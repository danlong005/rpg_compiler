**FREE
DCL-S text VARCHAR(50);
DCL-S result INT(10);

// %EDITFLT — format number in external float representation
text = %EDITFLT(1234.5);
DSPLY text;

text = %EDITFLT(-0.005);
DSPLY text;

// %UNSH — unsigned integer with half-adjust (rounding)
result = %UNSH(3.7);
DSPLY %CHAR(result);  // 4

result = %UNSH(3.2);
DSPLY %CHAR(result);  // 3

result = %UNSH(5.5);
DSPLY %CHAR(result);  // 6

*INLR = *ON;
