const paymentForm = document.getElementById("paymentForm");
const transactionBody = document.getElementById("transactionBody");
const statusText = document.getElementById("status");
const qrImageInput = document.getElementById("qrImage");
const qrPreview = document.getElementById("qrPreview");

let transactionCount = 0;

function formatCardNumber(value) {
  return value
    .replace(/\D/g, "")
    .slice(0, 16)
    .replace(/(\d{4})(?=\d)/g, "$1 ")
    .trim();
}

function formatExpiry(value) {
  const digits = value.replace(/\D/g, "").slice(0, 4);
  if (digits.length < 3) return digits;
  return `${digits.slice(0, 2)}/${digits.slice(2)}`;
}

document.getElementById("cardNumber").addEventListener("input", (event) => {
  event.target.value = formatCardNumber(event.target.value);
});

document.getElementById("expiry").addEventListener("input", (event) => {
  event.target.value = formatExpiry(event.target.value);
});

qrImageInput.addEventListener("change", () => {
  const file = qrImageInput.files[0];

  if (!file) {
    qrPreview.removeAttribute("src");
    qrPreview.style.display = "none";
    return;
  }

  if (!file.type.startsWith("image/")) {
    statusText.className = "status error";
    statusText.textContent = "Please upload a valid image file for QR.";
    qrImageInput.value = "";
    qrPreview.removeAttribute("src");
    qrPreview.style.display = "none";
    return;
  }

  const reader = new FileReader();
  reader.onload = () => {
    qrPreview.src = reader.result;
    qrPreview.style.display = "block";
  };
  reader.readAsDataURL(file);
});

paymentForm.addEventListener("submit", (event) => {
  event.preventDefault();

  const fullName = document.getElementById("fullName").value.trim();
  const email = document.getElementById("email").value.trim();
  const amount = Number(document.getElementById("amount").value);
  const currency = document.getElementById("currency").value;
  const method = document.getElementById("method").value;
  const cardNumber = document
    .getElementById("cardNumber")
    .value.replace(/\s/g, "");
  const expiry = document.getElementById("expiry").value;
  const cvv = document.getElementById("cvv").value;

  statusText.className = "status";

  if (!fullName || !email || !amount || amount <= 0 || !currency || !method) {
    statusText.textContent = "Please fill all required fields correctly.";
    statusText.classList.add("error");
    return;
  }

  if (method === "Card") {
    if (
      cardNumber.length !== 16 ||
      !/^\d{2}\/\d{2}$/.test(expiry) ||
      cvv.length < 3
    ) {
      statusText.textContent = "Please enter valid card details.";
      statusText.classList.add("error");
      return;
    }
  }

  transactionCount += 1;
  const transactionId = `TXN${String(transactionCount).padStart(4, "0")}`;
  const now = new Date().toLocaleString();

  if (transactionCount === 1) {
    transactionBody.innerHTML = "";
  }

  const row = document.createElement("tr");
  row.innerHTML = `
    <td>${transactionId}</td>
    <td>${fullName}</td>
    <td>${currency} ${amount.toFixed(2)}</td>
    <td>${method}</td>
    <td><span class="badge success">Success</span></td>
    <td>${now}</td>
  `;

  transactionBody.prepend(row);

  const latestTransaction = {
    transactionId,
    fullName,
    email,
    amount: amount.toFixed(2),
    currency,
    method,
    now,
  };

  localStorage.setItem("latestTransaction", JSON.stringify(latestTransaction));
  window.location.href = "transaction.html";
});
