# RPG IV Free-Format Feature Tracker

## ✅ Already Implemented
- **FREE, DCL-S (CHAR, VARCHAR, INT, PACKED, ZONED, IND, DATE, TIME, TIMESTAMP, POINTER, DIM, LIKE, INZ, CONST, STATIC, TEMPLATE)
- DCL-C, DCL-F (stub), DCL-DS/END-DS (QUALIFIED, DIM, LIKEDS), DCL-SUBF, DCL-PARM
- DCL-PR/END-PR, DCL-PROC/END-PROC, DCL-PI/END-PI (VALUE, return types, LIKEDS params, OPTIONS(*NOPASS))
- EVAL, EVAL-CORR, EVALR, DSPLY, RETURN, CALLP, LEAVESR
- IF/ELSEIF/ELSE/ENDIF, DOW/ENDDO, DOU/ENDDO
- FOR/ENDFOR (TO, DOWNTO, BY), SELECT/WHEN/OTHER/ENDSL, ITER, LEAVE
- MONITOR/ON-ERROR/ENDMON, BEGSR/ENDSR/EXSR, RESET, CLEAR, SORTA
- ON-EXIT (procedure cleanup)
- TEST(D/T/Z) — date/time/timestamp validation
- DEALLOC — deallocate heap storage
- Expressions: +, -, *, /, =, <>, <, >, <=, >=, AND, OR, NOT
- BIFs: %CHAR, %TRIM, %TRIML, %TRIMR, %LEN, %SUBST, %SCAN, %SCANRPL, %XLATE, %DEC, %INT, %ELEM, %MAX, %MIN, %ABS, %DIV, %REM, %SIZE, %ADDR, %PARMS, %STATUS, %ERROR, %FOUND, %EOF, %LOOKUP, %EDITC, %EDITW, %REPLACE, %CHECK, %CHECKR, %DATE, %TIME, %TIMESTAMP, %DIFF, %DAYS, %MONTHS, %YEARS, %LOWER, %UPPER, %SUBDT, %FLOAT, %SQRT, %ALLOC, %REALLOC, %XFOOT, %UNS, %INTH, %DECH, %DECPOS, %SPLIT, %CONCATARR, %LEFT, %RIGHT, %STR, %SUBARR, %MAXARR, %MINARR, %LIST, %RANGE, %LOOKUPLT, %LOOKUPGE, %LOOKUPLE, %LOOKUPGT, %HOURS, %MINUTES, %SECONDS, %MSECONDS, %PADDR, %PROC, %PASSED, %OMITTED
- Indicators (*IN01-*IN99), /COPY, /INCLUDE
- Conditional compilation: /DEFINE, /UNDEFINE, /IF DEFINED, /IF NOT DEFINED, /ELSE, /ENDIF
- Figurative constants: *BLANKS, *ZEROS, *HIVAL, *LOVAL, *ON, *OFF, *NULL, *INLR, *ALL'x'
- Date/time arithmetic, *INZSR, *PSSR, CTL-OPT (consumed)
- FOR-EACH, IN operator, BASED, ASCEND/DESCEND, UNS, FLOAT, BINDEC, UCS2/GRAPH, OBJECT
- Compiler directives: /EOF, /EJECT, /SPACE, /SET, /RESTORE, /ELSEIF

---

## 🔴 Major Features (Core Language)

