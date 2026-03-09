**FREE
// Test 60: New data types (UNS, FLOAT, BINDEC)
DCL-S uval UNS(10);
DCL-S fval FLOAT(8);
DCL-S bval BINDEC(9);

uval = 42;
DSPLY %CHAR(uval);

fval = 3.14159;
DSPLY %CHAR(fval);

bval = 100;
DSPLY %CHAR(bval);

// UNS conversion
uval = %UNS(99);
DSPLY %CHAR(uval);

// FLOAT conversion
fval = %FLOAT(42);
DSPLY %CHAR(fval);

*INLR = *ON;
