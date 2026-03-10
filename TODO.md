# RPG IV Free-Format Feature Tracker

---

## ✅ Implemented Features

### Core Language
- **FREE, DCL-S (CHAR, VARCHAR, INT, PACKED, ZONED, IND, DATE, TIME, TIMESTAMP, POINTER, UNS, FLOAT, BINDEC)
- DCL-S keywords: DIM, DIM(*VAR:max), DIM(*AUTO:max), LIKE, INZ, CONST, STATIC, TEMPLATE, BASED, ASCEND, DESCEND
- DCL-C, DCL-F (stub), DCL-DS/END-DS (QUALIFIED, DIM, DIM(*VAR), LIKEDS, OVERLAY, POS, PREFIX, EXTNAME stub)
- DCL-SUBF, DCL-PARM
- DCL-PR/END-PR, DCL-PROC/END-PROC, DCL-PI/END-PI (VALUE, return types, LIKEDS params)
- DCL-ENUM/END-ENUM (QUALIFIED), BOOLEAN data type (Test 71)
- EXPORT, IMPORT, EXTPGM, EXTPROC, NOMAIN (Tests 48/49)
- OPTIONS(*NOPASS) (Test 46), OPTIONS(*OMIT) (Test 64)

### Statements & Control Flow
- EVAL, EVAL-CORR, EVALR, DSPLY, RETURN, CALLP, LEAVESR
- IF/ELSEIF/ELSE/ENDIF, DOW/ENDDO, DOU/ENDDO
- FOR/ENDFOR (TO, DOWNTO, BY), FOR-EACH (Test 58)
- SELECT/WHEN/OTHER/ENDSL, ITER, LEAVE
- MONITOR/ON-ERROR/ENDMON, BEGSR/ENDSR/EXSR
- RESET, CLEAR, SORTA, DEALLOC
- ON-EXIT (Test 42), TEST(D/T/Z) (Test 47)
- *INZSR (Test 37), *PSSR (Test 66/67)

### Expressions & Operators
- Arithmetic: +, -, *, /, ** (exponentiation, Test 68)
- Comparison: =, <>, <, >, <=, >=
- Logical: AND, OR, NOT
- IN operator (Test 58)

### Built-In Functions
- **String:** %CHAR, %TRIM, %TRIML, %TRIMR, %LEN, %SUBST, %SCAN, %SCANR (Test 69), %SCANRPL, %XLATE, %REPLACE, %CHECK, %CHECKR, %LOWER, %UPPER, %SPLIT, %CONCATARR, %CONCAT (Test 74), %LEFT, %RIGHT, %STR, %EDITC, %EDITW
- **Numeric:** %DEC, %INT, %FLOAT, %UNS, %INTH, %DECH, %DECPOS, %SQRT, %ABS, %DIV, %REM, %EDITFLT (Test 70), %UNSH (Test 70), %PARMNUM (Test 71)
- **Array:** %ELEM, %ELEM(arr)=n (Test 72), %LOOKUP, %LOOKUPLT/GE/LE/GT (Test 52), %TLOOKUP/LT/GT/LE/GE (Test 75), %XFOOT, %SUBARR, %MAXARR, %MINARR, %LIST, %RANGE, %SIZE
- **Bitwise:** %BITAND, %BITNOT, %BITOR, %BITXOR (Test 68)
- **Date/Time:** %DATE, %TIME, %TIMESTAMP, %DIFF, %DAYS, %MONTHS, %YEARS, %HOURS, %MINUTES, %SECONDS, %MSECONDS, %SUBDT
- **Memory/Pointer:** %ALLOC, %REALLOC, %ADDR, %PADDR, %PROC, %STR
- **Other:** %PARMS, %STATUS, %ERROR, %FOUND, %EOF, %PASSED, %OMITTED, %MAX, %MIN, %GETENV (Test 85)