### 1. CTL-OPT (Control Options)
- ~~`NOMAIN` — No main procedure (service program module)~~ ✅ (Test 48)
- ~~`MAIN(procname)` — Named main procedure~~ ✅ (Test 56)
- ~~`DFTACTGRP(*NO)` — Default activation group~~ ✅ (accepted, ignored)
- ~~`ACTGRP(name)` — Activation group~~ ✅ (accepted, ignored)
- ~~`BNDDIR(name)` — Binding directory~~ ❌ Not Planned
- ~~`DATFMT(fmt)` / `TIMFMT(fmt)` — Default date/time formats~~ ✅ (Test 57)
- ~~`OPTION(...)` — Compiler options~~ ✅ (accepted, ignored)
- ~~`DEBUG`, `DECEDIT`, `CCSID`, `TEXT`, `THREAD`, etc.~~ ✅ (accepted, ignored)
- ~~`ALLOC(*TERASPACE | *STGMDL)` — Allocation type~~ ❌ Not Planned
- ~~`ALWNULL(*NO | *INPUTONLY | *USRCTL)` — Allow null-capable fields~~ ❌ Not Planned
- ~~`ALTSEQ(*NONE | *SRC | *EXT)` — Alternative collating sequence~~ ❌ Not Planned
- ~~`AUT(*LIBRCRTAUT | *ALL | *CHANGE | *USE | *EXCLUDE)` — Object authority~~ ❌ Not Planned
- ~~`CHARCOUNT(*NATURAL | *THREEBYTEUNI)` — Character counting~~ ❌ Not Planned
- ~~`CCSID(*CHAR:n)` / `CCSID(*GRAPH:n)` / `CCSID(*UCS2:n)` — Character set IDs~~ ❌ Not Planned
- ~~`COPYNEST(n)` — Maximum /COPY nesting (default 32, max 2048)~~ ❌ Not Planned
- ~~`COPYRIGHT('string')` — Copyright string embedded in object~~ ✅ (parsed for compatibility, no functionality)
- ~~`CURSYM('sym')` — Currency symbol~~ ❌ Not Planned
- ~~`DATEDIT(fmt{separator})` — Date edit format for UDATE~~ ❌ Not Planned
- ~~`DECPREC(30 | 31 | 63)` — Decimal precision~~ ❌ Not Planned
- ~~`DFTNAME(name)` — Default program name~~ ❌ Not Planned
- ~~`ENBPFRCOL(*PEP | *ENTRYEXIT | *FULL)` — Enable performance collection~~ ❌ Not Planned
- ~~`EXPROPTS(*MAXDIGITS | *RESDECPOS)` — Expression options~~ ❌ Not Planned
- ~~`EXTBININT(*NO | *YES)` — External binary integer treatment~~ ❌ Not Planned
- ~~`FIXNBR(*{NO}ZONED | *{NO}INPUTPACKED)` — Fix numeric~~ ❌ Not Planned
- ~~`FLTDIV(*NO | *YES)` — Float division~~ ❌ Not Planned
- ~~`FORMSALIGN(*NO | *YES)` — Forms alignment~~ ❌ Not Planned
- ~~`GENLVL(n)` — Generation severity level~~ ❌ Not Planned
- ~~`INDENT` — Indent listing~~ ❌ Not Planned
- ~~`INTPREC(10 | 20)` — Integer precision~~ ❌ Not Planned
- ~~`LANGID` — Language identifier~~ ❌ Not Planned
- ~~`OPTIMIZE(*NONE | *BASIC | *FULL)` — Optimization level~~ ❌ Not Planned
- ~~`OPENOPT(*INZOFL | *NOINZOFL)` — Open options~~ ❌ Not Planned
- ~~`PRFDTA(*NOCOL | *COL)` — Profiling data~~ ❌ Not Planned
- ~~`REQPREXP(*NO | *WARN | *REQUIRE)` — Require prototype for exported procs (7.4+)~~ ❌ Not Planned
- ~~`SRTSEQ(*HEX | *JOB | *JOBRUN | *LANGIDUNQ | *LANGIDSHR)` — Sort sequence~~ ❌ Not Planned
- ~~`STGMDL(*INHERIT | *SNGLVL | *TERASPACE)` — Storage model~~ ❌ Not Planned
- ~~`TGTCCSID(n)` — Target CCSID~~ ❌ Not Planned
- ~~`TGTRLS(release)` — Target release~~ ❌ Not Planned
- ~~`TRUNCNBR(*YES | *NO)` — Truncate numeric~~ ❌ Not Planned
- `USRPRF(*USER | *OWNER)` — User profile
- `VALIDATE(*NODATETIME)` — Validate parameters

### 2. File I/O Operations
- `CHAIN` — Random read by key/RRN
- `READ` / `READE` / `READP` / `READPE` / `READC` — Sequential reads
- `WRITE` — Write record
- `UPDATE` — Update record
- `DELETE` — Delete record
- `SETLL` / `SETGT` — Position file cursor
- `OPEN` / `CLOSE` — Manual file open/close
- `UNLOCK` — Unlock record
- `FEOD` — Force end of data
- `EXFMT` — Write/read workstation format
- `EXCEPT` — Exception output
- DCL-F keywords (core): KEYED, USAGE, USROPN, QUALIFIED, EXTFILE, RENAME, PREFIX, SFILE, INFDS, INFSR, BLOCK, COMMIT
- DCL-F keywords (additional):
  - `DISK` / `PRINTER` / `WORKSTN` / `SPECIAL` — File device types
  - `EXTDESC(filename)` — Compile-time external description
  - `EXTMBR(member)` — External member name
  - `MAXDEV(*FILE | *ONLY)` — Max devices for WORKSTN
  - `OFLIND(indicator)` — Overflow indicator for PRINTER
  - `TEMPLATE` — Template file definition
  - `LIKEFILE(filename)` — Define file like another file
  - `STATIC` — Static file in procedure
  - `HANDLER(proc{:commarea})` — Open Access handler
  - `PGMNAME(name)` — Program name for SPECIAL files
  - `PRTCTL(ds)` — Printer control DS
  - `IGNORE(recfmt1:recfmt2:...)` — Ignore record formats
  - `INCLUDE(recfmt1:recfmt2:...)` — Include only specific record formats
  - `INDDS(dsname)` — Indicator data structure
  - `RECNO(field)` — Relative record number field
  - `EXTIND(*INUx)` — External indicator
  - `PASS(*NOIND)` — Pass indicators
  - `DEVID(field)` — Device identifier field
  - `SAVEIND(n)` — Save indicator area
  - `FORMLEN(n)` / `FORMOFL(n)` — Form length/overflow

