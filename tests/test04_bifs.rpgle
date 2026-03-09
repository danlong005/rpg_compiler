**FREE
DCL-S padded CHAR(20);
DCL-S trimmed VARCHAR(50);
DCL-S length INT(10);
DCL-S part VARCHAR(50);
padded = '  Hello  ';
trimmed = %TRIM(padded);
DSPLY trimmed;
trimmed = %TRIML(padded);
DSPLY trimmed;
trimmed = %TRIMR(padded);
DSPLY trimmed;
length = %LEN(padded);
DSPLY %CHAR(length);
part = %SUBST(padded:3:5);
DSPLY part;
*INLR = *ON;
