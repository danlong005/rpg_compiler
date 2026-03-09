**FREE
// Test 58: FOR-EACH and IN operator
DCL-S names CHAR(10) DIM(3);
DCL-S name CHAR(10);
DCL-S val INT(10);

names(1) = 'Alice';
names(2) = 'Bob';
names(3) = 'Charlie';

// FOR-EACH over array
FOR-EACH name IN names;
  DSPLY %TRIM(name);
ENDFOR;

// IN operator with %LIST
val = 5;
IF val IN %LIST(1 : 3 : 5 : 7);
  DSPLY 'Found in list';
ENDIF;

// IN operator with %RANGE
val = 15;
IF val IN %RANGE(10 : 20);
  DSPLY 'In range';
ENDIF;

// IN not found
val = 99;
IF NOT (val IN %LIST(1 : 2 : 3));
  DSPLY 'Not found';
ENDIF;

*INLR = *ON;
