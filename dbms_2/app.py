import base64
import os
from pathlib import Path
import sqlite3

from flask import Flask, redirect, render_template_string, request, url_for

BASE_DIR = Path(__file__).resolve().parent
DB_PATH = BASE_DIR / "app.db"

app = Flask(__name__)

PAGE_HTML = """
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>PySnap CRUD</title>
    <style>
      :root {
        --bg: #f7f7f2;
        --ink: #1f2933;
        --accent: #ff7a59;
        --accent-2: #2a9d8f;
        --card: #ffffff;
        --line: #d9d9d0;
      }

      * { box-sizing: border-box; }

      body {
        margin: 0;
        font-family: Georgia, "Times New Roman", serif;
        color: var(--ink);
        background:
          radial-gradient(circle at 5% 5%, #ffd9cc 0, transparent 32%),
          radial-gradient(circle at 90% 95%, #cbf2ed 0, transparent 35%),
          var(--bg);
      }

      .shell {
        max-width: 1080px;
        margin: 28px auto;
        padding: 0 16px;
      }

      .hero {
        background: var(--card);
        border: 1px solid var(--line);
        border-left: 8px solid var(--accent);
        border-radius: 14px;
        padding: 18px;
        margin-bottom: 14px;
      }

      h1 {
        margin: 0;
        font-size: clamp(28px, 5vw, 46px);
      }

      .subtitle { margin: 8px 0 0; }

      .grid {
        display: grid;
        grid-template-columns: 340px 1fr;
        gap: 14px;
      }

      .card {
        background: var(--card);
        border: 1px solid var(--line);
        border-radius: 14px;
        padding: 16px;
      }

      label {
        display: block;
        margin: 10px 0 6px;
        font-weight: 700;
      }

      input {
        width: 100%;
        border: 1px solid #b8b8ae;
        border-radius: 10px;
        padding: 10px;
        font: inherit;
      }

      input[type="file"] { padding: 8px; }

      #preview-image {
        margin-top: 10px;
        width: 100%;
        max-height: 170px;
        object-fit: cover;
        border-radius: 10px;
        border: 1px solid #b8b8ae;
      }

      .actions,
      .list-head {
        display: flex;
        gap: 8px;
        align-items: center;
        justify-content: space-between;
        margin-top: 12px;
      }

      .btn {
        border: 0;
        border-radius: 999px;
        padding: 9px 12px;
        cursor: pointer;
        font-weight: 700;
        text-decoration: none;
        display: inline-block;
      }

      .btn.primary { background: var(--accent); color: #fff; }
      .btn.ghost { background: #ecece4; color: var(--ink); }
      .btn.edit { background: #dff2ef; color: var(--ink); }
      .btn.delete { background: #ffd9d1; color: var(--ink); }

      .message {
        min-height: 20px;
        font-weight: 700;
        margin-top: 8px;
      }

      .ok { color: #12664f; }
      .error { color: #b42318; }

      .table-wrap { overflow-x: auto; margin-top: 12px; }

      table {
        width: 100%;
        border-collapse: collapse;
        min-width: 660px;
      }

      th, td {
        border-bottom: 1px solid var(--line);
        text-align: left;
        padding: 9px 8px;
      }

      .thumb {
        width: 44px;
        height: 44px;
        border-radius: 50%;
        object-fit: cover;
        border: 1px solid #999;
      }

      .row-actions {
        display: flex;
        gap: 8px;
        align-items: center;
      }

      .inline-form {
        margin: 0;
      }

      @media (max-width: 900px) {
        .grid { grid-template-columns: 1fr; }
      }
    </style>
  </head>
  <body>
    <main class="shell">
      <section class="hero">
        <h1>PySnap User Desk</h1>
        <p class="subtitle">Pure Python Flask interface (no JavaScript).</p>
      </section>

      <section class="grid">
        <article class="card">
          <h2>{{ "Edit User #" ~ edit_user.id if edit_user else "Create User" }}</h2>

          <form method="post" enctype="multipart/form-data" action="{{ url_for('update_user', user_id=edit_user.id) if edit_user else url_for('create_user') }}">
            <label for="name">Name</label>
            <input id="name" name="name" type="text" required value="{{ edit_user.name if edit_user else '' }}" />

            <label for="email">Email</label>
            <input id="email" name="email" type="email" required value="{{ edit_user.email if edit_user else '' }}" />

            <label for="phone">Phone</label>
            <input id="phone" name="phone" type="text" required value="{{ edit_user.phone if edit_user else '' }}" />

            <label for="image">Image</label>
            <input id="image" name="image" type="file" accept="image/*" />
            <input name="existing_image" type="hidden" value="{{ edit_user.image if edit_user else '' }}" />

            {% if edit_user and edit_user.image %}
              <img id="preview-image" src="{{ edit_user.image }}" alt="preview" />
            {% endif %}

            <div class="actions">
              <button class="btn primary" type="submit">{{ "Update" if edit_user else "Save" }}</button>
              {% if edit_user %}
                <a class="btn ghost" href="{{ url_for('index') }}">Cancel</a>
              {% endif %}
            </div>
          </form>

          {% if message %}
            <p class="message ok">{{ message }}</p>
          {% endif %}
          {% if error %}
            <p class="message error">{{ error }}</p>
          {% endif %}
        </article>

        <article class="card">
          <div class="list-head">
            <h2>Users</h2>
            <a class="btn ghost" href="{{ url_for('index') }}">Refresh</a>
          </div>

          <div class="table-wrap">
            <table>
              <thead>
                <tr>
                  <th>ID</th>
                  <th>Image</th>
                  <th>Name</th>
                  <th>Email</th>
                  <th>Phone</th>
                  <th>Actions</th>
                </tr>
              </thead>
              <tbody>
                {% if users %}
                  {% for user in users %}
                    <tr>
                      <td>{{ user.id }}</td>
                      <td>
                        {% if user.image %}
                          <img src="{{ user.image }}" class="thumb" alt="user" />
                        {% else %}
                          No image
                        {% endif %}
                      </td>
                      <td>{{ user.name }}</td>
                      <td>{{ user.email }}</td>
                      <td>{{ user.phone }}</td>
                      <td>
                        <div class="row-actions">
                          <a class="btn edit" href="{{ url_for('index', edit=user.id) }}">Edit</a>
                          <form class="inline-form" method="post" action="{{ url_for('delete_user', user_id=user.id) }}">
                            <button class="btn delete" type="submit">Delete</button>
                          </form>
                        </div>
                      </td>
                    </tr>
                  {% endfor %}
                {% else %}
                  <tr>
                    <td colspan="6">No users found.</td>
                  </tr>
                {% endif %}
              </tbody>
            </table>
          </div>
        </article>
      </section>
    </main>
  </body>
</html>
"""