### 3. Embedded SQL
- `EXEC SQL ... ;` block parsing
- Host variables (`:variablename`)
- Cursors: DECLARE, OPEN, FETCH, CLOSE
- SELECT INTO, INSERT, UPDATE, DELETE
- SQLSTATE / SQLCODE special variables
- SET OPTION, PREPARE, EXECUTE
- `WHENEVER` — Conditional SQL action (SQLERROR / SQLWARNING / NOT FOUND)
- `CALL` — Call stored procedure
- `GET DIAGNOSTICS` — Retrieve diagnostic information
- `SIGNAL` — Signal SQL condition
- `SET RESULT SETS` — Return result sets from procedure
- `INCLUDE` — Include SQL structures (SQLCA, SQLDA)
- `BEGIN / END DECLARE SECTION` — Host variable declaration section
- `CONNECT` / `DISCONNECT` / `SET CONNECTION` — Connection management
- `COMMIT` / `ROLLBACK` — SQL transaction control
- `ALLOCATE / DEALLOCATE CURSOR` — Cursor management for result sets
- `ASSOCIATE LOCATOR(s)` — Associate result set locators
- `VALUES INTO` — Retrieve expression values
- `FOR n ROWS` — Multi-row fetch/insert
- `SQLCA` — SQL Communication Area structure
- `SQLDA` — SQL Descriptor Area structure

### 4. Service Programs / Modules
- ~~`EXPORT` keyword on DCL-PROC and DCL-S~~ ✅
- ~~`IMPORT` keyword on DCL-S~~ ✅
- ~~`NOMAIN` module support~~ ✅
- ~~`EXTPGM(name)` on DCL-PR — program calls~~ ✅
- ~~`EXTPROC(name)` on DCL-PR — external procedure binding~~ ✅
- Binding directories
- `STGMDL(*INHERIT | *SNGLVL | *TERASPACE)` — Storage model
- Binding source / binder language (STRPGMEXP/ENDPGMEXP)
- ~~`ACTGRP(*NEW | *CALLER | name)` — Activation group semantics~~ ✅ (parsed for compatibility, no functionality) ❌ Not Planned

---

## 🟡 Medium Features (Commonly Used)

### 5. Special Subroutines
- ~~`*INZSR` — Initialization subroutine~~ ✅ (Test 37)
- ~~`*PSSR` — Program error/exception subroutine~~ ✅ (Test 66)
- File-level `INFSR` — File error subroutine

### 6. ON-EXIT Block
- ~~Cleanup code that always runs when procedure ends (normal or abnormal)~~ ✅ (Test 42)

### 7. Missing Operation Codes
- ~~`CALLP` — Explicit call prototyped procedure~~ ✅ (Test 40)
- ~~`EVALR` — Evaluate with right-adjust~~ ✅ (Test 40)
- ~~`LEAVESR` — Leave subroutine~~ ✅ (Test 40)
- ~~`TEST` — Test date/time/timestamp validity~~ ✅ (Test 47)
- ~~`DEALLOC` — Deallocate heap storage~~ ✅ (Test 44)
- `DUMP` — Program dump (debug)
- ~~`FORCE` / `NEXT` / `POST` — Device operations~~ ❌ Not Planned
- ~~`ACQ` / `REL` — Acquire/release program device~~ ❌ Not Planned
- `COMMIT` / `ROLBK` — Commitment control
- `IN` / `OUT` — Data area operations
- ~~`SHTDN` — Check for job shutdown request~~ ❌ Not Planned

### 8. Missing BIFs — Numeric
- ~~`%FLOAT(expr)` — Convert to float~~ ✅ (Test 41)
- ~~`%UNS(expr)` — Convert to unsigned integer~~ ✅ (Test 50)
- ~~`%INTH(expr)` — Integer with half-adjust (rounding)~~ ✅ (Test 50)
- ~~`%DECH(expr:d:p)` — Decimal with half-adjust~~ ✅ (Test 50)
- ~~`%DECPOS(num)` — Number of decimal positions~~ ✅ (Test 50)
- ~~`%SQRT(n)` — Square root~~ ✅ (Test 41)
- ~~`%EDITFLT(expr)` — External float representation~~ ✅ (Test 70)
- ~~`%UNSH(expr)` — Unsigned integer with half-adjust~~ ✅ (Test 70)

### 9. Missing BIFs — String
- ~~`%LOWER(string)` — Convert to lowercase~~ ✅ (Test 41)
- ~~`%UPPER(string)` — Convert to uppercase~~ ✅ (Test 41)
- ~~`%SPLIT(string[:sep])` — Split into array (7.4+)~~ ✅ (Test 51)
- ~~`%CONCATARR(array:sep)` — Join array elements (7.5+)~~ ✅ (Test 51)
- ~~`%LEFT(string:len)` — Left substring (7.6+)~~ ✅ (Test 51)
- ~~`%RIGHT(string:len)` — Right substring (7.6+)~~ ✅ (Test 51)
- ~~`%STR(ptr[:len])` — Null-terminated string from pointer~~ ✅ (Test 51)
- ~~`%SCANR(search:source{:start})` — Scan reverse / right to left (7.3+)~~ ✅ (Test 69)
- ~~`%CONCAT(sep:val1:val2:...)` — Concatenate with separator (7.5+)~~ ✅ (Test 74)

