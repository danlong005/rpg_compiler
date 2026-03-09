**FREE
DCL-S myInt INT(10);
DCL-S myChar CHAR(20);
DCL-S myPacked PACKED(9:2);
DCL-S sizeResult INT(10);
DCL-S ptr POINTER;

// %SIZE - get size of variable in bytes
sizeResult = %SIZE(myInt);
DSPLY %CHAR(sizeResult);

sizeResult = %SIZE(myChar);
DSPLY %CHAR(sizeResult);

sizeResult = %SIZE(myPacked);
DSPLY %CHAR(sizeResult);

// %ADDR - get address of variable
myInt = 42;
ptr = %ADDR(myInt);
DSPLY 'Got pointer';

// Verify pointer is not null
IF ptr <> *NULL;
  DSPLY 'Pointer not null';
ENDIF;

*INLR = *ON;
