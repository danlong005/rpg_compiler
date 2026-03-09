**FREE
DCL-S total INT(10);
DCL-S x INT(10);

total = 0;

// Define subroutines
BEGSR addTen;
  total = total + 10;
ENDSR;

BEGSR showTotal;
  DSPLY %CHAR(total);
ENDSR;

// Call subroutines
EXSR addTen;
EXSR addTen;
EXSR addTen;
EXSR showTotal;

// Subroutine with condition
x = 5;
BEGSR doubleIfSmall;
  IF x < 10;
    x = x * 2;
  ENDIF;
ENDSR;

EXSR doubleIfSmall;
DSPLY %CHAR(x);

*INLR = *ON;