### 10. Missing BIFs — Array
- ~~`%SUBARR(array:start[:count])` — Sub-array reference~~ ✅ (Test 52)
- ~~`%XFOOT(array)` — Sum all array elements~~ ✅ (Test 45)
- ~~`%MAXARR(array)` — Index of maximum value (7.4+)~~ ✅ (Test 52)
- ~~`%MINARR(array)` — Index of minimum value (7.4+)~~ ✅ (Test 52)
- ~~`%LIST(val1:val2:...)` — Temporary array literal (7.4+)~~ ✅ (Test 52)
- ~~`%RANGE(low:high)` — Value range (7.4+)~~ ✅ (Test 52)
- ~~`%LOOKUPLT / %LOOKUPGE / %LOOKUPLE / %LOOKUPGT` — Array search variants~~ ✅ (Test 52)
- ~~`%TLOOKUP(arg:table{:alttable})` — Table lookup~~ ✅ (Test 75)
- ~~`%TLOOKUPLT / %TLOOKUPGT / %TLOOKUPLE / %TLOOKUPGE` — Table lookup variants~~ ✅ (Test 75)
- ~~`%ELEM(array) = n` — Set array dimension (left-hand, 7.4+)~~ ✅ (Test 72)
- `%ELEM(*ALLOC)` / `%ELEM(*KEEP)` — Varying array element control (7.4+)

### 11. Missing BIFs — Date/Time
- ~~`%SUBDT(date:*YEARS|*MONTHS|etc.)` — Extract part of date/time~~ ✅ (Test 41)
- ~~`%HOURS(n)` / `%MINUTES(n)` / `%SECONDS(n)` / `%MSECONDS(n)` — Duration units~~ ✅ (Test 53)

### 12. Missing BIFs — Memory/Pointer
- ~~`%ALLOC(n)` — Allocate heap storage~~ ✅ (Test 44)
- ~~`%REALLOC(ptr:n)` — Reallocate storage~~ ✅ (Test 44)
- ~~`%PADDR(procname)` — Procedure address (procedure pointer)~~ ✅ (Test 54)
- ~~`%PROC` — Current procedure name~~ ✅ (Test 54)

### 13. Missing BIFs — File/Record
- `%OPEN(filename)` — Check if file is open
- `%KDS(ds[:numkeys])` — DS as composite key
- `%FIELDS(fld1:fld2:...)` — Fields to update
- `%EQUAL` — Equal key found (after SETLL)
- `%NULLIND(field)` — Null indicator

### 14. Missing BIFs — Bitwise ✅
- ~~`%BITAND(expr1:expr2)` — Bitwise AND~~ ✅ (Test 68)
- ~~`%BITNOT(expr)` — Bitwise NOT (complement)~~ ✅ (Test 68)
- ~~`%BITOR(expr1:expr2)` — Bitwise OR~~ ✅ (Test 68)
- ~~`%BITXOR(expr1:expr2)` — Bitwise XOR~~ ✅ (Test 68)

### 15. Missing BIFs — Conversion/Formatting
- ~~`%GRAPH(expr{:ccsid})` — Convert to graphic (DBCS)~~ ❌ Not Planned
- ~~`%UCS2(expr{:ccsid})` — Convert to UCS-2~~ ❌ Not Planned
- ~~`%PARMNUM(parmname)` — Get parameter position number (7.3+)~~ ✅ (Test 71)
- ~~`%SHTDN` — Check for shutdown request~~ ❌ Not Planned

### 16. Missing BIFs — DATA-INTO/DATA-GEN/XML Companions
- `%DATA(document{:options})` — Data source for DATA-INTO/DATA-GEN
- `%GEN(name{:options})` — Generator for DATA-GEN
- `%PARSER(name{:options})` — Parser for DATA-INTO
- `%HANDLER(proc:commarea)` — Handler for XML-SAX/DATA-INTO
- `%XML(doc{:options})` — XML document for XML-INTO
- `%MSG(msgid:msgfile{:repdata})` — Message for SND-MSG (7.5+)
- `%TARGET(invocation{:*CALLER})` — Target for SND-MSG (7.5+)
- ~~`%THIS` — Reference to current Java object instance~~ ❌ Not Planned

### 17. Figurative Constants
- ~~`*BLANK` / `*BLANKS` — Blank value~~ ✅ (Test 39)
- ~~`*ZERO` / `*ZEROS` — Zero value~~ ✅ (Test 39)
- ~~`*HIVAL` — Highest value for type~~ ✅ (Test 39)
- ~~`*LOVAL` — Lowest value for type~~ ✅ (Test 39)
- ~~`*ALL'x'` — Fill with repeated character(s)~~ ✅ (Test 55)
- ~~`*OMIT` — Omit optional parameter~~ ✅ (Test 64)
- ~~`*ENTRY` — Entry point parameter list~~ ❌ Not Planned
- `*USER` — Current user profile name

