const userForm = document.getElementById("user-form");
const userIdInput = document.getElementById("user-id");
const nameInput = document.getElementById("name");
const emailInput = document.getElementById("email");
const phoneInput = document.getElementById("phone");
const imageInput = document.getElementById("image");
const previewImage = document.getElementById("preview-image");
const tableBody = document.getElementById("user-table");
const message = document.getElementById("message");
const formTitle = document.getElementById("form-title");
const cancelBtn = document.getElementById("cancel-btn");
let currentImageData = "";

function setMessage(text, isError = false) {
  message.textContent = text;
  message.style.color = isError ? "#b42318" : "#0f5132";
}

function resetForm() {
  userIdInput.value = "";
  userForm.reset();
  formTitle.textContent = "Add User";
  cancelBtn.hidden = true;
  previewImage.style.display = "none";
  currentImageData = "";
}

function fillForm(user) {
  userIdInput.value = user.id;
  nameInput.value = user.name;
  emailInput.value = user.email;
  phoneInput.value = user.phone;

  if (user.image) {
    previewImage.src = user.image;
    previewImage.style.display = "block";
    currentImageData = user.image;
  } else {
    previewImage.style.display = "none";
    currentImageData = "";
  }
  formTitle.textContent = `Edit User #${user.id}`;
  cancelBtn.hidden = false;
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
    const row = document.createElement("tr");
    const imageTd = user.image
      ? `<img src="${user.image}" style="width: 50px; height: 50px; object-fit: cover; border-radius: 4px;" />`
      : "No image";
    row.innerHTML = `
      <td>${user.id}</td>
      <td>${imageTd}</td>
      <td>${user.name}</td>
      <td>${user.email}</td>
      <td>${user.phone}</td>
      <td>
        <button class="tiny" data-action="edit" data-id="${user.id}">Edit</button>
        <button class="tiny danger" data-action="delete" data-id="${user.id}">Delete</button>
      </td>
    `;
    tableBody.appendChild(row);
  });
}

async function saveUser(event) {
  event.preventDefault();

  let imageData = currentImageData;

  if (imageInput.files && imageInput.files[0]) {
    try {
      imageData = await fileToBase64(imageInput.files[0]);
    } catch (error) {
      setMessage("Error reading image file: " + error.message, true);
      return;
    }
  }

  const payload = {
    name: nameInput.value.trim(),
    email: emailInput.value.trim(),
    phone: phoneInput.value.trim(),
    image: imageData,
  };

  const id = userIdInput.value;
  const isEdit = Boolean(id);

  const url = isEdit ? `/api/users/${id}` : "/api/users";
  const method = isEdit ? "PUT" : "POST";

  console.log("Sending request:", { url, method, payload });

  try {
    const response = await fetch(url, {
      method,
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(payload),
    });

    const result = await response.json();

    console.log("Response:", { status: response.status, result });

    if (!response.ok) {
      setMessage(result.error || "Request failed", true);
      return;
    }

    setMessage(
      isEdit ? "User updated successfully" : "User added successfully",
    );
    resetForm();
    await loadUsers();
  } catch (error) {
    console.error("Error:", error);
    setMessage("Error: " + error.message, true);
  }
}

async function handleTableClick(event) {
  const button = event.target.closest("button[data-action]");
  if (!button) return;

  const id = button.dataset.id;
  const action = button.dataset.action;

  if (action === "edit") {
    const row = button.closest("tr");
    const imageCell = row.querySelector("img");
    fillForm({
      id,
      name: row.children[2].textContent,
      email: row.children[3].textContent,
      phone: row.children[4].textContent,
      image: imageCell ? imageCell.src : "",
    });
    return;
  }

  if (action === "delete") {
    const confirmed = window.confirm("Delete this user?");
    if (!confirmed) return;

    const response = await fetch(`/api/users/${id}`, {
      method: "DELETE",
    });
    const result = await response.json();

    if (!response.ok) {
      setMessage(result.error || "Delete failed", true);
      return;
    }

    setMessage("User deleted successfully");
    await loadUsers();
  }
}

userForm.addEventListener("submit", saveUser);
tableBody.addEventListener("click", handleTableClick);
cancelBtn.addEventListener("click", resetForm);
document.getElementById("refresh-btn").addEventListener("click", loadUsers);

imageInput.addEventListener("change", async (e) => {
  if (e.target.files && e.target.files[0]) {
    previewImage.src = await fileToBase64(e.target.files[0]);
    previewImage.style.display = "block";
  }
});

function fileToBase64(file) {
  return new Promise((resolve, reject) => {
    const reader = new FileReader();
    reader.onload = () => resolve(reader.result);
    reader.onerror = reject;
    reader.readAsDataURL(file);
  });
}

loadUsers();
