# rpgc User's Guide

`rpgc` transpiles IBM RPG IV free-format source code into portable C++17 and optionally compiles it to a native executable. Programs can run on macOS, Linux, or any platform with a C++ compiler — no IBM i required.

---

## Table of Contents

1. [Installation](#installation)
2. [Quick Start](#quick-start)
3. [CLI Reference](#cli-reference)
4. [Language Basics](#language-basics)
5. [Data Types](#data-types)
6. [Variables and Constants](#variables-and-constants)
7. [Data Structures](#data-structures)
8. [Arrays](#arrays)
9. [Control Flow](#control-flow)
10. [Procedures](#procedures)
11. [Built-In Functions](#built-in-functions)
12. [Error Handling](#error-handling)
13. [Embedded SQL](#embedded-sql)
14. [Database Connections](#database-connections)
15. [Multi-Module Programs](#multi-module-programs)
16. [Environment Variables](#environment-variables)
17. [Testing](#testing)

---

## Installation

### Prerequisites

- **C++17 compiler** (clang++ or g++)
- **Flex** (lexer generator)
- **Bison** (parser generator)
- **unixODBC + database driver** (only if using embedded SQL)

### macOS (Homebrew)

```bash
brew install flex bison

# For embedded SQL support:
brew install unixodbc
# Plus a database driver (see Database Connections section)
```

### Linux (Debian/Ubuntu)

```bash
sudo apt install flex bison g++

# For embedded SQL support:
sudo apt install unixodbc-dev
# Plus a database driver (see Database Connections section)
```

### Windows (MSYS2/MinGW)

1. Install [MSYS2](https://www.msys2.org/) and open the **MINGW64** shell.

```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-flex mingw-w64-x86_64-bison make
```

Windows has a built-in ODBC driver manager, so `unixODBC` is not needed. Database ODBC drivers are installed via MSI installers and configured through the **ODBC Data Source Administrator** (search "ODBC" in the Start menu). See [Database Connections](#database-connections) for driver-specific setup.

> **Note:** You can also build with Visual Studio using [winflexbison](https://github.com/nicehash/winflexbison). Install via `choco install winflexbison` or download from the GitHub releases page. You'll need to adjust the `FLEX` and `BISON` paths in the Makefile or create a CMake/MSBuild project.

### Build

**macOS / Linux:**
```bash
git clone <repo-url>
cd rpg_compiler
make
```

**Windows (MSYS2 MINGW64 shell):**
```bash
git clone <repo-url>
cd rpg_compiler
make
```

This produces the `rpgc` executable.

### Install (optional)

To install `rpgc` system-wide:

```bash
sudo make install              # installs to /usr/local/bin
make install PREFIX=~/.local   # or install to ~/.local/bin (no sudo needed)
```

This installs:
- `rpgc` binary to `$PREFIX/bin/`
- Runtime headers to `$PREFIX/share/rpgc/runtime/`

When compiling RPG programs, `rpgc` automatically finds the runtime headers — it checks relative to the binary, the current directory, and the install prefix.

To uninstall:
```bash
sudo make uninstall
```

---

## Quick Start

**hello.rpgle:**
```rpgle
**FREE
DCL-S msg VARCHAR(50);
msg = 'Hello from RPG!';
DSPLY msg;
RETURN;
```

```bash
./rpgc hello.rpgle
./hello
# Output: Hello from RPG!
```

---

## CLI Reference

```
rpgc <source-file> [options]
```

| Flag | Description |
|------|-------------|
| `-o file` | Output file (executable by default, or C++ file with `-S`) |
| `-S` | Emit C++ source only, do not compile |
| `--keep-cpp` | Keep the intermediate `.cpp` file after compiling |

### File Extensions

| Extension | Description |
|-----------|-------------|
| `.rpgle` | Standard RPG IV source |
| `.sqlrpgle` | RPG IV with embedded SQL (automatically links ODBC) |

When the input file has a `.sqlrpgle` extension, `rpgc` automatically adds ODBC include paths and linker flags during compilation.

### Examples

```bash
# Compile to executable (default)
./rpgc program.rpgle              # produces ./program
./rpgc program.rpgle -o myapp     # produces ./myapp

# Emit C++ source only
./rpgc program.rpgle -S           # produces ./program.cpp
./rpgc program.rpgle -S -o out.cpp

# Keep intermediate C++ file
./rpgc program.rpgle --keep-cpp   # produces ./program and ./program.cpp

# SQL program (auto-links ODBC)
./rpgc report.sqlrpgle            # produces ./report (linked with -lodbc)
```

---

## Language Basics

All programs begin with `**FREE` to indicate free-format RPG IV:

```rpgle
**FREE

// Declarations go here
DCL-S name VARCHAR(50);

// Executable statements
name = 'World';
DSPLY 'Hello, ' + %TRIM(name) + '!';

*INLR = *ON;
RETURN;
```

### Comments

```rpgle
// Single-line comment
```

### Statement Terminator

Statements end with a semicolon (`;`).

---

## Data Types

| RPG Type | Example | Description |
|----------|---------|-------------|
| `CHAR(n)` | `DCL-S x CHAR(10);` | Fixed-length string |
| `VARCHAR(n)` | `DCL-S x VARCHAR(50);` | Variable-length string |
| `INT(10)` | `DCL-S x INT(10);` | 32-bit integer |
| `INT(20)` | `DCL-S x INT(20);` | 64-bit integer |
| `UNS(10)` | `DCL-S x UNS(10);` | Unsigned 32-bit integer |
| `PACKED(n:d)` | `DCL-S x PACKED(9:2);` | Packed decimal (stored as double) |
| `ZONED(n:d)` | `DCL-S x ZONED(9:2);` | Zoned decimal (stored as double) |
| `FLOAT(4)` | `DCL-S x FLOAT(4);` | Single-precision float |
| `FLOAT(8)` | `DCL-S x FLOAT(8);` | Double-precision float |
| `IND` | `DCL-S x IND;` | Boolean indicator |
| `DATE` | `DCL-S x DATE;` | Date value |
| `TIME` | `DCL-S x TIME;` | Time value |
| `TIMESTAMP` | `DCL-S x TIMESTAMP;` | Timestamp value |
| `POINTER` | `DCL-S x POINTER;` | Memory pointer |
| `BOOLEAN` | `DCL-S x BOOLEAN;` | Boolean (true/false) |

---

## Variables and Constants

### Variables

```rpgle
DCL-S counter INT(10);
DCL-S name VARCHAR(50) INZ('Default');
DCL-S rate PACKED(7:2) INZ(15.50);
DCL-S isActive IND INZ(*ON);
```

### Named Constants

```rpgle
DCL-C MAX_SIZE 100;
DCL-C GREETING 'Hello';
DCL-C PI 3.14159;
```

### Figurative Constants

| Constant | Description |
|----------|-------------|
| `*BLANKS` | Empty string / spaces |
| `*ZEROS` | Numeric zero or string of zeros |
| `*HIVAL` | Maximum value for the type |
| `*LOVAL` | Minimum value for the type |
| `*ON` | Boolean true / '1' |
| `*OFF` | Boolean false / '0' |
| `*NULL` | Null pointer |
| `*ALL'x'` | Repeated character pattern |

---

## Data Structures

### Basic Data Structure

```rpgle
DCL-DS employee QUALIFIED;
  id INT(10);
  name VARCHAR(50);
  salary PACKED(9:2);
END-DS;

employee.id = 1;
employee.name = 'Alice';
employee.salary = 75000.00;
DSPLY employee.name;
```

### Array of Data Structures

```rpgle
DCL-DS item QUALIFIED DIM(10);
  code CHAR(5);
  description VARCHAR(50);
  price PACKED(7:2);
END-DS;

item(1).code = 'A001';
item(1).description = 'Widget';
item(1).price = 9.99;
```

### LIKEDS

```rpgle
DCL-DS address QUALIFIED;
  street VARCHAR(100);
  city VARCHAR(50);
  state CHAR(2);
END-DS;

DCL-DS shipping LIKEDS(address);
shipping.city = 'Springfield';
```

---

## Arrays

Arrays in RPG are **1-based** (the first element is index 1).

```rpgle
// Fixed-size array
DCL-S names VARCHAR(50) DIM(5);
names(1) = 'Alice';
names(2) = 'Bob';
DSPLY names(1);  // Alice

// Variable-size array
DCL-S items VARCHAR(50) DIM(*VAR: 100);
%ELEM(items) = 3;
items(1) = 'First';

// Array initialization
DCL-S scores INT(10) DIM(3) INZ(0);
```

### Array Operations

```rpgle
DCL-S names VARCHAR(20) DIM(5);
DCL-S idx INT(10);

names(1) = 'Charlie';
names(2) = 'Alice';
names(3) = 'Bob';

SORTA names;  // Sort ascending

idx = %LOOKUP('Bob' : names);
DSPLY %CHAR(idx);  // Position of 'Bob' after sort

// FOR-EACH loop
FOR-EACH name IN names;
  IF name <> '';
    DSPLY name;
  ENDIF;
ENDFOR;
```

---

## Control Flow

### IF / ELSEIF / ELSE

```rpgle
IF score >= 90;
  grade = 'A';
ELSEIF score >= 80;
  grade = 'B';
ELSE;
  grade = 'C';
ENDIF;
```

### SELECT / WHEN / OTHER

```rpgle
SELECT;
  WHEN status = 'A';
    DSPLY 'Active';
  WHEN status = 'I';
    DSPLY 'Inactive';
  OTHER;
    DSPLY 'Unknown';
ENDSL;
```

### DOW (Do While) / DOU (Do Until)

```rpgle
// Do while count < 10
DOW count < 10;
  count += 1;
ENDDO;

// Do until found
DOU %FOUND;
  // search logic
ENDDO;
```

### FOR Loop

```rpgle
FOR i = 1 TO 10;
  DSPLY %CHAR(i);
ENDFOR;

FOR i = 10 DOWNTO 1 BY 2;
  DSPLY %CHAR(i);
ENDFOR;
```

---

## Procedures

### Defining and Calling Procedures

```rpgle
**FREE

// Forward declaration (prototype)
DCL-PR Add INT(10);
  a INT(10) VALUE;
  b INT(10) VALUE;
END-PR;

// Call it
DCL-S result INT(10);
result = Add(3 : 5);
DSPLY %CHAR(result);  // 8

RETURN;

// Implementation
DCL-PROC Add;
  DCL-PI INT(10);
    a INT(10) VALUE;
    b INT(10) VALUE;
  END-PI;

  RETURN a + b;
END-PROC;
```

### Optional Parameters

```rpgle
DCL-PROC Greet;
  DCL-PI VARCHAR(100);
    name VARCHAR(50) VALUE;
    title VARCHAR(20) VALUE OPTIONS(*NOPASS);
  END-PI;

  IF %PARMS >= 2;
    RETURN 'Hello, ' + title + ' ' + name;
  ELSE;
    RETURN 'Hello, ' + name;
  ENDIF;
END-PROC;
```

---

## Built-In Functions

### String Functions

```rpgle
DCL-S s VARCHAR(100);

s = '  Hello World  ';
DSPLY %TRIM(s);         // 'Hello World'
DSPLY %LEN(s);          // 15
DSPLY %SUBST(s:3:5);    // 'Hello'
DSPLY %SCAN('World':s); // 9
DSPLY %REPLACE('RPG':'Hello World':1:5);  // 'RPG World'
DSPLY %LOWER('HELLO');  // 'hello'
DSPLY %UPPER('hello');  // 'HELLO'
```

### Numeric Functions

```rpgle
DSPLY %CHAR(%ABS(-42));     // 42
DSPLY %CHAR(%INT(3.7));     // 3
DSPLY %CHAR(%DEC(3.7:5:2)); // 3.70
DSPLY %CHAR(%REM(17:5));    // 2
DSPLY %CHAR(%SQRT(144));    // 12
```

### Date/Time Functions

```rpgle
DCL-S today DATE INZ(%DATE);
DCL-S now TIME INZ(%TIME);
DCL-S ts TIMESTAMP INZ(%TIMESTAMP);
DCL-S future DATE;

future = today + %DAYS(30);
DSPLY %CHAR(future);

DCL-S daysBetween INT(10);
daysBetween = %DIFF(future : today : *DAYS);
DSPLY %CHAR(daysBetween);  // 30
```

---

## Error Handling

### MONITOR / ON-ERROR

```rpgle
MONITOR;
  result = numerator / denominator;
ON-ERROR;
  DSPLY 'Division error!';
  result = 0;
ENDMON;
```

### *PSSR (Program Status Subroutine)

```rpgle
BEGSR *PSSR;
  DSPLY 'Unhandled error: ' + %CHAR(%STATUS);
ENDSR;
```

### ON-EXIT

```rpgle
DCL-PROC ProcessData;
  DCL-PI;
  END-PI;
  DCL-S abnormal IND;

  // ... processing ...

  ON-EXIT abnormal;
    IF abnormal;
      DSPLY 'Procedure ended abnormally';
    ENDIF;
    // cleanup code always runs
END-PROC;
```

---

## Embedded SQL

Programs using embedded SQL should use the `.sqlrpgle` file extension. This tells `rpgc` to automatically link the ODBC library.

### Basic SQL Operations

```rpgle
**FREE

DCL-S connStr VARCHAR(200);
DCL-S empName VARCHAR(50);
DCL-S empId   INT(10);

// Connect to database
connStr = 'Driver={SQLite3};Database=myapp.sqlite;';
EXEC SQL CONNECT USING :connStr;

// Create a table
EXEC SQL CREATE TABLE employees (
  id INTEGER PRIMARY KEY,
  name VARCHAR(50),
  salary DECIMAL(9,2)
);

// Insert data using host variables
empId = 1;
empName = 'Alice';
EXEC SQL INSERT INTO employees (id, name, salary)
  VALUES(:empId, :empName, 75000.00);

// Query data
EXEC SQL SELECT name INTO :empName
  FROM employees WHERE id = :empId;
DSPLY empName;

// Check SQLCODE after operations
IF SQLCOD <> 0;
  DSPLY 'SQL error: ' + %CHAR(SQLCOD);
ENDIF;

// Clean up
EXEC SQL DROP TABLE employees;
EXEC SQL DISCONNECT;

*INLR = *ON;
RETURN;
```

### Cursors

Use cursors to iterate over result sets:

```rpgle
**FREE

DCL-S connStr VARCHAR(200);
DCL-S name    VARCHAR(50);
DCL-S salary  PACKED(9:2);

connStr = 'Driver={SQLite3};Database=myapp.sqlite;';
EXEC SQL CONNECT USING :connStr;

// Declare a cursor
EXEC SQL DECLARE empCur CURSOR FOR
  SELECT name, salary FROM employees
  ORDER BY name;

// Open and fetch in a loop
EXEC SQL OPEN empCur;

EXEC SQL FETCH empCur INTO :name, :salary;
DOW SQLCOD = 0;
  DSPLY name + ': ' + %CHAR(salary);
  EXEC SQL FETCH empCur INTO :name, :salary;
ENDDO;

EXEC SQL CLOSE empCur;
EXEC SQL DISCONNECT;
```

### Cursors with Data Structures

You can fetch directly into a qualified data structure:

```rpgle
DCL-DS emp QUALIFIED;
  id   INT(10);
  name VARCHAR(50);
  salary PACKED(9:2);
END-DS;

EXEC SQL DECLARE c1 CURSOR FOR
  SELECT id, name, salary FROM employees ORDER BY id;

EXEC SQL OPEN c1;

EXEC SQL FETCH NEXT FROM c1 INTO :emp;
DOW SQLSTATE < '02000';
  DSPLY %CHAR(emp.id) + ' ' + %TRIM(emp.name);
  EXEC SQL FETCH NEXT FROM c1 INTO :emp;
ENDDO;

EXEC SQL CLOSE c1;
```

### Parameterized Cursors

Host variables in the WHERE clause are bound when the cursor is opened:

```rpgle
DCL-S minSalary PACKED(9:2);

EXEC SQL DECLARE salCur CURSOR FOR
  SELECT name, salary FROM employees
  WHERE salary > :minSalary;

minSalary = 70000.00;
EXEC SQL OPEN salCur;

EXEC SQL FETCH salCur INTO :name, :salary;
DOW SQLCOD = 0;
  DSPLY name;
  EXEC SQL FETCH salCur INTO :name, :salary;
ENDDO;

EXEC SQL CLOSE salCur;
```

### Dynamic SQL

```rpgle
DCL-S sqlStr VARCHAR(256);
DCL-S id     INT(10);
DCL-S name   VARCHAR(50);

// Execute Immediate — for DDL or one-off statements
sqlStr = 'CREATE TABLE temp (id INTEGER, name TEXT)';
EXEC SQL EXECUTE IMMEDIATE :sqlStr;

// Prepare + Execute — for repeated statements with parameters
sqlStr = 'INSERT INTO temp VALUES(?, ?)';
EXEC SQL PREPARE ins1 FROM :sqlStr;

id = 1;
name = 'Alice';
EXEC SQL EXECUTE ins1 USING :id, :name;

id = 2;
name = 'Bob';
EXEC SQL EXECUTE ins1 USING :id, :name;
```

### Multi-Row Operations

```rpgle
DCL-S ids      INT(10) DIM(10);
DCL-S names    VARCHAR(50) DIM(10);
DCL-S nRows    INT(10);

// Multi-row insert from arrays
ids(1) = 1;  names(1) = 'Alice';
ids(2) = 2;  names(2) = 'Bob';
ids(3) = 3;  names(3) = 'Charlie';

nRows = 3;
EXEC SQL INSERT INTO employees (id, name)
  VALUES(:ids, :names)
  FOR :nRows ROWS;

// Multi-row fetch into arrays
EXEC SQL DECLARE c1 CURSOR FOR
  SELECT id, name FROM employees ORDER BY id;
EXEC SQL OPEN c1;

nRows = 10;
EXEC SQL FETCH c1 FOR :nRows ROWS
  INTO :ids, :names;

EXEC SQL CLOSE c1;
```

### Transaction Control

```rpgle
EXEC SQL INSERT INTO accounts (id, balance) VALUES(1, 1000.00);
EXEC SQL INSERT INTO accounts (id, balance) VALUES(2, 500.00);

// Savepoint for partial rollback
EXEC SQL SAVEPOINT before_transfer;

EXEC SQL UPDATE accounts SET balance = balance - 200 WHERE id = 1;
EXEC SQL UPDATE accounts SET balance = balance + 200 WHERE id = 2;

// Something went wrong? Rollback to savepoint
EXEC SQL ROLLBACK TO SAVEPOINT before_transfer;

// Or commit everything
EXEC SQL COMMIT;
```

### GET DIAGNOSTICS

```rpgle
DCL-S rowCount INT(10);

EXEC SQL UPDATE employees SET salary = salary * 1.1
  WHERE department = 'ENG';

EXEC SQL GET DIAGNOSTICS :rowCount = ROW_COUNT;
DSPLY 'Updated ' + %CHAR(rowCount) + ' employees';
```

### SQLCODE and SQLSTATE

After each SQL statement, you can check:

| Variable | Description |
|----------|-------------|
| `SQLCOD` | Numeric return code (0 = success, 100 = not found, negative = error) |
| `SQLSTT` | 5-character SQLSTATE code ('00000' = success, '02000' = not found) |

```rpgle
EXEC SQL SELECT name INTO :empName FROM employees WHERE id = 999;

IF SQLCOD = 100;
  DSPLY 'Employee not found';
ELSEIF SQLCOD < 0;
  DSPLY 'SQL error: ' + %CHAR(SQLCOD);
ENDIF;
```

---

## Database Connections

`rpgc` uses ODBC for database access, making it portable across databases. You connect using a connection string with `EXEC SQL CONNECT USING`.

### Prerequisites

**macOS / Linux:**
1. Install **unixODBC** (the driver manager)
2. Install a **database-specific ODBC driver**
3. Register the driver in `/etc/odbcinst.ini` or (on macOS with Homebrew) `/opt/homebrew/etc/odbcinst.ini`

**Windows:**
1. ODBC driver manager is **built in** — no additional install needed
2. Install a **database-specific ODBC driver** (typically an MSI installer)
3. Drivers are registered automatically; manage them via the **ODBC Data Source Administrator** (search "ODBC" in the Start menu)

### SQLite

SQLite is ideal for local development and testing — no server required.

**Install:**
```bash
# macOS
brew install sqliteodbc

# Linux (Debian/Ubuntu)
sudo apt install libsqliteodbc
```

**Register driver** (macOS — add to `/opt/homebrew/etc/odbcinst.ini`):
```ini
[SQLite3]
Description=SQLite3 ODBC driver
Driver=/opt/homebrew/lib/libsqlite3odbc.dylib
Threading=2
```

**Register driver** (Linux — add to `/etc/odbcinst.ini`):
```ini
[SQLite3]
Description=SQLite3 ODBC driver
Driver=/usr/lib/x86_64-linux-gnu/odbc/libsqlite3odbc.so
Threading=2
```

**Connect:**
```rpgle
DCL-S connStr VARCHAR(200);
connStr = 'Driver={SQLite3};Database=/path/to/mydb.sqlite;';
EXEC SQL CONNECT USING :connStr;
```

**Windows:**

Download the SQLite ODBC driver from [http://www.ch-werner.de/sqliteodbc/](http://www.ch-werner.de/sqliteodbc/) and run the MSI installer. The driver is registered automatically. Use the same connection string as above.

The database file is created automatically if it doesn't exist.

### PostgreSQL

**Install:**
```bash
# macOS
brew install psqlodbc

# Linux (Debian/Ubuntu)
sudo apt install odbc-postgresql
```

**Register driver** (macOS — add to `/opt/homebrew/etc/odbcinst.ini`):
```ini
[PostgreSQL]
Description=PostgreSQL ODBC driver (ANSI)
Driver=/opt/homebrew/lib/psqlodbca.so
Threading=0

[PostgreSQL Unicode]
Description=PostgreSQL ODBC driver (Unicode)
Driver=/opt/homebrew/lib/psqlodbcw.so
Threading=0
```

**Register driver** (Linux — add to `/etc/odbcinst.ini`):
```ini
[PostgreSQL]
Description=PostgreSQL ODBC driver
Driver=/usr/lib/x86_64-linux-gnu/odbc/psqlodbca.so
Threading=0

[PostgreSQL Unicode]
Description=PostgreSQL ODBC driver (Unicode)
Driver=/usr/lib/x86_64-linux-gnu/odbc/psqlodbcw.so
Threading=0
```

**Windows:**

Download the PostgreSQL ODBC driver from [https://www.postgresql.org/ftp/odbc/versions/msi/](https://www.postgresql.org/ftp/odbc/versions/msi/) and run the MSI installer. The driver name is typically `PostgreSQL Unicode(x64)`.

**Connect:**
```rpgle
DCL-S connStr VARCHAR(300);

// Basic connection
connStr = 'Driver={PostgreSQL};Server=localhost;Port=5432;'
        + 'Database=mydb;Uid=myuser;Pwd=mypassword;';
EXEC SQL CONNECT USING :connStr;

// Windows (use the registered driver name)
connStr = 'Driver={PostgreSQL Unicode(x64)};Server=localhost;Port=5432;'
        + 'Database=mydb;Uid=myuser;Pwd=mypassword;';
EXEC SQL CONNECT USING :connStr;
```

### MySQL / MariaDB

**Install:**
```bash
# macOS
brew install mysql-connector-odbc

# Linux (Debian/Ubuntu)
sudo apt install libmyodbc
```

**Register driver** (macOS — find the .so path with `find /opt/homebrew -name "libmyodbc*"`):
```ini
[MySQL]
Description=MySQL ODBC driver
Driver=/opt/homebrew/lib/libmyodbc8a.so
Threading=0
```

**Windows:**

Download MySQL Connector/ODBC from [https://dev.mysql.com/downloads/connector/odbc/](https://dev.mysql.com/downloads/connector/odbc/) and run the MSI installer. The driver name is typically `MySQL ODBC 8.0 Unicode Driver`.

**Connect:**
```rpgle
DCL-S connStr VARCHAR(300);

// macOS / Linux
connStr = 'Driver={MySQL};Server=localhost;Port=3306;'
        + 'Database=mydb;User=myuser;Password=mypassword;';
EXEC SQL CONNECT USING :connStr;

// Windows
connStr = 'Driver={MySQL ODBC 8.0 Unicode Driver};Server=localhost;Port=3306;'
        + 'Database=mydb;User=myuser;Password=mypassword;';
EXEC SQL CONNECT USING :connStr;
```

### Microsoft SQL Server

**Install:**
```bash
# macOS
brew tap microsoft/mssql-release https://github.com/Microsoft/homebrew-mssql-release
brew install msodbcsql18

# Linux (Debian/Ubuntu) — see Microsoft's docs for repo setup
sudo apt install msodbcsql18
```

**Windows:**

Download "ODBC Driver 18 for SQL Server" from [Microsoft's download page](https://learn.microsoft.com/en-us/sql/connect/odbc/download-odbc-driver-for-sql-server) and run the MSI installer. SQL Server Express also installs the driver automatically.

**Connect:**
```rpgle
DCL-S connStr VARCHAR(300);
connStr = 'Driver={ODBC Driver 18 for SQL Server};'
        + 'Server=localhost,1433;Database=mydb;'
        + 'Uid=sa;Pwd=mypassword;TrustServerCertificate=yes;';
EXEC SQL CONNECT USING :connStr;
```

The connection string is the same on all platforms.

### IBM Db2

**Install (macOS / Linux):**
```bash
# Download IBM Data Server Driver from IBM's website
# Or use the IBM i Access ODBC driver for IBM i connections
```

**Install (Windows):**

Download the IBM Data Server Driver Package from [IBM Fix Central](https://www.ibm.com/support/fixcentral/) or install **IBM i Access Client Solutions** which includes the IBM i Access ODBC Driver. Run the installer and the driver is registered automatically.

**Connect:**
```rpgle
DCL-S connStr VARCHAR(300);

// Db2 on Linux/Windows
connStr = 'Driver={IBM DB2 ODBC DRIVER};'
        + 'Database=mydb;Hostname=localhost;Port=50000;'
        + 'Uid=db2admin;Pwd=mypassword;Protocol=TCPIP;';
EXEC SQL CONNECT USING :connStr;

// IBM i (via IBM i Access ODBC Driver)
connStr = 'Driver={IBM i Access ODBC Driver};'
        + 'System=myibmi.example.com;'
        + 'Uid=myuser;Pwd=mypassword;';
EXEC SQL CONNECT USING :connStr;
```

### Using Environment Variables for Connection Strings

Avoid hardcoding credentials. Use `%GETENV` to read connection details from the environment:

```rpgle
DCL-S connStr VARCHAR(300);

connStr = %GETENV('DATABASE_URL');
IF connStr = '';
  DSPLY 'DATABASE_URL not set!';
  RETURN;
ENDIF;

EXEC SQL CONNECT USING :connStr;
```

```bash
export DATABASE_URL="Driver={PostgreSQL};Server=localhost;Port=5432;Database=mydb;Uid=user;Pwd=pass;"
./myprogram
```

### Verifying Your ODBC Setup

**macOS / Linux** — list registered drivers:
```bash
odbcinst -q -d
```

Test a connection with `isql` (comes with unixODBC):
```bash
isql MyDSN myuser mypassword
```

**Windows** — open the **ODBC Data Source Administrator** (search "ODBC" in the Start menu). The **Drivers** tab lists all registered drivers. Use the **Test Connection** button when configuring a data source.

### Connection Lifecycle

```rpgle
// Connect
EXEC SQL CONNECT USING :connStr;

// ... do work ...

// Disconnect when done
EXEC SQL DISCONNECT;

// Or use CONNECT RESET (equivalent to DISCONNECT)
EXEC SQL CONNECT RESET;
```

**Note:** `rpgc` supports one database connection per program. You must disconnect before connecting to a different database.

---

## Multi-Module Programs

For larger applications, split code across modules:

**mathlib.rpgle** (module — no main):
```rpgle
**FREE
CTL-OPT NOMAIN;

DCL-PROC Add EXPORT;
  DCL-PI INT(10);
    a INT(10) VALUE;
    b INT(10) VALUE;
  END-PI;
  RETURN a + b;
END-PROC;
```

**main.rpgle** (main program):
```rpgle
**FREE

DCL-PR Add INT(10) EXTPROC('Add');
  a INT(10) VALUE;
  b INT(10) VALUE;
END-PR;

DCL-S result INT(10);
result = Add(3 : 5);
DSPLY %CHAR(result);

RETURN;
```

**Build:**
```bash
./rpgc -S mathlib.rpgle -o mathlib.cpp
clang++ -std=c++17 -Iruntime -c -o mathlib.o mathlib.cpp

./rpgc -S main.rpgle -o main.cpp
clang++ -std=c++17 -Iruntime -o myapp main.cpp mathlib.o
```

---

## Environment Variables

Read environment variables at runtime with `%GETENV`:

```rpgle
DCL-S home VARCHAR(200);
DCL-S dbUrl VARCHAR(300);

home = %GETENV('HOME');
DSPLY 'Home directory: ' + home;

dbUrl = %GETENV('DATABASE_URL');
IF dbUrl = '';
  DSPLY 'No database configured';
ENDIF;
```

`%GETENV` returns an empty string if the variable is not set.

---

## Testing

```bash
# Run all tests (validates runtime output)
make test

# Regenerate expected output baselines
make update-expected
```

The test suite includes 86 tests covering language features, built-in functions, error handling, and embedded SQL operations. SQL tests use SQLite databases that are automatically created and cleaned up during testing.

---

## Complete Example: Employee Report

Here's a full program that connects to a database, queries employees, and displays a report:

**employee_report.sqlrpgle:**
```rpgle
**FREE

DCL-DS emp QUALIFIED;
  id     INT(10);
  name   VARCHAR(50);
  salary PACKED(9:2);
END-DS;

DCL-S connStr VARCHAR(200);
DCL-S total   PACKED(11:2) INZ(0);
DCL-S count   INT(10) INZ(0);

// Connect using environment variable or default
connStr = %GETENV('DATABASE_URL');
IF connStr = '';
  connStr = 'Driver={SQLite3};Database=company.sqlite;';
ENDIF;

EXEC SQL CONNECT USING :connStr;

IF SQLCOD < 0;
  DSPLY 'Failed to connect to database';
  RETURN;
ENDIF;

// Declare and open cursor
EXEC SQL DECLARE empCur CURSOR FOR
  SELECT id, name, salary FROM employees
  ORDER BY salary DESC;

EXEC SQL OPEN empCur;

// Fetch and display
DSPLY '--- Employee Report ---';
EXEC SQL FETCH empCur INTO :emp.id, :emp.name, :emp.salary;

DOW SQLCOD = 0;
  DSPLY %CHAR(emp.id) + '  ' + %TRIM(emp.name) + '  $' + %CHAR(emp.salary);
  total += emp.salary;
  count += 1;
  EXEC SQL FETCH empCur INTO :emp.id, :emp.name, :emp.salary;
ENDDO;

EXEC SQL CLOSE empCur;

DSPLY '-----------------------';
DSPLY 'Employees: ' + %CHAR(count);
DSPLY 'Total Payroll: $' + %CHAR(total);

EXEC SQL DISCONNECT;

*INLR = *ON;
RETURN;
```

```bash
./rpgc employee_report.sqlrpgle
./employee_report
```