### 18. Declaration Keywords Missing
- ~~`TEMPLATE` — Template only (no storage, for LIKE/LIKEDS reference)~~ ✅ (Test 43)
- ~~`BASED(pointer)` — Based variable at pointer location~~ ✅
- ~~`STATIC` — Static storage in procedure (retains across calls)~~ ✅ (Test 43)
- ~~`EXTNAME(filename)` — Externally described DS from DB file~~ ✅ (stub)
- ~~`OVERLAY(field[:pos])` — Overlay fields in DS~~ ✅ (Test 62)
- ~~`POS(n)` — Position within DS~~ ✅ (Test 62)
- ~~`PREFIX(pfx[:n])` — Prefix field names~~ ✅ (Test 63)
- ~~`DATFMT(fmt)` / `TIMFMT(fmt)` — Date/time format on fields~~ ✅
- ~~`OPTIONS(*NOPASS)` — Optional parameter~~ ✅ (Test 46)
- ~~`OPTIONS(*OMIT)` — Omittable parameter~~ ✅ (Test 64)
- ~~`OPTIONS(*VARSIZE)` — Variable-size parameter~~ ❌ Not Planned
- ~~`OPTIONS(*STRING)` — Allow string literal for pointer parameter~~ ❌ Not Planned
- ~~`OPTIONS(*TRIM)` — Trim blanks from parameter~~ ❌ Not Planned
- ~~`OPTIONS(*RIGHTADJ)` — Right-adjust parameter~~ ❌ Not Planned
- ~~`OPTIONS(*CONVERT)` — Auto-convert parameter to string (7.5+)~~ ❌ Not Planned
- ~~`OPTIONS(*EXACT)` — Exact type matching (7.4+)~~ ❌ Not Planned
- ~~`RTNPARM` — Return value as hidden parameter~~ ❌ Not Planned
- ~~`OPDESC` — Operational descriptors~~ ❌ Not Planned
- ~~`ASCEND` / `DESCEND` — Array sort order~~ ✅
- ~~`NULLIND(field)` — Null indicator association~~ ❌ Not Planned
- ~~`VARYING` — Alternative to VARCHAR on standalone variables~~ ❌ Not Planned
- ~~`CCSID(n)` — CCSID for character/graphic fields~~ ❌ Not Planned
- ~~`NOOPT` — Prevent optimizer from optimizing variable~~ ❌ Not Planned
- ~~`DTAARA{(*VAR:fieldname)}` — Associate variable/DS with data area~~ ❌ Not Planned
- ~~`FROMFILE(filename)` / `TOFILE(filename)` — Pre-runtime array I/O~~ ❌ Not Planned
- ~~`PERRCD(n)` — Elements per record for compile-time arrays~~ ❌ Not Planned
- ~~`EXTFMT` — External format for externally described fields~~ ❌ Not Planned
- ~~`SERIALIZE` — Serialize procedure for thread safety~~ ❌ Not Planned

### 19. DCL-DS Keywords Missing
- ~~`LIKEREC(recfmt{:*ALL | *INPUT | *OUTPUT | *KEY})` — DS like record format~~ ❌ Not Planned
- ~~`ALIGN` — Align subfields on natural boundaries~~ ❌ Not Planned
- ~~`LEN(n)` — Explicit DS length~~ ❌ Not Planned
- `PSDS` — Program Status Data Structure keyword
- ~~`EXTNAME with *ALL | *INPUT | *OUTPUT | *KEY` — Record format extraction options~~ ❌ Not Planned
- ~~`DIM(*AUTO:max)` — Auto-sizing varying dimension arrays (7.4+)~~ ✅ (Test 72/76)
- ~~`DIM(*VAR:max)` — Variable dimension arrays (7.4+)~~ ✅ (Test 72/76)

### 20. Expression Operators Missing ✅
- ~~`**` — Exponentiation operator~~ ✅ (Test 68)

---

## 🟢 Minor / Stretch Features

### 21. Newer Language Features (IBM i 7.3+)
- ~~`FOR-EACH` / `ENDFOR` — Iterate over arrays / %LIST~~ ✅ (Test 58)
- `SND-MSG` — Send message to job log (7.5+)
- `ON-EXCP` — Monitor for specific escape message (7.5+)
- `DATA-INTO` — Parse JSON/CSV/etc. into RPG variables
- `DATA-GEN` — Generate structured output from RPG variables
- ~~`IN` operator — `IF x IN %LIST(...)` or `IF x IN %RANGE(...)`~~ ✅ (Test 58)
- ~~`%PASSED(parm)` / `%OMITTED(parm)` — Optional parameter checks (7.5+)~~ ✅ (Test 59)
- `OVERLOAD(proc1:proc2:...)` — Overloaded procedures (7.4+)
- ~~`DCL-ENUM` / `END-ENUM` — Enumeration type definition (7.5 TR3 / 7.4 TR9)~~ ✅ (Test 71)
- ~~`BOOLEAN` data type (7.5 TR3 / 7.4 TR9, treated as indicator)~~ ✅ (Test 71)

### 22. XML Support
- `XML-SAX` — SAX-based XML parsing
- `XML-INTO` — Parse XML into RPG variables
- `%XML(doc:options)` / `%HANDLER(proc:commarea)`

### 23. Data Types Missing
- ~~`UNS(n)` — Unsigned integer (3, 5, 10, 20)~~ ✅ (Test 60)
- ~~`FLOAT(4|8)` — IEEE floating point~~ ✅ (Test 60)
- ~~`BINDEC(n)` — Binary decimal (legacy)~~ ✅ (Test 60)
- ~~`UCS2(n)` / `GRAPH(n)` — Unicode/DBCS~~ ✅
- ~~`OBJECT(*JAVA:class)` — Java object reference~~ ✅
- ~~Multiple-occurrence DS (`OCCURS`, `%OCCUR`)~~ ❌ (Not planned — use DIM/arrays)
- `VARUCS2(n)` — Varying-length UCS-2
- `VARGRAPH(n)` — Varying-length graphic
- `SQLTYPE(CLOB:n)` — Character large object
- `SQLTYPE(BLOB:n)` — Binary large object
- `SQLTYPE(DBCLOB:n)` — Double-byte character large object
- `SQLTYPE(XML_CLOB:n)` / `SQLTYPE(XML_DBCLOB:n)` / `SQLTYPE(XML_BLOB:n)` — XML types
- `SQLTYPE(BINARY:n)` / `SQLTYPE(VARBINARY:n)` — Binary data types
- `SQLTYPE(ROWID)` — Row identifier
- `SQLTYPE(RESULT_SET_LOCATOR)` — Result set locator
- `SQLTYPE(CLOB_LOCATOR)` / `SQLTYPE(BLOB_LOCATOR)` / `SQLTYPE(DBCLOB_LOCATOR)` — LOB locators
- `SQLTYPE(CLOB_FILE)` / `SQLTYPE(BLOB_FILE)` / `SQLTYPE(DBCLOB_FILE)` — LOB file references

