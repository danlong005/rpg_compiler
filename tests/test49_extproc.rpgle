**FREE
DCL-S sharedVal INT(10) IMPORT;

DCL-PR externalAdd INT(10) EXTPROC('ADD');
  a INT(10) VALUE;
  b INT(10) VALUE;
END-PR;

DSPLY %CHAR(externalAdd(10 : 20));
DSPLY %CHAR(sharedVal);

*INLR = *ON;
