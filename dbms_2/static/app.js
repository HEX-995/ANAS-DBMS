const userForm = document.getElementById("user-form");
const userIdInput = document.getElementById("user-id");
const nameInput = document.getElementById("name");
const emailInput = document.getElementById("email");
const phoneInput = document.getElementById("phone");
const imageInput = document.getElementById("image");
const previewImage = document.getElementById("preview-image");
const tableBody = document.getElementById("user-table");
const formTitle = document.getElementById("form-title");
const cancelBtn = document.getElementById("cancel-btn");
const messageNode = document.getElementById("message");

let currentImage = "";

function setMessage(text, error = false) {
  messageNode.textContent = text;
  messageNode.style.color = error ? "#a91d3a" : "#12664f";
}

function resetForm() {
  userIdInput.value = "";
  userForm.reset();
  currentImage = "";
  previewImage.hidden = true;
  formTitle.textContent = "Create User";
  cancelBtn.hidden = true;
}

function fillForm(user) {
  userIdInput.value = user.id;
  nameInput.value = user.name;
  emailInput.value = user.email;
  phoneInput.value = user.phone;
  currentImage = user.image || "";

  if (currentImage) {
    previewImage.src = currentImage;
    previewImage.hidden = false;
  } else {
    previewImage.hidden = true;
  }

  formTitle.textContent = `Edit User #${user.id}`;
  cancelBtn.hidden = false;
}

function fileToBase64(file) {
  return new Promise((resolve, reject) => {
    const reader = new FileReader();
    reader.onload = () => resolve(reader.result);
    reader.onerror = reject;
    reader.readAsDataURL(file);
  });
}

async function loadUsers() {
  const response = await fetch("/api/users");
  const users = await response.json();

  tableBody.innerHTML = "";

  if (!users.length) {
    tableBody.innerHTML = '<tr><td colspan="6">No data found.</td></tr>';
    return;
  }

  users.forEach((user) => {
    const tr = document.createElement("tr");
    const photo = user.image
      ? `<img src="${user.image}" class="user-photo" alt="photo" />`
      : "No photo";

    tr.innerHTML = `
      <td>${user.id}</td>
      <td>${photo}</td>
      <td>${user.name}</td>
      <td>${user.email}</td>
      <td>${user.phone}</td>
      <td>
        <div class="row-actions">
          <button class="small edit" data-action="edit" data-id="${user.id}">Edit</button>
          <button class="small delete" data-action="delete" data-id="${user.id}">Delete</button>
        </div>
      </td>
    `;

    tableBody.appendChild(tr);
  });
}

async function saveUser(event) {
  event.preventDefault();

  let image = currentImage;
  if (imageInput.files && imageInput.files[0]) {
    image = await fileToBase64(imageInput.files[0]);
  }

  const payload = {
    name: nameInput.value.trim(),
    email: emailInput.value.trim(),
    phone: phoneInput.value.trim(),
    image,
  };

  const id = userIdInput.value;
  const isEdit = Boolean(id);

  const response = await fetch(isEdit ? `/api/users/${id}` : "/api/users", {
    method: isEdit ? "PUT" : "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(payload),
  });

  const result = await response.json();

  if (!response.ok) {
    setMessage(result.error || "Failed request", true);
    return;
  }

  setMessage(isEdit ? "User updated" : "User created");
  resetForm();
  await loadUsers();
}

async function tableClick(event) {
  const button = event.target.closest("button[data-action]");
  if (!button) return;

  const action = button.dataset.action;
  const id = button.dataset.id;

  if (action === "edit") {
    const row = button.closest("tr");
    const img = row.querySelector("img");
    fillForm({
      id,
      name: row.children[2].textContent,
      email: row.children[3].textContent,
      phone: row.children[4].textContent,
      image: img ? img.src : "",
    });
    return;
  }

  if (action === "delete") {
    const ok = window.confirm("Delete this user?");
    if (!ok) return;

    const response = await fetch(`/api/users/${id}`, { method: "DELETE" });
    const result = await response.json();

    if (!response.ok) {
      setMessage(result.error || "Delete failed", true);
      return;
    }

    setMessage("User deleted");
    await loadUsers();
  }
}

imageInput.addEventListener("change", async (event) => {
  if (!event.target.files || !event.target.files[0]) {
    return;
  }

  const base64 = await fileToBase64(event.target.files[0]);
  previewImage.src = base64;
  previewImage.hidden = false;
});

userForm.addEventListener("submit", saveUser);
tableBody.addEventListener("click", tableClick);
cancelBtn.addEventListener("click", resetForm);
document.getElementById("refresh-btn").addEventListener("click", loadUsers);

loadUsers();