### 24. Operation Code Extenders
- `(E)` — Error handling extender (sets %ERROR/%STATUS)
- `(N)` — No-lock extender on read
- `(H)` — Half-adjust (rounding) extender
- `(D/T/Z)` — Date/time/timestamp extender on TEST
- `(M)` — Maximum digits (on EVAL, use max precision)
- `(R)` — Result decimal positions (on EVAL)
- `(P)` — Pad result with blanks

### 25. Compiler Directives Missing
- ~~`/EOF` — Force end-of-file on source~~ ✅
- ~~`/EJECT` / `/SPACE` — Listing formatting~~ ✅
- ~~`/SET` / `/RESTORE` — Compiler directive values~~ ✅
- ~~`/ELSEIF` in conditional compilation~~ ✅
- ~~`/FREE` / `/END-FREE` — Free-format section markers (deprecated in 7.2+, for older source compat)~~ ❌ Not Planned
- ~~`/TITLE text` — Set listing title~~ ✅ (parsed for compatibility, no functionality)

### 26. Date/Time Format Constants ✅
- ~~Date formats: `*ISO`, `*USA`, `*EUR`, `*JIS`, `*MDY`, `*DMY`, `*YMD`, `*JUL`, `*CYMD`, `*CMDY`, `*CDMY`, `*LONGJUL`~~ ✅ (Test 73)
- ~~Time formats: `*HMS`, `*ISO`, `*USA`, `*EUR`, `*JIS`~~ ✅
- ~~Timestamp formats: `*ISO`, `*ISO0`~~ ✅

### 27. Program Status Data Structure (PSDS)
Full PSDS subfield positions:
- 1-10: Procedure/module name
- 11-15: Status code (5,0)
- 16-20: Previous status code (5,0)
- 21-28: Source statement number (line)
- 29-36: RPG routine name (*INIT, *DETL, *GETIN, *TOTC, *TOTL, *DETC, *OFL, *TERM, proc name)
- 37-39: Number of parameters passed (3,0)
- 40-42: Exception type (MCH, CPF, etc.)
- 43-46: Exception number
- 51-80: Message work area
- 81-90: Program library
- 91-170: Retrieved exception data
- 171-174: Exception ID causing RNX9001
- 175-184: Last file with I/O error
- 191-198: Date entered system (job date)
- 199-200: Century of start date (2,0)
- 201-208: Last file operation
- 209-243: Last file status info
- 244-253: Job name
- 254-263: Job user
- 264-269: Job number (6,0)
- 270-275: Job started date (6,0)
- 276-281: Program run date (6,0)
- 282-287: Program run time (6,0)
- 288-293: Compile date
- 294-299: Compile time
- 300-303: Compiler level
- 304-313: Source file name
- 314-323: Source library
- 324-333: Source member
- 334-343: Program containing procedure
- 344-353: Module containing procedure
- 354-355: Source statement number (binary 2)
- 356-357: Source ID (binary 2)
- 358-367: Current user
- 368-371: External error code (int 4)
- 372-379: Elements set by XML-INTO/DATA-INTO (int 20)
- 380-395: Internal job ID (7.3 TR6+)
- 396-403: System name (7.3 TR6+)

### 28. File Information Data Structure (INFDS) — Not Planned ❌

### 29. Indicator Types — Partially Done
- ~~`*IN01` - `*IN99` — General indicators~~ ✅
- ~~`*INLR` — Last Record indicator~~ ✅ (compatibility only, not implemented)
- ~~`*INKA` - `*INKN`, `*INKP` - `*INKY` — Command key (function key) indicators~~ ❌ Not Planned
- ~~`*INH1` - `*INH9` — Halt indicators~~ ❌ Not Planned
- ~~`*INOA` - `*INOG`, `*INOV` — Overflow indicators~~ ❌ Not Planned
- ~~`*INRT` — Return indicator~~ ❌ Not Planned
- ~~`*INL1` - `*INL9` — Level indicators (cycle)~~ ❌ Not Planned
- ~~`*INMR` — Matching record indicator~~ ❌ Not Planned
- ~~`*INU1` - `*INU8` — External indicators~~ ❌ Not Planned
- ~~`*IN` — General indicator array (*IN(1) through *IN(99))~~ ❌ Not Planned

### 30. Data Area Operations
- `IN` / `OUT` opcodes for data areas
- `UNLOCK` opcode — Unlock data area without updating
- `DTAARA` keyword on DCL-S/DCL-DS — Associate with data area
- `DTAARA(*VAR:fieldname)` — Dynamic data area name
- `*LDA` — Local Data Area
- `*PDA` — Program Initialization Parameter Data Area
- `*GDA` — Group Data Area

