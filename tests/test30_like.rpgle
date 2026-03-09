**FREE
DCL-S baseInt INT(10);
DCL-S baseStr VARCHAR(50);
DCL-S baseDec PACKED(9:2);

// LIKE keyword - declare variable with same type as another
DCL-S copyInt LIKE(baseInt);
DCL-S copyStr LIKE(baseStr);
DCL-S copyDec LIKE(baseDec);

baseInt = 42;
copyInt = baseInt;
DSPLY %CHAR(copyInt);

baseStr = 'Hello LIKE';
copyStr = baseStr;
DSPLY copyStr;

baseDec = 3.14;
copyDec = baseDec;
DSPLY %CHAR(copyDec);

*INLR = *ON;
