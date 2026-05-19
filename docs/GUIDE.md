# OpenRPG User's Guide

OpenRPG transpiles IBM RPG IV free-format source code into portable C++17 and optionally compiles it to a native executable. Programs can run on macOS, Linux, or any platform with a C++ compiler — no IBM i required.

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
9. [Varying-Dimension Arrays](#varying-dimension-arrays)
10. [Control Flow](#control-flow)
11. [Procedures](#procedures)
12. [Procedure Overloading](#procedure-overloading)
13. [Built-In Functions](#built-in-functions)
14. [Error Handling](#error-handling)
15. [Operation Extenders](#operation-extenders)
16. [Enumerations](#enumerations)
17. [Program Status Data Structure](#program-status-data-structure)
18. [Data Areas](#data-areas)
19. [SND-MSG](#snd-msg)
20. [Embedded SQL](#embedded-sql)
21. [Record-Level Access](#record-level-access)
22. [DATA-INTO and DATA-GEN](#data-into-and-data-gen)
23. [XML-INTO](#xml-into)
24. [Database Connections](#database-connections)
25. [Multi-Module Programs](#multi-module-programs)
26. [Environment Variables](#environment-variables)
27. [Testing](#testing)

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

To install OpenRPG system-wide:

```bash
sudo make install              # installs to /usr/local/bin
make install PREFIX=~/.local   # or install to ~/.local/bin (no sudo needed)
```

This installs:
- `rpgc` binary to `$PREFIX/bin/`
- Runtime headers to `$PREFIX/share/rpgc/runtime/`

When compiling RPG programs, OpenRPG automatically finds the runtime headers — it checks relative to the binary, the current directory, and the install prefix.

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

When the input file has a `.sqlrpgle` extension, OpenRPG automatically adds ODBC include paths and linker flags during compilation.

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

Programs using embedded SQL should use the `.sqlrpgle` file extension. This tells OpenRPG to automatically link the ODBC library.

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

OpenRPG uses ODBC for database access, making it portable across databases. You connect using a connection string with `EXEC SQL CONNECT USING`.

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

**Note:** OpenRPG supports one database connection per program. You must disconnect before connecting to a different database.

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
rpgc -c mathlib.rpgle              # produces mathlib.o
rpgc main.rpgle mathlib.o -o myapp # compiles main and links with module
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

The test suite includes 115 tests covering language features, built-in functions, error handling, embedded SQL, and record-level access. SQL and RLA tests use SQLite databases that are automatically created and cleaned up during testing.

---

## Varying-Dimension Arrays

### DIM(\*VAR) — Fixed Capacity, Variable Size

Declare an array with a maximum capacity but let the active size grow at runtime:

```rpgle
DCL-S scores INT(10) DIM(*VAR: 100);   // up to 100 elements

// Set the active size
%ELEM(scores) = 5;
scores(1) = 90;
scores(2) = 85;
// ...

DSPLY 'Count: ' + %CHAR(%ELEM(scores));   // 5
```

### DIM(\*AUTO) — Grows Automatically

`DIM(*AUTO: max)` behaves like `DIM(*VAR: max)` but the array expands as you assign to
higher indices — no explicit `%ELEM(arr) = n` required:

```rpgle
DCL-S tags VARCHAR(20) DIM(*AUTO: 50);

tags(1) = 'alpha';
tags(2) = 'beta';
tags(3) = 'gamma';
// %ELEM(tags) is now 3 automatically
DSPLY %CHAR(%ELEM(tags));    // 3
```

### %ELEM(\*ALLOC) and %ELEM(\*KEEP)

Control the underlying buffer capacity separately from the active element count:

```rpgle
DCL-S nums INT(10) DIM(*VAR: 10);

// Expand allocation beyond the declared max
%ELEM(nums : *ALLOC) = 50;
DSPLY %CHAR(%ELEM(nums : *ALLOC));   // 50 — capacity
DSPLY %CHAR(%ELEM(nums));            // 0  — active size unchanged

// Populate 5 elements
%ELEM(nums) = 5;
FOR i = 1 TO 5;
  nums(i) = i * 10;
ENDFOR;

// Shrink active count without releasing the buffer
%ELEM(nums : *KEEP) = 3;
DSPLY %CHAR(%ELEM(nums));            // 3  — active size
DSPLY %CHAR(%ELEM(nums : *ALLOC));   // 50 — capacity still intact
```

Use `*KEEP` when you want to reuse the same buffer across iterations without
repeated reallocations.

### Arrays of Data Structures

```rpgle
DCL-DS employee QUALIFIED DIM(*VAR: 50);
  id   INT(10);
  name VARCHAR(40);
END-DS;

%ELEM(employee) = 2;
employee(1).id = 101;
employee(1).name = 'Alice';
employee(2).id = 102;
employee(2).name = 'Bob';

DSPLY employee(1).name;
```

---

## Operation Extenders

Operation extenders modify the behavior of `EVAL`, `EVALR`, and `CALLP`. They are
written in parentheses after the opcode.

### (H) — Half-Adjust (Round)

Rounds the result to the target precision before assignment:

```rpgle
DCL-S a PACKED(7:1) INZ(7.0);
DCL-S b PACKED(7:0) INZ(2);
DCL-S result INT(10);

EVAL(H) result = a / b;   // 7.0 / 2 = 3.5, rounds to 4
DSPLY %CHAR(result);       // 4
```

### (R) — Round

Synonym for `(H)`:

```rpgle
EVAL(R) result = a / b;
```

### (E) — Error Capture

Prevents a runtime error from halting the program. After the operation, check
`%ERROR` to see if it failed:

```rpgle
CALLP(E) riskProc(arg);
IF %ERROR;
  DSPLY 'Call failed: ' + %CHAR(%STATUS);
ENDIF;

EVAL(E) x = someCalc();
IF %ERROR;
  DSPLY 'Calc error';
ENDIF;
```

### (M) — Move (multiple extenders)

Extenders can be combined — e.g., `EVAL(MH)` means move with half-adjust:

```rpgle
EVAL(MH) result = a / b;
```

### (P) — Pad

For string assignments, pads the target with blanks. For numeric, same as no
extender. Primarily a compatibility keyword; accepted and parsed:

```rpgle
EVAL(P) padStr = 'HELLO';
```

### (N) — No Lock

Accepted on file operations and `EVAL`; treated as a no-op outside record-level
access. Useful when porting code that uses `(N)` on READ/CHAIN:

```rpgle
EVAL(N) x = x + 1;
```

### EVALR with Extenders

`EVALR` right-adjusts the result into the target. Extenders work the same way:

```rpgle
DCL-S target CHAR(10);
DCL-S n PACKED(7:1) INZ(3.7);
EVALR(H) target = n;   // rounds to 4, right-justified in 10 chars
```

---

## Enumerations

`DCL-ENUM` defines a named set of constants. Use `QUALIFIED` so each value is
accessed with the enum name as a prefix.

```rpgle
DCL-ENUM Color QUALIFIED;
  Red;       // 0
  Green;     // 1
  Blue;      // 2
END-ENUM;

DCL-S paint INT(10);
paint = Color.Green;

SELECT;
  WHEN paint = Color.Red;
    DSPLY 'Red';
  WHEN paint = Color.Green;
    DSPLY 'Green';
  WHEN paint = Color.Blue;
    DSPLY 'Blue';
ENDSL;
```

### BOOLEAN Type

`BOOLEAN` is a built-in type that holds `*ON` or `*OFF`:

```rpgle
DCL-S isReady BOOLEAN INZ(*OFF);
DCL-S hasError BOOLEAN;

isReady = *ON;

IF isReady AND NOT hasError;
  DSPLY 'Ready and no errors';
ENDIF;
```

---

## Program Status Data Structure

The PSDS (`PSDS`) keyword on a `DCL-DS` declares the Program Status Data Structure.
OpenRPG populates it at startup with process and environment information, mirroring
the IBM i layout at the well-known POS offsets.

```rpgle
DCL-DS PgmInfo PSDS QUALIFIED;
  PgmName CHAR(10) POS(81);    // program name (source file stem)
  UserID  CHAR(10) POS(91);    // current OS user
  JobNum  CHAR(8)  POS(101);   // process ID (zero-padded)
  RunDate CHAR(8)  POS(109);   // YYYYMMDD
  RunTime CHAR(6)  POS(119);   // HHMMSS
END-DS;
```

| POS | Length | Content |
|-----|--------|---------|
| 1   | 10     | Current procedure name |
| 11  | 5      | Current status code (PACKED 5,0) |
| 81  | 10     | Program name |
| 91  | 10     | User profile / OS username |
| 101 | 8      | Job number (PID, zero-padded) |
| 109 | 8      | Run date (YYYYMMDD) |
| 119 | 6      | Run time (HHMMSS) |

```rpgle
IF %TRIM(PgmInfo.UserID) <> '';
  DSPLY 'Running as: ' + PgmInfo.UserID;
ENDIF;

DSPLY 'Started: ' + PgmInfo.RunDate + ' ' + PgmInfo.RunTime;
```

The PSDS also syncs before every `ON-ERROR` handler fires, so you can read
`StatusCode` inside `MONITOR` blocks to identify the error.

---

## Data Areas

Data areas are persistent named storage outside of any single program. On IBM i
they are system objects; in OpenRPG they are plain files on the local filesystem,
stored in `$TMPDIR` (typically `/tmp`).

### Declare a Data Area Variable

Add `DTAARA` to a `DCL-S` or `DCL-DS`:

```rpgle
// *LDA — the Local Data Area (one per job/process)
DCL-S LdaData CHAR(256) DTAARA(*LDA);

// Named data area
DCL-S Config CHAR(100) DTAARA(APPCONFIG);
```

### IN — Read from Data Area

```rpgle
IN LdaData;
DSPLY %TRIM(LdaData);
```

### OUT — Write to Data Area

```rpgle
LdaData = 'SESSION_ID=ABC123';
OUT LdaData;
```

### UNLOCK — Release the Lock

`IN` acquires an exclusive lock on the data area. `UNLOCK` releases it when you
are done reading so other programs can access it:

```rpgle
IN LdaData;
// ... use LdaData ...
UNLOCK LdaData;
```

### Round-Trip Example

```rpgle
DCL-S LdaData CHAR(20) DTAARA(*LDA);

LdaData = 'HELLO DATA AREA     ';
OUT LdaData;

LdaData = '';      // clear local copy
IN LdaData;        // read back from storage

DSPLY %TRIM(LdaData);   // HELLO DATA AREA
UNLOCK LdaData;
```

### Named Data Areas

```rpgle
DCL-S MyConfig CHAR(50) DTAARA(RPGCONFIG);

MyConfig = 'VERSION=2.0';
OUT MyConfig;

MyConfig = '';
IN MyConfig;
DSPLY %SUBST(MyConfig: 1: 11);   // VERSION=2.0
UNLOCK MyConfig;
```

> Data area files are created automatically on `OUT` if they do not exist.
> On IBM i the equivalent would be `CRTDTAARA`.

---

## SND-MSG

`SND-MSG` sends a message to the program message queue. In OpenRPG, `*INFO` and
`*DIAG` messages are written to stderr. `*ESCAPE` raises a catchable exception.

### Syntax

```rpgle
SND-MSG *INFO 'Informational message';
SND-MSG *DIAG 'Diagnostic detail';
SND-MSG *ESCAPE 'Fatal error text';

// TYPE() keyword form
SND-MSG TYPE(*INFO) 'Processing complete';

// Bare form — defaults to *INFO
SND-MSG 'Something happened';

// Variable message
DCL-S msg VARCHAR(100);
msg = 'Row count: ' + %CHAR(rowCount);
SND-MSG *DIAG msg;
```

### Catching \*ESCAPE with MONITOR

`*ESCAPE` is the only message type that can interrupt normal flow. Wrap it in a
`MONITOR` block to handle it gracefully:

```rpgle
MONITOR;
  SND-MSG *ESCAPE 'Validation failed';
ON-ERROR;
  DSPLY 'Caught: ' + %CHAR(%STATUS);
ENDMON;
```

---

## Record-Level Access

Record-Level Access (RLA) is RPG's native file I/O model. In OpenRPG, RLA is
implemented over ODBC — the file is actually a database table, and the RLA opcodes
translate to SQL operations transparently. Any ODBC-connected database works.

### Declaring a File

```rpgle
DCL-F filename DISK KEYED EXTDESC('tablename');
```

| Keyword | Meaning |
|---------|---------|
| `DISK` | Disk (database) file |
| `KEYED` | Key-based access (CHAIN, SETLL, READE) |
| `EXTDESC('name')` | Maps to the SQL table named `name` |

Omit `KEYED` for sequential-only access.

The table's columns become program-scope variables with the same names as the
column definitions. All names are uppercased to match RPG convention.

### CHAIN — Random Read by Key

```rpgle
DCL-F CUSTFL DISK KEYED EXTDESC('customers');
DCL-S key VARCHAR(10);

key = 'C001';
CHAIN key CUSTFL;
IF %FOUND(CUSTFL);
  DSPLY CUSTNO;
  DSPLY CUSTNAME;
ENDIF;
```

`%FOUND(filename)` is true when the last CHAIN found a record.

### READ — Sequential Read

```rpgle
DCL-F CUSTFL DISK EXTDESC('customers');

READ CUSTFL;
DOW NOT %EOF(CUSTFL);
  DSPLY CUSTNAME;
  READ CUSTFL;
ENDDO;
```

`%EOF(filename)` becomes true after a READ past the last record.

### WRITE — Insert a New Record

Assign values to the field variables, then WRITE:

```rpgle
CUSTNO   = 'C010';
CUSTNAME = 'New Customer';
CUSTBAL  = 0;
WRITE CUSTFL;
```

### UPDATE — Modify the Current Record

After a successful CHAIN or READ, modify fields and UPDATE:

```rpgle
key = 'C001';
CHAIN key CUSTFL;
IF %FOUND(CUSTFL);
  CUSTBAL = CUSTBAL + 500;
  UPDATE CUSTFL;
ENDIF;
```

### DELETE — Remove the Current Record

After a successful CHAIN or READ, DELETE removes that row:

```rpgle
key = 'C010';
CHAIN key CUSTFL;
IF %FOUND(CUSTFL);
  DELETE CUSTFL;
ENDIF;
```

### SETLL — Position to a Key

`SETLL` positions the file cursor so the next READ starts at the first record
with a key >= the argument:

```rpgle
DCL-F CUSTFL DISK KEYED EXTDESC('customers');
DCL-S key VARCHAR(10);

key = 'B000';
SETLL key CUSTFL;

READ CUSTFL;
DOW NOT %EOF(CUSTFL) AND CUSTNO <= 'B999';
  DSPLY CUSTNO + ' ' + CUSTNAME;
  READ CUSTFL;
ENDDO;
```

### READE — Read Equal Key

`READE` reads the next record only if its key matches the argument:

```rpgle
key = 'B002';
SETLL key CUSTFL;

READE key CUSTFL;
IF %FOUND(CUSTFL);
  DSPLY CUSTNAME;
ENDIF;
```

### Connection

RLA uses the same ODBC connection as embedded SQL. You can connect explicitly or
use `rpgc.conf` (see [Database Connections](#database-connections)):

```rpgle
DCL-F CUSTFL DISK KEYED EXTDESC('customers');
DCL-S connStr VARCHAR(200);

connStr = 'Driver={SQLite3};Database=myapp.db;';
EXEC SQL CONNECT USING :connStr;

key = 'C001';
CHAIN key CUSTFL;
```

Or with `rpgc.conf` — no `EXEC SQL CONNECT` needed at all:

```rpgle
DCL-F CUSTFL DISK KEYED EXTDESC('customers');
DCL-S key VARCHAR(10);

key = 'B002';
CHAIN key CUSTFL;
IF %FOUND(CUSTFL);
  DSPLY CUSTNAME;
ENDIF;
```

### Complete RLA Example

```rpgle
**FREE

DCL-F EMPFL DISK KEYED EXTDESC('employees');

DCL-S connStr VARCHAR(200);
DCL-S key     VARCHAR(10);

connStr = 'Driver={SQLite3};Database=company.db;';
EXEC SQL CONNECT USING :connStr;

EXEC SQL CREATE TABLE employees (
  EMPNO   VARCHAR(10) PRIMARY KEY,
  EMPNAME VARCHAR(50),
  SALARY  DECIMAL(9,2)
);
EXEC SQL INSERT INTO employees VALUES('E001','Alice',85000);
EXEC SQL INSERT INTO employees VALUES('E002','Bob',72000);
EXEC SQL INSERT INTO employees VALUES('E003','Carol',91000);

// Random read
key = 'E002';
CHAIN key EMPFL;
IF %FOUND(EMPFL);
  DSPLY 'Found: ' + EMPNAME;
ENDIF;

// Sequential scan
READ EMPFL;
DOW NOT %EOF(EMPFL);
  DSPLY EMPNO + ' ' + EMPNAME;
  READ EMPFL;
ENDDO;

// Write a new record
EMPNO   = 'E004';
EMPNAME = 'David';
SALARY  = 68000;
WRITE EMPFL;

// Update
key = 'E001';
CHAIN key EMPFL;
IF %FOUND(EMPFL);
  SALARY = SALARY + 5000;
  UPDATE EMPFL;
ENDIF;

// Delete
key = 'E004';
CHAIN key EMPFL;
IF %FOUND(EMPFL);
  DELETE EMPFL;
ENDIF;

EXEC SQL DROP TABLE employees;
EXEC SQL DISCONNECT;
*INLR = *ON;
```

---

## DATA-INTO and DATA-GEN

`DATA-INTO` parses structured data (JSON) into a data structure.
`DATA-GEN` serializes a data structure to structured data (JSON).

### DATA-INTO — Parse JSON

```rpgle
DCL-DS person QUALIFIED;
  name VARCHAR(40);
  age  INT(10);
  city VARCHAR(30);
END-DS;

DCL-S json VARCHAR(500);
json = '{"name":"Alice","age":30,"city":"Boston"}';

DATA-INTO person %DATA(json : 'doc=string case=any');

DSPLY person.name;              // Alice
DSPLY %CHAR(person.age);        // 30
DSPLY person.city;              // Boston
```

The `%DATA` BIF takes the data source and an options string:

| Option | Meaning |
|--------|---------|
| `doc=string` | The data is a string variable (not a file) |
| `case=any` | Case-insensitive field name matching |

Fields not present in the JSON default to zero (numeric) or blank (character).

### DATA-GEN — Generate JSON

```rpgle
DCL-DS item QUALIFIED;
  id    INT(10);
  price PACKED(9:2);
  label VARCHAR(30);
END-DS;

DCL-S json VARCHAR(300);

item.id    = 42;
item.price = 19.99;
item.label = 'Widget';

DATA-GEN item %DATA(json : 'doc=string');

DSPLY json;   // {"id":42,"price":19.99,"label":"Widget"}
```

### Numeric Types

PACKED, ZONED, INT, FLOAT, and UNS fields all round-trip correctly:

```rpgle
DCL-DS product QUALIFIED;
  id    INT(10);
  price PACKED(9:2);
  qty   INT(10);
END-DS;

json = '{"id":99,"price":4.50,"qty":10}';
DATA-INTO product %DATA(json : 'doc=string case=any');

DSPLY %CHAR(product.price);   // 4.50
```

### Special Characters in Strings

`DATA-GEN` escapes double-quotes and other JSON special characters automatically:

```rpgle
DCL-DS msg QUALIFIED;
  text VARCHAR(100);
END-DS;

msg.text = 'Price < $10 & "sale"';
DATA-GEN msg %DATA(json : 'doc=string');
// {"text":"Price < $10 & \"sale\""}
```

---

## XML-INTO

`XML-INTO` parses an XML string into a data structure or array of data structures.
It uses the `%XML` BIF to specify the data source and parsing options.

### Basic Usage

```rpgle
DCL-DS order QUALIFIED;
  id       INT(10);
  customer VARCHAR(50);
  qty      INT(10);
END-DS;

DCL-S xml VARCHAR(500);
xml = '<order><id>1001</id><customer>Acme</customer><qty>25</qty></order>';

XML-INTO order %XML(xml : 'case=any');

DSPLY %CHAR(order.id);        // 1001
DSPLY order.customer;          // Acme
DSPLY %CHAR(order.qty);        // 25
```

### Options

| Option | Meaning |
|--------|---------|
| `case=any` | Case-insensitive element-to-field matching |
| `path=a/b/c` | Navigate into the XML tree before mapping |

Missing elements default to zero or blank. Unknown elements are ignored.

### PATH Option

Use `path=` to navigate past wrapper elements:

```rpgle
DCL-DS rec QUALIFIED;
  id   INT(10);
  name VARCHAR(40);
END-DS;

xml = '<response><data><record><id>5</id><name>Alice</name></record></data></response>';

XML-INTO rec %XML(xml : 'case=any path=response/data/record');

DSPLY %CHAR(rec.id);    // 5
DSPLY rec.name;          // Alice
```

### Array Target

Map a repeating XML element into an array DS. Use `path=` to name the parent
element, and the target DS array receives one element per child:

```rpgle
DCL-DS item QUALIFIED DIM(5);
  name  VARCHAR(50);
  qty   INT(10);
  price PACKED(9:2);
END-DS;

xml = '<items>' +
      '<item><name>Widget</name><qty>5</qty><price>19.99</price></item>' +
      '<item><name>Gadget</name><qty>3</qty><price>29.50</price></item>' +
      '</items>';

XML-INTO item %XML(xml : 'case=any path=items');

DSPLY item(1).name + ' qty=' + %CHAR(item(1).qty);   // Widget qty=5
DSPLY item(2).name + ' qty=' + %CHAR(item(2).qty);   // Gadget qty=3
```

Use `DIM(*VAR: n)` to handle a variable number of elements:

```rpgle
DCL-DS emp QUALIFIED DIM(*VAR: 50);
  id   INT(10);
  name VARCHAR(40);
END-DS;

XML-INTO emp %XML(xml : 'case=any path=employees');

DSPLY 'Count: ' + %CHAR(%ELEM(emp));
```

### Nested Data Structures with LIKEDS

```rpgle
DCL-DS address QUALIFIED;
  street VARCHAR(50);
  city   VARCHAR(30);
  state  CHAR(2);
END-DS;

DCL-DS customer QUALIFIED;
  name VARCHAR(50);
  age  INT(10);
  addr LIKEDS(address);
END-DS;

xml = '<customer>' +
        '<name>Alice</name><age>30</age>' +
        '<addr><street>123 Main</street><city>Boston</city><state>MA</state></addr>' +
      '</customer>';

XML-INTO customer %XML(xml : 'case=any');

DSPLY customer.name;           // Alice
DSPLY customer.addr.city;      // Boston
DSPLY customer.addr.state;     // MA
```

---

## Procedure Overloading

`OVERLOAD` declares a generic procedure name that dispatches to one of several
typed implementations based on argument types at call time.

### Declaration

```rpgle
// Typed implementations
DCL-PR absInt INT(10);
  n INT(10) VALUE;
END-PR;

DCL-PR absFloat FLOAT(8);
  n FLOAT(8) VALUE;
END-PR;

// Generic overloaded name
DCL-PR abs OVERLOAD(absInt : absFloat);
END-PR;
```

### Calling

The compiler selects the implementation whose parameter types best match the
argument types at the call site:

```rpgle
DCL-S i INT(10);
DCL-S f FLOAT(8);

i = abs(-7);      // calls absInt
f = abs(-3.5);    // calls absFloat
```

### Full Example

```rpgle
**FREE

CTL-OPT MAIN(main);

DCL-PR formatInt   VARCHAR(30);
  n INT(10) VALUE;
END-PR;

DCL-PR formatFloat VARCHAR(30);
  n FLOAT(8) VALUE;
END-PR;

DCL-PR format OVERLOAD(formatInt : formatFloat);
END-PR;

DCL-PROC main;
  DCL-PI main; END-PI;

  DSPLY format(42);      // calls formatInt  → "INT:42"
  DSPLY format(3.14);    // calls formatFloat → "FLT:3"
END-PROC;

DCL-PROC formatInt EXPORT;
  DCL-PI formatInt VARCHAR(30);
    n INT(10) VALUE;
  END-PI;
  RETURN 'INT:' + %CHAR(n);
END-PROC;

DCL-PROC formatFloat EXPORT;
  DCL-PI formatFloat VARCHAR(30);
    n FLOAT(8) VALUE;
  END-PI;
  RETURN 'FLT:' + %CHAR(%INT(n));
END-PROC;
```

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