### 31. Open Access (Handler Programs) — Not Planned
- ~~`HANDLER` keyword on DCL-F — Specify handler program/procedure~~ ❌
- ~~Handler parameter DS — Standard handler communication structure~~ ❌
- ~~Open Access enablement (5733-OAR)~~ ❌

### 32. RPG Status Codes
Complete list of %STATUS code values (100-9999) for error handling:
- 100: Value out of range for string operation
- 101: Negative square root
- 102: Divide by zero
- 103: Intermediate result overflow
- 104: Float underflow
- 112: Invalid date/time/timestamp value
- 113: Date overflow/underflow
- 114: Date mapping errors
- 115: Variable-length field has invalid length
- 120: Table/array out of sequence
- 121: Array index not valid
- 122: OCCUR value not valid
- 202: Called program failed
- 211: Error calling program
- 221: Called program not found
- 222: Pointer/parameter error
- 231: Called program halted
- 232: Halt indicator on in called program
- 233: Halt indicator on when RETURN
- 299: RPG IV runtime error
- 301-399: File I/O errors
- 401: Data area not found
- 402: Data area type/length mismatch
- 411: Data area not locked
- 412: Data area lock error
- 413: Error updating data area
- 414: User not authorized to data area
- 415: Error accessing data area
- 421: Error calling DSPLY
- 431: Error calling SND-MSG
- 450: Character conversion error
- 500: Failure to allocate storage
- 802: Failure in sort
- 803: Error during dump
- 804: Error in *PSSR
- 907: Decimal data error
- 1021-1026: XML parser errors
- 1211-1299: XML-SAX/XML-INTO errors
- 9001: Program exception
- 9999: General ILE RPG error

### 33. Legacy/RPG Cycle — Not Planned
- ~~RPG cycle processing (detail calc, total calc, LR indicator)~~ ❌
- ~~CTDATA — Compile-time array data at end of source~~ ❌
- ~~ALT(array) — Alternating arrays~~ ❌
- ~~`OCCURS(n)` / `%OCCUR(dsname)` — Multiple-occurrence DS (legacy, replaced by DIM/arrays)~~ ❌

### 34. IBM i-Specific Features — Not Planned
- ~~%GRAPH — Convert to graphic (DBCS)~~ ❌
- ~~%UCS2 — Convert to UCS-2 encoding~~ ❌
- ~~%SHTDN — Check system shutdown request~~ ❌
- ~~CCSID — Character set conversion IDs~~ ❌
- ~~FROMFILE/TOFILE — Compile-time array file keywords~~ ❌
- ~~SERIALIZE — Serialized procedure access (IBM i job locking)~~ ❌

