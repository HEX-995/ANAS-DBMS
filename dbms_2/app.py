from pathlib import Path
import os
import sqlite3

from flask import Flask, jsonify, render_template, request

BASE_DIR = Path(__file__).resolve().parent
DB_PATH = BASE_DIR / "app.db"

app = Flask(__name__)


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

    columns = {
        row["name"] for row in conn.execute("PRAGMA table_info(users)").fetchall()
    }
    if "image" not in columns:
        conn.execute("ALTER TABLE users ADD COLUMN image TEXT")

    conn.commit()
    conn.close()


@app.get("/")
def index():
    return render_template("index.html")


@app.get("/api/users")
def list_users():
    conn = get_connection()
    rows = conn.execute(
        "SELECT id, name, email, phone, image FROM users ORDER BY id DESC"
    ).fetchall()
    conn.close()
    return jsonify([dict(row) for row in rows])


@app.post("/api/users")
def create_user():
    data = request.get_json(silent=True) or {}
    name = str(data.get("name", "")).strip()
    email = str(data.get("email", "")).strip()
    phone = str(data.get("phone", "")).strip()
    image = str(data.get("image", "")).strip()

    if not name or not email or not phone:
        return jsonify({"error": "name, email, and phone are required"}), 400

    try:
        conn = get_connection()
        cursor = conn.execute(
            "INSERT INTO users (name, email, phone, image) VALUES (?, ?, ?, ?)",
            (name, email, phone, image),
        )
        conn.commit()
        user_id = cursor.lastrowid
        conn.close()
    except sqlite3.IntegrityError:
        return jsonify({"error": "email already exists"}), 409

    return (
        jsonify({
            "id": user_id,
            "name": name,
            "email": email,
            "phone": phone,
            "image": image,
        }),
        201,
    )


@app.put("/api/users/<int:user_id>")
def update_user(user_id: int):
    data = request.get_json(silent=True) or {}
    name = str(data.get("name", "")).strip()
    email = str(data.get("email", "")).strip()
    phone = str(data.get("phone", "")).strip()
    image = str(data.get("image", "")).strip()

    if not name or not email or not phone:
        return jsonify({"error": "name, email, and phone are required"}), 400

    conn = get_connection()
    exists = conn.execute("SELECT id FROM users WHERE id = ?", (user_id,)).fetchone()
    if not exists:
        conn.close()
        return jsonify({"error": "user not found"}), 404

    try:
        conn.execute(
            "UPDATE users SET name = ?, email = ?, phone = ?, image = ? WHERE id = ?",
            (name, email, phone, image, user_id),
        )
        conn.commit()
    except sqlite3.IntegrityError:
        conn.close()
        return jsonify({"error": "email already exists"}), 409

    conn.close()
    return jsonify(
        {
            "id": user_id,
            "name": name,
            "email": email,
            "phone": phone,
            "image": image,
        }
    )


@app.delete("/api/users/<int:user_id>")
def delete_user(user_id: int):
    conn = get_connection()
    cursor = conn.execute("DELETE FROM users WHERE id = ?", (user_id,))
    conn.commit()
    conn.close()

    if cursor.rowcount == 0:
        return jsonify({"error": "user not found"}), 404

    return jsonify({"message": "user deleted"})


if __name__ == "__main__":
    init_db()
    app.run(debug=True, port=int(os.getenv("PORT", "5000")))
