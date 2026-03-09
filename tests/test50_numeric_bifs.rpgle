**FREE
// Test 50: Numeric BIFs - %UNS, %INTH, %DECH, %DECPOS
DCL-S val PACKED(7:2);
DCL-S result INT(10);
DCL-S uval INT(10);
DCL-S dpos INT(10);

val = 3.456;

// %INTH - integer with half-adjust (rounding)
result = %INTH(val);
DSPLY %CHAR(result);

// %DECH - decimal with half-adjust
val = %DECH(3.456 : 7 : 1);
DSPLY %CHAR(val);

// %DECPOS - number of decimal positions
dpos = %DECPOS(val);
DSPLY %CHAR(dpos);

// %UNS - convert to uvaligned integer
uval = %UNS(42);
DSPLY %CHAR(uval);

*INLR = *ON;
