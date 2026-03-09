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
- Date/time arithmetic, *INZSR, CTL-OPT (consumed)
- FOR-EACH, IN operator, BASED, ASCEND/DESCEND, UNS, FLOAT, BINDEC, UCS2/GRAPH, OBJECT
- Compiler directives: /EOF, /EJECT, /SPACE, /SET, /RESTORE, /ELSEIF

---

## 🔴 Major Features (Core Language)

### 1. CTL-OPT (Control Options)
- ~~`NOMAIN` — No main procedure (service program module)~~ ✅ (Test 48)
- ~~`MAIN(procname)` — Named main procedure~~ ✅ (Test 56)
- `DFTACTGRP(*NO)` — Default activation group
- `ACTGRP(name)` — Activation group
- `BNDDIR(name)` — Binding directory
- ~~`DATFMT(fmt)` / `TIMFMT(fmt)` — Default date/time formats~~ ✅ (Test 57)
- `OPTION(...)` — Compiler options
- `DEBUG`, `DECEDIT`, `CCSID`, `TEXT`, `THREAD`, etc.

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
- DCL-F keywords: KEYED, USAGE, USROPN, QUALIFIED, EXTFILE, RENAME, PREFIX, SFILE, INFDS, INFSR, BLOCK, COMMIT, etc.

### 3. Embedded SQL
- `EXEC SQL ... ;` block parsing
- Host variables (`:variablename`)
- Cursors: DECLARE, OPEN, FETCH, CLOSE
- SELECT INTO, INSERT, UPDATE, DELETE
- SQLSTATE / SQLCODE special variables
- SET OPTION, PREPARE, EXECUTE

### 4. Service Programs / Modules
- ~~`EXPORT` keyword on DCL-PROC and DCL-S~~ ✅
- ~~`IMPORT` keyword on DCL-S~~ ✅
- ~~`NOMAIN` module support~~ ✅
- ~~`EXTPGM(name)` on DCL-PR — program calls~~ ✅
- ~~`EXTPROC(name)` on DCL-PR — external procedure binding~~ ✅
- Binding directories

---

## 🟡 Medium Features (Commonly Used)

### 5. Special Subroutines
- ~~`*INZSR` — Initialization subroutine~~ ✅ (Test 37)
- `*PSSR` — Program error/exception subroutine
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
- `FORCE` / `NEXT` / `POST` — Device operations
- `ACQ` / `REL` — Acquire/release program device
- `COMMIT` / `ROLBK` — Commitment control
- `IN` / `OUT` — Data area operations

### 8. Missing BIFs — Numeric
- ~~`%FLOAT(expr)` — Convert to float~~ ✅ (Test 41)
- ~~`%UNS(expr)` — Convert to unsigned integer~~ ✅ (Test 50)
- ~~`%INTH(expr)` — Integer with half-adjust (rounding)~~ ✅ (Test 50)
- ~~`%DECH(expr:d:p)` — Decimal with half-adjust~~ ✅ (Test 50)
- ~~`%DECPOS(num)` — Number of decimal positions~~ ✅ (Test 50)
- ~~`%SQRT(n)` — Square root~~ ✅ (Test 41)

### 9. Missing BIFs — String
- ~~`%LOWER(string)` — Convert to lowercase~~ ✅ (Test 41)
- ~~`%UPPER(string)` — Convert to uppercase~~ ✅ (Test 41)
- ~~`%SPLIT(string[:sep])` — Split into array (7.4+)~~ ✅ (Test 51)
- ~~`%CONCATARR(array:sep)` — Join array elements (7.5+)~~ ✅ (Test 51)
- ~~`%LEFT(string:len)` — Left substring (7.6+)~~ ✅ (Test 51)
- ~~`%RIGHT(string:len)` — Right substring (7.6+)~~ ✅ (Test 51)
- ~~`%STR(ptr[:len])` — Null-terminated string from pointer~~ ✅ (Test 51)

### 10. Missing BIFs — Array
- ~~`%SUBARR(array:start[:count])` — Sub-array reference~~ ✅ (Test 52)
- ~~`%XFOOT(array)` — Sum all array elements~~ ✅ (Test 45)
- ~~`%MAXARR(array)` — Index of maximum value (7.4+)~~ ✅ (Test 52)
- ~~`%MINARR(array)` — Index of minimum value (7.4+)~~ ✅ (Test 52)
- ~~`%LIST(val1:val2:...)` — Temporary array literal (7.4+)~~ ✅ (Test 52)
- ~~`%RANGE(low:high)` — Value range (7.4+)~~ ✅ (Test 52)
- ~~`%LOOKUPLT / %LOOKUPGE / %LOOKUPLE / %LOOKUPGT` — Array search variants~~ ✅ (Test 52)

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

