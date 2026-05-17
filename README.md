# openrpg

![openrpg logo](assets/openrpg_logo.svg)

openrpg is an open-source, clean-room compiler for IBM RPG IV free-format source code. The `rpgc` binary compiles `.rpgle` source into executables that run on macOS, Linux, or Windows — no IBM i required.

## Prerequisites

- **C++17 compiler** (clang++ or g++)
- **Flex** (lexer generator)
- **Bison** (parser generator)

On macOS with Homebrew:
```bash
brew install flex bison
```

On Linux (Debian/Ubuntu):
```bash
sudo apt install flex bison g++
```

On Windows (via [MSYS2](https://www.msys2.org/) MINGW64 shell):
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-flex mingw-w64-x86_64-bison make
```

> **Alternative:** Use [winflexbison](https://github.com/nicehash/winflexbison) with Visual Studio or `choco install winflexbison`. Adjust `FLEX` and `BISON` paths in the Makefile accordingly.

## Building

```bash
make
```

This produces the `rpgc` executable in the project root.

If your `flex` and `bison` are in non-standard locations, edit the `FLEX` and `BISON` paths in the `Makefile`.

```bash
make clean   # Remove build artifacts
```

### Installing

```bash
sudo make install              # installs to /usr/local
make install PREFIX=~/.local   # install without sudo
sudo make uninstall            # remove
```

This installs the `rpgc` binary and runtime headers. `rpgc` automatically locates the runtime whether run from the source tree or after installation.

#### macOS installer (.pkg)

Pre-built `.pkg` installers are available on the [Releases](../../releases) page. The installer requires **unixodbc**, which you can install with Homebrew before running the `.pkg`:

```bash
brew install unixodbc
```

Because openrpg is not code-signed with an Apple Developer certificate, macOS Gatekeeper will block the installer with an "unidentified developer" warning. To work around it, run this command in Terminal before opening the file:

```bash
xattr -cr ~/Downloads/rpgc-*.pkg
```

Then double-click the `.pkg` to proceed with installation normally.

## Usage

```bash
# Compile to executable (default)
./rpgc program.rpgle              # produces ./program
./rpgc program.rpgle -o myapp     # produces ./myapp

# Emit intermediate source only, do not compile
./rpgc program.rpgle -S           # produces ./program.cpp
./rpgc program.rpgle -S -o out.cpp

# Compile and keep the intermediate source file
./rpgc program.rpgle --keep-cpp
```

| Flag | Description |
|------|-------------|
| `-o file` | Output file |
| `-S` | Emit intermediate source only, do not compile |
| `-g` | Compile with debug symbols for source-level debugging |
| `--keep-cpp` | Keep the intermediate source file after compiling |

### Debugging in VS Code

`rpgc -g` compiles your program with full debug symbols and generates a `.vscode/launch.json` configured for the **CodeLLDB** extension. The debugger maps execution back to your original `.rpgle` source, so you step through RPG — not generated code.

**One-time setup:**

Install the appropriate VS Code extension for your platform:

| Platform | Extension |
|----------|-----------|
| macOS / Linux | [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) (`vadimcn.vscode-lldb`) |
| Windows | [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) (`ms-vscode.cpptools`) |

**Per-program workflow:**

```bash
./rpgc -g program.rpgle -o program
```

This produces the `program` binary and writes `.vscode/launch.json`. Then in VS Code:

1. Open the folder containing your `.rpgle` files.
2. Set breakpoints by clicking in the gutter of any `.rpgle` file.
3. Press **F5** to launch the debugger.

You can step through your RPG source line by line, inspect variable values by hovering, and view the call stack — all anchored to your `.rpgle` file.

> **Note:** If you recompile without `-g`, remove `.vscode/launch.json` or the debugger will still try to attach.

---

### Multi-module programs

For programs using NOMAIN modules with EXPORT/IMPORT:

```bash
# Compile the module (no main)
./rpgc module.rpgle -S -o module.cpp
clang++ -std=c++17 -Iruntime -c -o module.o module.cpp

# Compile the main program and link with the module
./rpgc main.rpgle -S -o main.cpp
clang++ -std=c++17 -Iruntime -o program main.cpp module.o
```

### Database connectivity (rpgc.conf)

For programs that use embedded SQL or record-level access (RLA), create an `rpgc.conf` file in your home directory or in the directory where you invoke the compiler:

```ini
# ~/.rpgc.conf  (or ./rpgc.conf for a project-specific override)
DB_DSN=Driver={SQLite3};Database=/path/to/myapp.db;
```

With a DSN configured, no `EXEC SQL CONNECT` statement is needed in the source — the compiler wires up the connection automatically, just like IBM i job environments. The `RPGC_DSN` environment variable takes highest priority over any conf file.

`rpgc` uses ODBC, so it works with any database that has an ODBC driver. Install the driver for your database, then set the appropriate connection string:

| Database | Driver package | Example DSN |
|----------|---------------|-------------|
| **SQLite** | macOS: `brew install sqliteodbc`<br>Linux: `sudo apt install libsqliteodbc` | `Driver={SQLite3};Database=/path/to/file.db;` |
| **PostgreSQL** | macOS: `brew install psqlodbc`<br>Linux: `sudo apt install odbc-postgresql` | `Driver={PostgreSQL Unicode};Server=localhost;Port=5432;Database=mydb;Uid=user;Pwd=pass;` |
| **MySQL / MariaDB** | macOS: `brew install mysql-connector-odbc`<br>Linux: `sudo apt install odbc-mariadb` | `Driver={MySQL ODBC 8.0 Unicode Driver};Server=localhost;Port=3306;Database=mydb;User=user;Password=pass;` |
| **SQL Server** | [Microsoft ODBC Driver](https://learn.microsoft.com/sql/connect/odbc/download-odbc-driver-for-sql-server) | `Driver={ODBC Driver 18 for SQL Server};Server=localhost;Database=mydb;Uid=user;Pwd=pass;` |
| **IBM Db2** | [IBM Data Server Driver](https://www.ibm.com/support/pages/db2-odbc-cli-driver-download-and-installation-information) | `Driver={IBM DB2 ODBC DRIVER};Database=mydb;Hostname=localhost;Port=50000;Protocol=TCPIP;Uid=user;Pwd=pass;` |

After installing a driver you may need to register it with `odbcinst`. Check your driver's documentation for the exact driver name to use in the DSN string.

## Example

**hello.rpgle:**
```rpgle
**FREE
DCL-S msg VARCHAR(50);
msg = 'Hello from RPG!';
DSPLY msg;
*INLR = *ON;
```

**Compile and run:**
```bash
./rpgc hello.rpgle
./hello
```

**Output:**
```
Hello from RPG!
```

## Running Tests

```bash
make test              # Run all tests (validates runtime output)
make update-expected   # Regenerate expected output baselines
```

## Project Structure

```
openrpg/
  src/
    lexer.l            Lexer
    parser.y           Parser
    ast.h / ast.cpp    Abstract syntax tree
    codegen.h / codegen.cpp  Code generator
    conf.h / conf.cpp  rpgc.conf reader
    extdesc.h / extdesc.cpp  External file description (schema pre-pass)
    main.cpp           Entry point
  runtime/
    rpg_runtime.h      Runtime support library
    rpg_sql_runtime.h  SQL/ODBC runtime support
    rpg_xml_runtime.h  XML runtime support
  tests/
    test*.rpgle         RPG test source files
    test*.sqlrpgle      SQL test source files
    expected_output/    Expected runtime output for each test
    run_tests.sh        Test runner script
  Makefile
  TODO.md              Feature tracker
```

## Documentation

- **[User's Guide](docs/GUIDE.md)** — Full language guide with database connection examples
- **[TODO.md](TODO.md)** — Feature tracker (implemented, remaining, not planned)

### Highlights
- Full free-format RPG IV support (declarations, control flow, expressions)
- 90+ built-in functions
- Data structures (QUALIFIED, DIM, LIKEDS, OVERLAY, POS, PREFIX)
- Procedures with prototypes, optional parameters (*NOPASS, *OMIT)
- Enumerations (DCL-ENUM) and BOOLEAN type
- Varying-dimension arrays (DIM(*VAR), DIM(*AUTO))
- Date/time arithmetic with all format constants
- MONITOR/ON-ERROR error handling
- *PSSR global exception handler
- ON-EXIT cleanup blocks
- Multi-module support (NOMAIN, EXPORT, IMPORT, EXTPROC)
- Conditional compilation (/IF, /DEFINE, /COPY)
- Embedded SQL via ODBC (SQLite, PostgreSQL, MySQL, SQL Server, Db2)
- Record-level access (READ, WRITE, CHAIN, UPDATE, DELETE, SETLL, SETGT) via ODBC
- Externally-described files with `.extdesc` schema cache
- DATA-INTO / DATA-GEN for JSON parsing and generation
- Source-level debugging in VS Code via CodeLLDB (`rpgc -g`)

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
