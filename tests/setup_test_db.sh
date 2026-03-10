#!/bin/bash
# Create SQLite test database for SQL tests
DB="/tmp/rpgc_test_db.sqlite"
rm -f "$DB"

sqlite3 "$DB" << 'SQL'
CREATE TABLE employees (
  id INTEGER PRIMARY KEY,
  name VARCHAR(50),
  age INTEGER,
  salary DECIMAL(9,2)
);

INSERT INTO employees VALUES(1, 'Alice', 30, 75000.00);
INSERT INTO employees VALUES(2, 'Bob', 25, 65000.00);
INSERT INTO employees VALUES(3, 'Charlie', 35, 90000.00);
INSERT INTO employees VALUES(4, 'Diana', 28, 72000.00);
INSERT INTO employees VALUES(5, 'Eve', 32, 85000.00);
SQL

echo "Test database created: $DB"
