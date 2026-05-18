# OpenRPG

![OpenRPG logo](assets/openrpg_logo.svg)

OpenRPG is an open-source, clean-room compiler for IBM RPG IV free-format source code. The `rpgc` binary compiles `.rpgle` source into executables that run on macOS, Linux, or Windows — no IBM i required.

## Installation

Pre-built packages are available on the [Releases](../../releases) page.

### macOS

Download `rpgc-<version>.pkg` from the Releases page. Before installation, `unixodbc` must be installed:

```bash
brew install unixodbc
```

Because OpenRPG is not code-signed with an Apple Developer certificate, macOS Gatekeeper will block the installer. Clear the quarantine flag before opening it:

```bash
xattr -cr ~/Downloads/rpgc-*.pkg
```

Then double-click the `.pkg` to install. This puts `rpgc` on your PATH system-wide.

### Linux

Download the `.deb` (Debian/Ubuntu) or `.rpm` (RHEL/Fedora) from the Releases page.

**Debian/Ubuntu:**
```bash
sudo apt install unixodbc
sudo dpkg -i rpgc_*.deb
```

**RHEL/Fedora:**
```bash
sudo dnf install unixODBC
sudo rpm -i rpgc-*.rpm
```

### Windows

Download `openrpg-<version>-windows-x64.exe` from the Releases page and run the installer. It adds `rpgc` to your PATH automatically.

---

## Quick Start

**hello.rpgle:**
```rpgle
**FREE
DCL-S msg VARCHAR(50);
msg = 'Hello from RPG!';
DSPLY msg;
*INLR = *ON;
```

```bash
rpgc hello.rpgle
./hello
```

**Output:**
```
Hello from RPG!
```

---

## Usage

```
rpgc <source-file> [options]
```

| Flag | Description |
|------|-------------|
| `-o file` | Output file |
| `-g` | Compile with debug symbols for source-level debugging |
| `-v` | Print version and exit |

```bash
rpgc program.rpgle              # produces ./program
rpgc program.rpgle -o myapp     # produces ./myapp
rpgc -v                         # print version
```

SQL programs (`.sqlrpgle`) are linked with ODBC automatically — no extra flags needed.

---

## Database Connectivity

For programs that use embedded SQL or record-level access (RLA), create an `rpgc.conf` file:

```ini
# ~/.rpgc.conf  (or ./rpgc.conf for a project-specific override)
DB_DSN=Driver={SQLite3};Database=/path/to/myapp.db;
```

With a DSN configured, no `EXEC SQL CONNECT` statement is needed in the source — OpenRPG wires up the connection automatically, just like IBM i job environments. The `RPGC_DSN` environment variable takes highest priority over any conf file.

OpenRPG uses ODBC, so it works with any database that has an ODBC driver:

| Database | Driver package | Example DSN |
|----------|---------------|-------------|
| **SQLite** | macOS: `brew install sqliteodbc`<br>Linux: `sudo apt install libsqliteodbc` | `Driver={SQLite3};Database=/path/to/file.db;` |
| **PostgreSQL** | macOS: `brew install psqlodbc`<br>Linux: `sudo apt install odbc-postgresql` | `Driver={PostgreSQL Unicode};Server=localhost;Port=5432;Database=mydb;Uid=user;Pwd=pass;` |
| **MySQL / MariaDB** | macOS: `brew install mysql-connector-odbc`<br>Linux: `sudo apt install odbc-mariadb` | `Driver={MySQL ODBC 8.0 Unicode Driver};Server=localhost;Port=3306;Database=mydb;User=user;Password=pass;` |
| **SQL Server** | [Microsoft ODBC Driver](https://learn.microsoft.com/sql/connect/odbc/download-odbc-driver-for-sql-server) | `Driver={ODBC Driver 18 for SQL Server};Server=localhost;Database=mydb;Uid=user;Pwd=pass;` |
| **IBM Db2** | [IBM Data Server Driver](https://www.ibm.com/support/pages/db2-odbc-cli-driver-download-and-installation-information) | `Driver={IBM DB2 ODBC DRIVER};Database=mydb;Hostname=localhost;Port=50000;Protocol=TCPIP;Uid=user;Pwd=pass;` |

---

## Debugging in VS Code

`rpgc -g` compiles with full debug symbols and generates `.vscode/launch.json` for the **CodeLLDB** extension. The debugger maps execution back to your original `.rpgle` source.

**One-time setup** — install the VS Code extension for your platform:

| Platform | Extension |
|----------|-----------|
| macOS / Linux | [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) (`vadimcn.vscode-lldb`) |
| Windows | [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) (`ms-vscode.cpptools`) |

**Per-program:**
```bash
rpgc -g program.rpgle -o program
```

Then open the folder in VS Code, set breakpoints in your `.rpgle` file, and press **F5**.

---

## Multi-Module Programs

OpenRPG supports splitting programs across multiple source files using `CTL-OPT NOMAIN` with `EXPORT`/`IMPORT` and `EXTPROC`:

```bash
rpgc -c module.rpgle          # compile module to module.o
rpgc main.rpgle module.o      # compile main and link with module
```

See the [User's Guide](docs/GUIDE.md#multi-module-programs) for details.

---

## Documentation

- **[User's Guide](docs/GUIDE.md)** — Full language reference with examples
- **[TODO.md](TODO.md)** — Feature tracker

### Highlights

- Full free-format RPG IV support (declarations, control flow, expressions)
- 90+ built-in functions
- Data structures (QUALIFIED, DIM, LIKEDS, OVERLAY, POS, PREFIX)
- Procedures with prototypes, optional parameters (*NOPASS, *OMIT)
- Enumerations (DCL-ENUM) and BOOLEAN type
- Varying-dimension arrays (DIM(*VAR), DIM(*AUTO))
- Date/time arithmetic with all format constants
- MONITOR/ON-ERROR error handling, *PSSR, ON-EXIT
- Multi-module support (NOMAIN, EXPORT, IMPORT, EXTPROC)
- Conditional compilation (/IF, /DEFINE, /COPY)
- Embedded SQL via ODBC (SQLite, PostgreSQL, MySQL, SQL Server, Db2)
- Record-level access (READ, WRITE, CHAIN, UPDATE, DELETE, SETLL, SETGT) via ODBC
- DATA-INTO / DATA-GEN for JSON parsing and generation
- Source-level debugging in VS Code (`rpgc -g`)

---

## Building from Source

If you prefer to build from source rather than using a pre-built package:

**Prerequisites:** C++17 compiler (clang++ or g++), Flex, Bison.

```bash
# macOS
brew install flex bison

# Linux (Debian/Ubuntu)
sudo apt install flex bison g++

# Windows — use MSYS2 MINGW64 shell
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-flex mingw-w64-x86_64-bison make
```

```bash
git clone https://github.com/danlong005/OpenRPG.git
cd OpenRPG
make
sudo make install        # installs to /usr/local
```

---

## Trademarks

RPG, RPG IV, ILE, ILE RPG, RPG/400, IBM i, AS/400, and Db2 are trademarks
or registered trademarks of International Business Machines Corporation in
the United States, other countries, or both. Other product and service
names might be trademarks of IBM or other companies.

This project is an independent, clean-room implementation. It is not
affiliated with, endorsed by, sponsored by, or otherwise associated with
IBM. References to IBM products and technologies are made solely for the
purpose of describing compatibility and interoperability (nominative fair
use).

## License

MIT — see [LICENSE](LICENSE) for details.