### %STATUS Code Values
| Code | Description | Applicable |
|------|-------------|------------|
| 0 | No error | ✅ |
| 100 | Value out of range for string operation | ✅ |
| 101 | Negative square root | ✅ |
| 102 | Divide by zero | ✅ |
| 103 | Intermediate result overflow | ✅ |
| 104 | Float underflow | ✅ |
| 112 | Invalid date/time/timestamp value | ✅ |
| 113 | Date overflow/underflow | ✅ |
| 114 | Date mapping errors | ✅ |
| 115 | Variable-length field has invalid length | ✅ |
| 120 | Table/array out of sequence | N/A (legacy) |
| 121 | Array index not valid | ✅ |
| 122 | OCCUR value not valid | N/A (legacy) |
| 202 | Called program failed | ✅ |
| 211 | Error calling program | ✅ |
| 221 | Called program not found | ✅ |
| 222 | Pointer/parameter error | ✅ |
| 231 | Called program halted | ✅ |
| 232 | Halt indicator on in called program | ✅ |
| 233 | Halt indicator on when RETURN | ✅ |
| 299 | RPG IV runtime error | ✅ |
| 301-399 | File I/O errors | N/A (using SQL) |
| 401 | Data area not found | Maybe |
| 402 | Data area type/length mismatch | Maybe |
| 411 | Data area not locked | Maybe |
| 412 | Data area lock error | Maybe |
| 413 | Error updating data area | Maybe |
| 414 | User not authorized to data area | Maybe |
| 415 | Error accessing data area | Maybe |
| 421 | Error calling DSPLY | ✅ |
| 431 | Error calling SND-MSG | N/A (IBM i) |
| 450 | Character conversion error | ✅ |
| 500 | Failure to allocate storage | ✅ |
| 802 | Failure in sort | ✅ |
| 803 | Error during dump | N/A (IBM i) |
| 804 | Error in *PSSR | ✅ |
| 907 | Decimal data error | ✅ |
| 1021-1026 | XML parser errors | N/A (IBM i) |
| 1211-1299 | XML-SAX/XML-INTO errors | N/A (IBM i) |
| 9001 | Program exception | ✅ |
| 9999 | General ILE RPG error | ✅ |

### Date/Time Formats (Test 73)
- Date: *ISO, *USA, *EUR, *JIS, *MDY, *DMY, *YMD, *JUL, *CYMD, *CMDY, *CDMY, *LONGJUL
- Time: *HMS, *ISO, *USA, *EUR, *JIS
- Timestamp: *ISO, *ISO0

### Figurative Constants
- *BLANKS, *ZEROS, *HIVAL, *LOVAL, *ON, *OFF, *NULL, *INLR, *ALL'x', *OMIT

### Indicators
- *IN01-*IN99 — Fully functional
- *INLR — Compatibility only (accepted/ignored; no RPG cycle to end)

### Compiler Directives
- /COPY, /INCLUDE, /DEFINE, /UNDEFINE, /IF DEFINED, /IF NOT DEFINED, /ELSE, /ELSEIF, /ENDIF
- /EOF, /EJECT, /SPACE, /SET, /RESTORE, /TITLE (compatibility)

### CTL-OPT (Control Options)
- NOMAIN (Test 48), MAIN(procname) (Test 56)
- DATFMT(fmt), TIMFMT(fmt) (Test 57)
- DFTACTGRP, ACTGRP, OPTION, DEBUG, DECEDIT, CCSID, TEXT, THREAD, COPYRIGHT — accepted/ignored

---

## 🔲 Remaining Work

### Still TODO

