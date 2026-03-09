**FREE
DCL-S x INT(10);

// Set indicators
*IN01 = *ON;
*IN02 = *OFF;
*IN50 = *ON;

// Test indicators in conditions
IF *IN01;
  DSPLY 'IN01 is on';
ENDIF;

IF NOT *IN02;
  DSPLY 'IN02 is off';
ENDIF;

// Use indicator in logic
x = 0;
IF *IN50 AND NOT *IN02;
  x = 100;
ENDIF;
DSPLY %CHAR(x);

// Toggle indicator
*IN01 = *OFF;
IF NOT *IN01;
  DSPLY 'IN01 now off';
ENDIF;

*INLR = *ON;
