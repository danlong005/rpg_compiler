-- Customer Order Thank-You Example
-- Run once to initialize the database:
--   sqlite3 /tmp/example.db < setup.sql

CREATE TABLE customers (
  id         INTEGER PRIMARY KEY,
  first_name VARCHAR(50)  NOT NULL,
  last_name  VARCHAR(50)  NOT NULL,
  email      VARCHAR(100) NOT NULL
);

INSERT INTO customers(id, first_name, last_name, email) VALUES
  (1, 'Alice', 'Smith', 'alice@example.com'),
  (2, 'Bob',   'Jones', 'bob@example.com'),
  (3, 'Carol', 'White', 'carol@example.com');

CREATE TABLE orders (
  id          INTEGER PRIMARY KEY,
  customer_id INTEGER NOT NULL,
  placed_at   DATE    NOT NULL,
  thanked     CHAR(1) NOT NULL DEFAULT 'N'
);

-- Two orders placed today, one from the past (should not be processed)
INSERT INTO orders(id, customer_id, placed_at, thanked) VALUES
  (1, 1, date('now'), 'N'),
  (2, 2, date('now'), 'N'),
  (3, 3, '2024-01-15', 'N');

CREATE TABLE messages (
  id          INTEGER PRIMARY KEY,
  customer_id INTEGER      NOT NULL,
  order_id    INTEGER      NOT NULL,
  message     VARCHAR(500) NOT NULL,
  email       VARCHAR(100) NOT NULL DEFAULT '',
  status      CHAR(1)      NOT NULL DEFAULT ' '
);