def get_connection() -> sqlite3.Connection:
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    return conn


def init_db() -> None:
    conn = get_connection()
    conn.execute(
        """
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE,
            phone TEXT NOT NULL,
            image TEXT
        )
        """
    )
    conn.commit()
    conn.close()


def image_to_data_uri(upload) -> str:
    if not upload or not upload.filename:
        return ""

    raw = upload.read()
    if not raw:
        return ""

    mime = upload.mimetype or "image/png"
    encoded = base64.b64encode(raw).decode("ascii")
    return f"data:{mime};base64,{encoded}"


def fetch_users():
    conn = get_connection()
    rows = conn.execute(
        "SELECT id, name, email, phone, image FROM users ORDER BY id DESC"
    ).fetchall()
    conn.close()
    return rows


@app.get("/")
def index():
    edit_id = request.args.get("edit")
    message = request.args.get("message", "")
    error = request.args.get("error", "")

    users = fetch_users()
    edit_user = None
    if edit_id:
        for user in users:
            if str(user["id"]) == edit_id:
                edit_user = user
                break

    return render_template_string(
        PAGE_HTML,
        users=users,
        edit_user=edit_user,
        message=message,
        error=error,
    )


@app.post("/create")
def create_user():
    name = str(request.form.get("name", "")).strip()
    email = str(request.form.get("email", "")).strip()
    phone = str(request.form.get("phone", "")).strip()
    image = image_to_data_uri(request.files.get("image"))

    if not name or not email or not phone:
        return redirect(url_for("index", error="name, email, and phone are required"))

    try:
        conn = get_connection()
        conn.execute(
            "INSERT INTO users (name, email, phone, image) VALUES (?, ?, ?, ?)",
            (name, email, phone, image),
        )
        conn.commit()
        conn.close()
    except sqlite3.IntegrityError:
        return redirect(url_for("index", error="email already exists"))

    return redirect(url_for("index", message="User created"))


@app.post("/update/<int:user_id>")
def update_user(user_id: int):
    name = str(request.form.get("name", "")).strip()
    email = str(request.form.get("email", "")).strip()
    phone = str(request.form.get("phone", "")).strip()
    existing_image = str(request.form.get("existing_image", "")).strip()
    new_image = image_to_data_uri(request.files.get("image"))
    image = new_image or existing_image

    if not name or not email or not phone:
        return redirect(
            url_for(
                "index",
                edit=user_id,
                error="name, email, and phone are required",
            )
        )

    conn = get_connection()
    exists = conn.execute("SELECT id FROM users WHERE id = ?", (user_id,)).fetchone()
    if not exists:
        conn.close()
        return redirect(url_for("index", error="user not found"))

    try:
        conn.execute(
            "UPDATE users SET name = ?, email = ?, phone = ?, image = ? WHERE id = ?",
            (name, email, phone, image, user_id),
        )
        conn.commit()
    except sqlite3.IntegrityError:
        conn.close()
        return redirect(url_for("index", edit=user_id, error="email already exists"))

    conn.close()
    return redirect(url_for("index", message="User updated"))


@app.post("/delete/<int:user_id>")
def delete_user(user_id: int):
    conn = get_connection()
    cursor = conn.execute("DELETE FROM users WHERE id = ?", (user_id,))
    conn.commit()
    conn.close()

    if cursor.rowcount == 0:
        return redirect(url_for("index", error="user not found"))

    return redirect(url_for("index", message="User deleted"))


if __name__ == "__main__":
    init_db()
    app.run(debug=True, port=int(os.getenv("PORT", "5000")))
