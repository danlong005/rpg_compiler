**FREE
DCL-S x INT(10);
DCL-S y INT(10);
DCL-S result INT(10);
DCL-S decVal PACKED(9:2);

// %ABS - absolute value
x = -42;
result = %ABS(x);
DSPLY %CHAR(result);

// %ABS with positive
x = 17;
result = %ABS(x);
DSPLY %CHAR(result);

// %DIV - integer division
x = 17;
y = 5;
result = %DIV(x : y);
DSPLY %CHAR(result);

// %REM - remainder
result = %REM(x : y);
DSPLY %CHAR(result);

// %ABS with decimal
decVal = -3.14;
decVal = %ABS(decVal);
DSPLY %CHAR(decVal);

// %DIV and %REM together: 100 / 7
result = %DIV(100 : 7);
DSPLY %CHAR(result);
result = %REM(100 : 7);
DSPLY %CHAR(result);

*INLR = *ON;