### 35. Fixed-Format Only Opcodes — Not Planned
These opcodes exist only in fixed-format RPG and have free-format equivalents:
- ~~`ADD`, `SUB`, `MULT`, `DIV`, `MVR`, `Z-ADD`, `Z-SUB` — Arithmetic (use EVAL)~~ ❌
- ~~`SQRT` — Square root (use %SQRT)~~ ❌
- ~~`XFOOT` — Cross-foot (use %XFOOT)~~ ❌
- ~~`MOVE`, `MOVEL`, `MOVEA` — Move operations (use EVAL / %SUBST / %CHAR / etc.)~~ ❌
- ~~`COMP`, `CABxx`, `CASxx` — Compare and branch (use IF/SELECT)~~ ❌
- ~~`CAT` — Concatenate (use + operator)~~ ❌
- ~~`CHECK`, `CHECKR` — Check characters (use %CHECK / %CHECKR)~~ ❌
- ~~`SCAN` — Scan string (use %SCAN)~~ ❌
- ~~`SUBST` — Substring (use %SUBST)~~ ❌
- ~~`XLATE` — Translate (use %XLATE)~~ ❌
- ~~`LOOKUP` — Look up (use %LOOKUP)~~ ❌
- ~~`DO`, `DOUxx`, `DOWxx`, `IFxx`, `WHENxx`, `ANDxx`, `ORxx` — Control flow (use free-format)~~ ❌
- ~~`GOTO`, `TAG` — Goto/label~~ ❌
- ~~`CALL`, `CALLB` — Non-prototyped calls (use CALLP with DCL-PR)~~ ❌
- ~~`PARM`, `PLIST` — Parameter list (use DCL-PR/DCL-PI)~~ ❌
- ~~`KLIST`, `KFLD` — Key list (use %KDS)~~ ❌
- ~~`DEFINE` — Field definition (use DCL-S)~~ ❌
- ~~`OCCUR` — Set/get occurrence (use %OCCUR)~~ ❌
- ~~`ADDDUR`, `SUBDUR` — Duration ops (use + / - with %DAYS etc.)~~ ❌
- ~~`EXTRCT` — Extract date/time part (use %SUBDT)~~ ❌
- ~~`TIME` — Retrieve time (use %TIMESTAMP)~~ ❌
- ~~`ALLOC`, `REALLOC` — Allocation (use %ALLOC / %REALLOC)~~ ❌
- ~~`SETON`, `SETOFF` — Set indicators (use EVAL *INxx = *ON/*OFF)~~ ❌
- ~~`BITON`, `BITOFF`, `TESTB` — Bit operations (use %BITAND / %BITOR etc.)~~ ❌
- ~~`TESTN`, `TESTZ` — Test numeric/zone~~ ❌
- ~~`MHHZO`, `MHLZO`, `MLHZO`, `MLLZO` — Move zone operations~~ ❌
- ~~`ENDyy` — Generic end~~ ❌

---

## Implementation Priority Recommendation

**Tier 1 — Core (needed by most programs):** ✅ ALL DONE
1. ~~*INZSR special subroutine~~ ✅ (Test 37)
2. ~~CTL-OPT (parsed and consumed)~~ ✅ (Test 38)
3. ~~Figurative constants (*BLANKS, *ZEROS, *HIVAL, *LOVAL)~~ ✅ (Test 39)
4. ~~EVALR, LEAVESR, CALLP~~ ✅ (Test 40)
5. ~~%LOWER, %UPPER, %SUBDT, %FLOAT, %SQRT~~ ✅ (Test 41)

**Tier 2 — Important (commonly used):** ✅ MOSTLY DONE
6. ~~ON-EXIT~~ ✅ (Test 42)
7. ~~STATIC, TEMPLATE~~ ✅ (Test 43), ~~BASED~~ ✅
8. ~~%ALLOC, %REALLOC, DEALLOC~~ ✅ (Test 44)
9. ~~%XFOOT~~ ✅ (Test 45), ~~%SUBARR, %SPLIT~~ ✅ (Test 51/52)
10. ~~OPTIONS(*NOPASS)~~ ✅ (Test 46), ~~*OMIT~~ ✅ (Test 64)
11. ~~TEST opcode~~ ✅ (Test 47)
12. Operation extenders (E), (H), (N)
13. ~~%BITAND, %BITNOT, %BITOR, %BITXOR — Bitwise BIFs~~ ✅ (Test 68)
14. ~~** exponentiation operator~~ ✅ (Test 68)
15. ~~%SCANR — Reverse scan~~ ✅ (Test 69)
16. ~~%EDITFLT, %UNSH — Numeric formatting/conversion~~ ✅ (Test 70)
17. ~~%PARMNUM — Parameter number~~ ✅ (Test 71)
18. ~~DCL-ENUM / BOOLEAN — Enumerations and boolean type (7.4/7.5)~~ ✅ (Test 71)
19. ~~DIM(*AUTO:max), DIM(*VAR:max) — Varying-dimension arrays (7.4)~~ ✅ (Test 72)
20. ~~%OPEN, %KDS, %FIELDS, %EQUAL, %NULLIND — File/Record BIFs~~ ❌ Not Planned
21. ~~%GRAPH, %UCS2, %SHTDN — Conversion/Formatting BIFs~~ ❌ Not Planned (IBM i-specific encodings)
22. %DATA, %GEN, %PARSER, %HANDLER, %XML, %MSG, %TARGET — Companion BIFs
23. *ENTRY, *USER — Figurative constants
24. ~~OPTIONS(*VARSIZE/*STRING/*TRIM/*RIGHTADJ/*CONVERT/*EXACT) — Parameter options~~ ❌ Not Planned
25. RTNPARM, OPDESC, NOOPT — Procedure/variable keywords
26. NULLIND, VARYING, DTAARA, PERRCD — Declaration keywords
27. LIKEREC, ALIGN, LEN, PSDS, DIM(*AUTO), DIM(*VAR) — DS keywords
28. ~~%CONCAT — Concatenate with separator (7.5+)~~ ✅ (Test 74)
29. ~~%TLOOKUP and variants — Table lookup BIFs~~ ✅ (Test 75)
30. ~~%ELEM(array) = n~~ ✅ (Test 72), %ELEM(*ALLOC/*KEEP) — Varying array control (7.4)
31. Data area operations (IN/OUT/UNLOCK, DTAARA, *LDA/*GDA/*PDA)

**Tier 3 — File I/O (big effort):**
20. Full DCL-F with all keywords
21. CHAIN, READ, WRITE, UPDATE, DELETE, SETLL, SETGT
22. Record formats and externally-described files
23. EXTNAME DS (with *ALL/*INPUT/*OUTPUT/*KEY)
24. LIKEREC, LIKEFILE
25. PSDS — Program Status Data Structure
26. INFDS — File Information Data Structure
27. INFSR — File error subroutine

**Tier 4 — SQL (biggest effort):**
28. EXEC SQL parsing and translation
29. Host variables, cursors, SQLSTATE/SQLCODE
30. SQLTYPE data types (CLOB, BLOB, etc.)
31. Connection management, transaction control
32. GET DIAGNOSTICS, WHENEVER, SQLCA/SQLDA

**Tier 5 — Modern/Stretch:**
33. ~~FOR-EACH, %LIST, %RANGE, IN operator~~ ✅ (Test 58)
34. DATA-INTO, DATA-GEN (%DATA, %GEN, %PARSER)
35. XML-SAX, XML-INTO (%XML, %HANDLER)
36. SND-MSG, ON-EXCP (%MSG, %TARGET)
37. OVERLOAD — Overloaded procedures
38. ~~Open Access — Handler programs~~ ❌ Not Planned
39. ~~Data area operations~~ (moved to Tier 2, item 31)
40. ~~SERIALIZE — Thread-safe procedures~~ ❌ Not Planned
41. Remaining CTL-OPT keywords
42. ~~Indicator types (*INKx, *INHx, *INOx, *INLx, *INUx)~~ ❌ Not Planned