### 14. Figurative Constants
- ~~`*BLANK` / `*BLANKS` — Blank value~~ ✅ (Test 39)
- ~~`*ZERO` / `*ZEROS` — Zero value~~ ✅ (Test 39)
- ~~`*HIVAL` — Highest value for type~~ ✅ (Test 39)
- ~~`*LOVAL` — Lowest value for type~~ ✅ (Test 39)
- ~~`*ALL'x'` — Fill with repeated character(s)~~ ✅ (Test 55)
- `*OMIT` — Omit optional parameter

### 15. Declaration Keywords Missing
- ~~`TEMPLATE` — Template only (no storage, for LIKE/LIKEDS reference)~~ ✅ (Test 43)
- ~~`BASED(pointer)` — Based variable at pointer location~~ ✅
- ~~`STATIC` — Static storage in procedure (retains across calls)~~ ✅ (Test 43)
- ~~`EXTNAME(filename)` — Externally described DS from DB file~~ ✅ (stub)
- `OVERLAY(field[:pos])` — Overlay fields in DS
- `POS(n)` — Position within DS
- `PREFIX(pfx[:n])` — Prefix field names
- ~~`DATFMT(fmt)` / `TIMFMT(fmt)` — Date/time format on fields~~ ✅
- ~~`OPTIONS(*NOPASS)` — Optional parameter~~ ✅ (Test 46)
- `OPTIONS(*OMIT:*VARSIZE:*STRING:*TRIM)` — Other parameter options
- `RTNPARM` — Return value as hidden parameter
- `OPDESC` — Operational descriptors
- ~~`ASCEND` / `DESCEND` — Array sort order~~ ✅
- `NULLIND(field)` — Null indicator association

---

## 🟢 Minor / Stretch Features

### 16. Newer Language Features (IBM i 7.4+)
- ~~`FOR-EACH` / `ENDFOR` — Iterate over arrays / %LIST~~ ✅ (Test 58)
- `SND-MSG` — Send message to job log (7.5+)
- `ON-EXCP` — Monitor for specific escape message (7.5+)
- `DATA-INTO` — Parse JSON/CSV/etc. into RPG variables
- `DATA-GEN` — Generate structured output from RPG variables
- ~~`IN` operator — `IF x IN %LIST(...)` or `IF x IN %RANGE(...)`~~ ✅ (Test 58)
- ~~`%PASSED(parm)` / `%OMITTED(parm)` — Optional parameter checks (7.5+)~~ ✅ (Test 59)
- `OVERLOAD(proc1:proc2:...)` — Overloaded procedures (7.4+)

### 17. XML Support
- `XML-SAX` — SAX-based XML parsing
- `XML-INTO` — Parse XML into RPG variables
- `%XML(doc:options)` / `%HANDLER(proc:commarea)`

### 18. Data Types Missing
- ~~`UNS(n)` — Unsigned integer (3, 5, 10, 20)~~ ✅ (Test 60)
- ~~`FLOAT(4|8)` — IEEE floating point~~ ✅ (Test 60)
- ~~`BINDEC(n)` — Binary decimal (legacy)~~ ✅ (Test 60)
- ~~`UCS2(n)` / `GRAPH(n)` — Unicode/DBCS~~ ✅
- ~~`OBJECT(*JAVA:class)` — Java object reference~~ ✅
- Multiple-occurrence DS (`OCCURS`, `%OCCUR`)

### 19. Operation Code Extenders
- `(E)` — Error handling extender (sets %ERROR/%STATUS)
- `(N)` — No-lock extender on read
- `(H)` — Half-adjust (rounding) extender
- `(D/T/Z)` — Date/time/timestamp extender on TEST

### 20. Compiler Directives Missing
- ~~`/EOF` — Force end-of-file on source~~ ✅
- ~~`/EJECT` / `/SPACE` — Listing formatting~~ ✅
- ~~`/SET` / `/RESTORE` — Compiler directive values~~ ✅
- ~~`/ELSEIF` in conditional compilation~~ ✅

### 21. Legacy/RPG Cycle
- RPG cycle processing (detail calc, total calc, LR indicator)
- `*DTAARA` data area support in DS
- CTDATA — Compile-time array data at end of source
- ALT(array) — Alternating arrays

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
10. ~~OPTIONS(*NOPASS)~~ ✅ (Test 46), *OMIT (not yet)
11. ~~TEST opcode~~ ✅ (Test 47)
12. Operation extenders (E), (H), (N) (not yet)

**Tier 3 — File I/O (big effort):**
13. Full DCL-F with keywords
14. CHAIN, READ, WRITE, UPDATE, DELETE, SETLL, SETGT
15. Record formats and externally-described files
16. EXTNAME DS

**Tier 4 — SQL (biggest effort):**
17. EXEC SQL parsing and translation

**Tier 5 — Modern/Stretch:**
18. ~~FOR-EACH, %LIST, %RANGE, IN operator~~ ✅ (Test 58)
19. DATA-INTO, DATA-GEN, XML-INTO
20. SND-MSG, ON-EXCP
