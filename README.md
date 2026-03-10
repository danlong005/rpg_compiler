# rpgc — RPG IV to C++ Transpiler

`rpgc` transpiles IBM RPG IV free-format source code into portable C++17. The generated C++ can be compiled and run on macOS, Linux, or Windows — no IBM i required.

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

## Usage

By default, `rpgc` compiles the RPG source all the way to an executable:

```bash
# Compile to executable (default)
./rpgc program.rpgle              # produces ./program
./rpgc program.rpgle -o myapp     # produces ./myapp

# Emit C++ only, do not compile
./rpgc program.rpgle -S           # produces ./program.cpp
./rpgc program.rpgle -S -o out.cpp  # C++ to file

# Compile to executable and keep the intermediate .cpp file
./rpgc program.rpgle --keep-cpp   # produces ./program and ./program.cpp
```

| Flag | Description |
|------|-------------|
| `-o file` | Output file (executable by default, or C++ file with `-S`) |
| `-S` | Emit C++ source only, do not compile |
| `--keep-cpp` | Keep the intermediate `.cpp` file after compiling |

### Multi-module programs

For programs using NOMAIN modules with EXPORT/IMPORT:

```bash
# Emit and compile the module (no main)
./rpgc module.rpgle -S -o module.cpp
clang++ -std=c++17 -Iruntime -c -o module.o module.cpp

# Compile the main program and link with the module
./rpgc main.rpgle -S -o main.cpp
clang++ -std=c++17 -Iruntime -o program main.cpp module.o
```

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
rpgc/
  src/
    lexer.l        Flex lexer (tokenizer)
    parser.y       Bison parser (grammar)
    ast.h / ast.cpp  Abstract syntax tree definitions
    codegen.h / codegen.cpp  C++ code generator
    main.cpp       Entry point
  runtime/
    rpg_runtime.h  Runtime support library (included by generated code)
  tests/
    test*.rpgle         RPG test source files
    test*.sqlrpgle      SQL test source files
    expected_output/    Expected runtime output for each test
    run_tests.sh        Test runner script
  build/           Generated lexer/parser files and object files
  Makefile
  TODO.md          Feature tracker
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

## License

This project is not yet licensed. All rights reserved.