| # | Feature | Section |
|---|---------|---------|
| 1 | Operation extenders (E), (H), (N), (M), (R), (P) | Opcodes |
| 2 | DUMP opcode (debug) | Opcodes |
| 3 | ~~COMMIT / ROLBK~~ — Moved to Embedded SQL Phase 2 | Opcodes |
| 4 | IN / OUT — Data area operations | Opcodes |
| 5 | *USER — Current user profile figurative constant | Constants |
| 6 | PSDS — Program Status Data Structure | DS Keywords |
| 7 | %ELEM(*ALLOC) / %ELEM(*KEEP) — Varying array control | BIFs |
| 8 | SND-MSG / ON-EXCP — Message operations (7.5+) | Modern |
| 9 | DATA-INTO / DATA-GEN (%DATA, %GEN, %PARSER) | Modern |
| 10 | OVERLOAD — Overloaded procedures (7.4+) | Modern |
| 11 | Data area operations (IN/OUT/UNLOCK, DTAARA, *LDA/*GDA/*PDA) | Data Areas |
| 12 | %DATA, %GEN, %PARSER, %HANDLER, %XML, %MSG, %TARGET — Companion BIFs | BIFs |
| 13 | RPG status codes (full %STATUS value set) | Error Handling |

### ~~File I/O~~ — Not Planned (using SQL as data access path instead)
~~Full DCL-F, CHAIN, READ, WRITE, UPDATE, DELETE, SETLL, SETGT, record formats, INFSR~~

### Embedded SQL (via ODBC)

#### Phase 1 — Foundation ✅
| # | Feature | Details |
|---|---------|---------|
| 18 | ✅ EXEC SQL parsing | Lexer `<SQL>` start condition, captures raw SQL until `;` as `EXEC_SQL_TEXT` token |
| 19 | ✅ Host variables | Extract `:varName` references, replace with `?` parameter markers |
| 20 | ✅ ExecSqlStmt AST node | Single node with `SqlStmtKind` enum (avoids 15+ separate node classes) |
| 21 | ✅ SQL utility functions | `src/sql_utils.h/.cpp` — `extractHostVariables()`, `replaceHostVarsWithMarkers()`, `classifySqlStmt()` |
| 22 | ✅ ODBC runtime wrapper | `runtime/rpg_sql_runtime.h` — `RpgSqlEnv` class (connection, cursor, prepared stmt management) |

#### Phase 2 — Core SQL Statements ✅
| # | Feature | RPG Syntax | ODBC Mapping |
|---|---------|-----------|-------------|
| 23 | ✅ SELECT INTO | `EXEC SQL SELECT col INTO :var FROM tbl WHERE ...;` | `SQLPrepare` + `SQLBindCol` + `SQLExecute` + `SQLFetch` |
| 24 | ✅ INSERT | `EXEC SQL INSERT INTO tbl VALUES(:v1, :v2);` | `SQLPrepare` + `SQLBindParameter` + `SQLExecute` |
| 25 | ✅ UPDATE | `EXEC SQL UPDATE tbl SET col = :v WHERE ...;` | Same as INSERT |
| 26 | ✅ DELETE | `EXEC SQL DELETE FROM tbl WHERE ...;` | Same as INSERT |
| 27 | ✅ COMMIT | `EXEC SQL COMMIT;` | `SQLEndTran(SQL_COMMIT)` |
| 28 | ✅ ROLLBACK | `EXEC SQL ROLLBACK;` | `SQLEndTran(SQL_ROLLBACK)` |
| 29 | ✅ SQLCODE / SQLSTATE | `SQLCOD` / `SQLSTT` variables | `SQLGetDiagRec` → `__sql_env.sqlcode` / `.sqlstate` |

#### Phase 3 — Cursor Operations ✅
| # | Feature | RPG Syntax | ODBC Mapping |
|---|---------|-----------|-------------|
| 30 | ✅ DECLARE CURSOR | `EXEC SQL DECLARE C1 CURSOR FOR SELECT ...;` | `SQLPrepare` (store handle in cursor map) |
| 31 | ✅ OPEN | `EXEC SQL OPEN C1;` | `SQLExecute` on cursor's stmt handle |
| 32 | ✅ FETCH | `EXEC SQL FETCH C1 INTO :v1, :v2;` | `SQLBindCol` + `SQLFetch` |
| 33 | ✅ CLOSE | `EXEC SQL CLOSE C1;` | `SQLFreeStmt(SQL_CLOSE)` |

#### Phase 4 — Connection Management ✅
| # | Feature | RPG Syntax | ODBC Mapping |
|---|---------|-----------|-------------|
| 34 | ✅ CONNECT | `EXEC SQL CONNECT TO :dsn USER :u USING :p;` | `SQLConnect` |
| 34a | ✅ CONNECT (conn string) | `EXEC SQL CONNECT USING :connStr;` | `SQLDriverConnect` |
| 34b | ✅ CONNECT RESET | `EXEC SQL CONNECT RESET;` | `SQLDisconnect` |
| 35 | ✅ DISCONNECT | `EXEC SQL DISCONNECT;` | `SQLDisconnect` |
| 36 | — SET CONNECTION | Not supported (single connection per program) | — |

#### Phase 5 — Dynamic SQL ✅
| # | Feature | RPG Syntax | ODBC Mapping |
|---|---------|-----------|-------------|
| 37 | ✅ PREPARE | `EXEC SQL PREPARE S1 FROM :sqlStr;` | `SQLPrepare` (store handle) |
| 38 | ✅ EXECUTE | `EXEC SQL EXECUTE S1 USING :v1, :v2;` | `SQLBindParameter` + `SQLExecute` |
| 39 | ✅ EXECUTE IMMEDIATE | `EXEC SQL EXECUTE IMMEDIATE :sqlStr;` | `SQLExecDirect` |

#### Phase 6 — Advanced Features ✅
| # | Feature | RPG Syntax | ODBC Mapping |
|---|---------|-----------|-------------|
| 40 | Indicator variables | `:var :ind` | `SQLLEN` indicator in bind calls |
| 41 | ✅ GET DIAGNOSTICS | `EXEC SQL GET DIAGNOSTICS :rc = ROW_COUNT;` | `SQLGetDiagRec` / `SQLGetDiagField` |
| 42 | ✅ CALL procedures | `EXEC SQL CALL proc(:p1, :p2);` | `SQLPrepare("{CALL proc(?,?)}")` + bind |
| 43 | ✅ SAVEPOINT | `EXEC SQL SAVEPOINT sp1;` | SQL passthrough (driver-dependent) |
| 44 | ✅ Multiple-row FETCH | `FETCH ... FOR :n ROWS` | Loop with `SQLFetch` into array elements |
| 45 | ✅ Multiple-row INSERT | `INSERT ... FOR :n ROWS` | Loop with `SQLExecute` per array element |

#### Architecture Notes
- **Lexer**: `EXEC SQL` triggers exclusive start condition `<SQL>`, captures until `;`
- **Parser**: Single `exec_sql_stmt` rule; classification via utility function (not a full SQL parser)
- **AST**: Single `ExecSqlStmt` node with `SqlStmtKind` enum
- **Runtime**: Separate `rpg_sql_runtime.h` (programs without SQL don't need ODBC)
- **Linking**: `-lodbc` added only when SQL is used (codegen sets `uses_sql_` flag)
- **SELECT INTO**: `INTO :var1, :var2` clause stripped from SQL sent to ODBC (uses `SQLBindCol` instead)

### Modern/Stretch

| # | Feature |
|---|---------|
| 46 | XML-SAX, XML-INTO (%XML, %HANDLER) |
| 47 | Remaining CTL-OPT keywords (USRPRF, VALIDATE) |

---

## ❌ Not Planned

These features are IBM i-specific, legacy, or otherwise not applicable:

### Embedded SQL — Not Planned
- SQLTYPE (CLOB, BLOB, XML) — LOB support varies wildly by ODBC driver
- SQLDA (Descriptor Area) — Complex, rarely used, requires dynamic memory allocation
- WHENEVER — Legacy error handling; programs should check SQLCODE directly
- SET OPTION — IBM i compilation directive, no C++ equivalent
- DESCRIBE — Requires SQLDA support
- DBCLOB — Double-byte, IBM i specific
- XML variants (XML_BLOB, XML_CLOB) — IBM i specific

### IBM i-Specific
- %GRAPH, %UCS2, %SHTDN — IBM i encoding/shutdown
- CCSID — Character set conversion IDs
- FROMFILE/TOFILE — Compile-time array file keywords
- SERIALIZE — Serialized procedure access (job locking)
- ACTGRP semantics — Activation group (parsed for compatibility)
- INFDS — File Information Data Structure
- LIKEREC, LIKEFILE, EXTNAME options (*ALL/*INPUT/*OUTPUT/*KEY)
- ALIGN — Subfield alignment (C++ handles natively)
- LEN(n) — Explicit DS length
- NULLIND — Null indicator association
- OPDESC — Operational descriptors
- RTNPARM, NOOPT — Procedure/variable keywords
- %OPEN, %KDS, %FIELDS, %EQUAL, %NULLIND — File/Record BIFs
- BNDDIR — Binding directory
- STGMDL, ALLOC(*TERASPACE) — Storage model
- Open Access / Handler programs
- *ENTRY — Entry point parameter list
- %THIS — Java object reference

### CTL-OPT Keywords (all accepted/ignored, no implementation)
- ALWNULL, ALTSEQ, AUT, CHARCOUNT, COPYNEST, CURSYM, DATEDIT, DECPREC
- DFTNAME, ENBPFRCOL, EXPROPTS, EXTBININT, FIXNBR, FLTDIV, FORMSALIGN
- GENLVL, INDENT, INTPREC, LANGID, OPTIMIZE, OPENOPT, PRFDTA, REQPREXP
- SRTSEQ, TGTCCSID, TGTRLS, TRUNCNBR

### Declaration Keywords
- OPTIONS(*VARSIZE/*STRING/*TRIM/*RIGHTADJ/*CONVERT/*EXACT)
- VARYING, CCSID(n), DTAARA, PERRCD, EXTFMT

### Legacy / Fixed-Format
- RPG cycle processing (detail calc, total calc, LR indicator)
- CTDATA, ALT(array), OCCURS/%OCCUR
- /FREE, /END-FREE
- All fixed-format opcodes (ADD, SUB, MULT, DIV, MOVE, COMP, GOTO, TAG, CALL, PARM, PLIST, etc.)

### Indicator Types (beyond *IN01-*IN99, *INLR)
- *INKx, *INHx, *INOx, *INLx, *INUx, *INRT, *INMR, *IN array

---

## Test Index

| Test | Description |
|------|-------------|
| 01 | Hello World |
| 02 | Arithmetic |
| 03 | Types |
| 04 | BIFs |
| 05 | IF |
| 06 | Loops |
| 07 | Select |
| 08 | Procedures |
| 09 | Data Structures |
| 10 | Expanded BIFs |
| 11 | Error Reporting |
| 12 | Monitor |
| 13 | Subroutines |
| 14 | Indicators |
| 15 | DOU Loop |
| 16 | /COPY Include |
| 17 | Named Constants |
| 18 | Date/Time |
| 19 | Math BIFs |
| 20 | Memory BIFs |
| 21 | %PARMS |
| 22 | %STATUS/%ERROR |
| 23 | RESET/CLEAR |
| 24 | %MAX/%MIN |
| 25 | DCL-F |
| 26 | Pointers |
| 27 | Arrays |
| 28 | Conditional Compilation |
| 29 | DCL-SUBF/DCL-PARM |
| 30 | LIKE |
| 31 | LOOKUP and SORTA |
| 32 | EDITC/EDITW |
| 33 | REPLACE |
| 34 | CHECK/CHECKR |
| 35 | EVAL-CORR |
| 36 | DS Params |
| 37 | *INZSR |
| 38 | CTL-OPT |
| 39 | Figurative Constants |
| 40 | EVALR/LEAVESR |
| 41 | String/Math BIFs |
| 42 | ON-EXIT |
| 43 | STATIC |
| 44 | ALLOC/DEALLOC |
| 45 | Array BIFs |
| 46 | OPTIONS(*NOPASS) |
| 47 | TEST Opcode |
| 48 | NOMAIN Module |
| 49 | EXTPROC/IMPORT |
| 50 | Numeric BIFs |
| 51 | String BIFs |
| 52 | Array BIFs |
| 53 | Date/Time BIFs |
| 54 | Memory/Pointer BIFs |
| 55 | Figurative Constants |
| 56 | MAIN(procname) |
| 57 | DATFMT/TIMFMT |
| 58 | FOR-EACH and IN |
| 59 | %PASSED/%OMITTED |
| 60 | Data Types |
| 61 | No **FREE |
| 62 | OVERLAY/POS |
| 63 | PREFIX |
| 64 | OPTIONS(*OMIT) |
| 65 | DFTACTGRP/ACTGRP |
| 66 | *PSSR |
| 67 | *PSSR Error |
| 68 | Bitwise & Power |
| 69 | %SCANR |
| 70 | %EDITFLT & %UNSH |
| 71 | Enum & Boolean |
| 72 | DIM(*VAR) |
| 73 | Date Formats |
| 74 | %CONCAT |
| 75 | %TLOOKUP & %ELEM |
| 76 | DS DIM(*VAR) |
| 77 | Embedded SQL |
| 78 | SQL in Procedures |
| 79 | SQL Core Statements |
| 80 | SQL Cursors |
| 81 | Dynamic SQL |
| 82 | SQL Advanced |
| 83 | SQL Multi-row |
| 84 | SQL Connect |
| 85 | %GETENV |
