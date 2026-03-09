# RPG IV Features Not Yet Implemented

## Major Features (Core Language)
1. **CTL-OPT** — Control options (DFTACTGRP, ACTGRP, BNDDIR, etc.)
2. **File I/O** — DCL-F (parsed, stub only), READ, WRITE, UPDATE, DELETE, CHAIN, SETLL, SETGT, OPEN, CLOSE, record formats, externally-described files
3. **SQL embedded** — EXEC SQL blocks
4. **Service programs / modules** — EXPORT keyword on DCL-PROC, binding directories, NOMAIN

## Medium Features (Commonly Used)
~~5. **DCL-SUBF / DCL-PARM** — Explicit subfield/parameter declarations~~ ✅ Implemented (Test 29)
~~6. **LIKE / LIKEDS** — Variable declarations based on another variable's type~~ ✅ Implemented (Test 30)
~~7. **%LOOKUP** — Array search BIF~~ ✅ Implemented (Test 31)
~~8. **SORTA** — Sort array operation~~ ✅ Implemented (Test 31)
~~9. **%EDITC / %EDITW** — Edit codes and edit words for formatting numbers~~ ✅ Implemented (Test 32)
~~10. **%REPLACE** — Replace substring at position~~ ✅ Implemented (Test 33)
~~11. **%CHECK / %CHECKR** — Character validation BIFs~~ ✅ Implemented (Test 34)
~~12. **EVAL-CORR** — Assign matching fields between data structures~~ ✅ Implemented (Test 35)
~~13. **Multiple return values** — Via data structure parameters~~ ✅ Implemented (Test 36)
14. **Overloaded procedures** — OVERLOAD keyword
15. **ON-EXIT** — Cleanup code that always runs when procedure ends

## Minor / Less Common
~~16. **%ABS / %REM / %DIV** — Math BIFs~~ ✅ Implemented (Test 19)
~~17. **%SIZE / %ADDR** — Memory BIFs~~ ✅ Implemented (Test 20)
18. **%SHTDN** — System shutdown check
~~19. **%PARMS** — Parameter count BIF~~ ✅ Implemented (Test 21)
~~20. **%STATUS / %ERROR** — Status BIFs~~ ✅ Implemented (Test 22)
~~21. **Conditional compilation** — /IF, /ELSEIF, /ELSE, /ENDIF, /DEFINE, /UNDEFINE~~ ✅ Implemented (Test 28)
22. **Data areas** — IN, OUT, UNLOCK operations
~~23. **RESET** — Reset variable to initial value~~ ✅ Implemented (Test 23)
~~24. **CLEAR** — Clear variable/structure~~ ✅ Implemented (Test 23)
~~25. **%MAX / %MIN** — Modern BIFs~~ ✅ Implemented (Test 24)
~~26. **Free-form DCL-F** — File declarations (stub)~~ ✅ Implemented (Test 25)
~~27. **Pointers** — POINTER type, %ADDR, *NULL~~ ✅ Implemented (Test 26)
~~28. **DCL-S DIM arrays** — Fixed-size arrays with 1-based indexing~~ ✅ Implemented (Test 27)
