**FREE
DCL-S str CHAR(10);
DCL-S result VARCHAR(20);

// EVALR - right-adjust assignment
str = *BLANKS;
EVALR str = 'Hi';
DSPLY str;

// LEAVESR - exit subroutine early
result = 'before';
EXSR mySR;
DSPLY result;

*INLR = *ON;

BEGSR mySR;
  result = 'entered';
  LEAVESR;
  result = 'should not reach';
ENDSR;
