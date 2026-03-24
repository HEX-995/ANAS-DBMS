const express = require("express");
const path = require("path");
const sqlite3 = require("sqlite3").verbose();

const app = express();
const PORT = process.env.PORT || 5000;
const DB_PATH = path.join(__dirname, "app.db");

const db = new sqlite3.Database(DB_PATH, (err) => {
  if (err) {
    console.error("Failed to connect to SQLite:", err.message);
    process.exit(1);
  }
});

// Ensure table exists before handling requests.
db.serialize(() => {
  db.run(
    `
    CREATE TABLE IF NOT EXISTS users (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      name TEXT NOT NULL,
      email TEXT NOT NULL UNIQUE,
      phone TEXT NOT NULL,
      image TEXT
    )
    `,
  );
});

app.use(express.json({ limit: "50mb" }));
app.use(express.urlencoded({ limit: "50mb", extended: true }));
app.use("/static", express.static(path.join(__dirname, "static")));

app.get("/", (_req, res) => {
  res.sendFile(path.join(__dirname, "templates", "index.html"));
});

app.get("/api/users", (_req, res) => {
  db.all(
    "SELECT id, name, email, phone, image FROM users ORDER BY id DESC",
    [],
    (err, rows) => {
      if (err) {
        return res.status(500).json({ error: "failed to fetch users" });
      }
      return res.json(rows);
    },
  );
});

app.post("/api/users", (req, res) => {
  const name = String(req.body?.name || "").trim();
  const email = String(req.body?.email || "").trim();
  const phone = String(req.body?.phone || "").trim();
  const image = String(req.body?.image || "").trim();

  console.log("POST /api/users - Received:", {
    name,
    email,
    phone,
    hasImage: !!image,
  });

  if (!name || !email || !phone) {
    return res
      .status(400)
      .json({ error: "name, email, and phone are required" });
  }

  const sql =
    "INSERT INTO users (name, email, phone, image) VALUES (?, ?, ?, ?)";
  db.run(sql, [name, email, phone, image], function onInsert(err) {
    if (err) {
      console.error("Database error:", err.message);
      if (err.message.includes("UNIQUE")) {
        return res.status(409).json({ error: "email already exists" });
      }
      return res.status(500).json({ error: "failed to create user" });
    }

    console.log("User created with ID:", this.lastID);
    return res.status(201).json({
      id: this.lastID,
      name,
      email,
      phone,
      image,
    });
  });
});

app.put("/api/users/:id", (req, res) => {
  const userId = Number(req.params.id);
  const name = String(req.body?.name || "").trim();
  const email = String(req.body?.email || "").trim();
  const phone = String(req.body?.phone || "").trim();
  const image = String(req.body?.image || "").trim();

  console.log("PUT /api/users/:id - Received:", {
    userId,
    name,
    email,
    phone,
    hasImage: !!image,
  });

  if (!name || !email || !phone) {
    return res
      .status(400)
      .json({ error: "name, email, and phone are required" });
  }

  const sql =
    "UPDATE users SET name = ?, email = ?, phone = ?, image = ? WHERE id = ?";
  db.run(sql, [name, email, phone, image, userId], function onUpdate(err) {
    if (err) {
      console.error("Database error:", err.message);
      if (err.message.includes("UNIQUE")) {
        return res.status(409).json({ error: "email already exists" });
      }
      return res.status(500).json({ error: "failed to update user" });
    }

    if (this.changes === 0) {
      return res.status(404).json({ error: "user not found" });
    }

    console.log("User updated with ID:", userId);
    return res.json({ id: userId, name, email, phone, image });
  });
});

app.delete("/api/users/:id", (req, res) => {
  const userId = Number(req.params.id);
  db.run("DELETE FROM users WHERE id = ?", [userId], function onDelete(err) {
    if (err) {
      return res.status(500).json({ error: "failed to delete user" });
    }

    if (this.changes === 0) {
      return res.status(404).json({ error: "user not found" });
    }

    return res.json({ message: "user deleted" });
  });
});

app.listen(PORT, () => {
  console.log(`Server running at http://127.0.0.1:${PORT}`);
});
