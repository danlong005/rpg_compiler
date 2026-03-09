**FREE
DCL-S nums INT(10) DIM(5);
DCL-S names VARCHAR(20) DIM(4);
DCL-S pos INT(10);
DCL-S i INT(10);

// Fill arrays
nums(1) = 30;
nums(2) = 10;
nums(3) = 50;
nums(4) = 20;
nums(5) = 40;

// %LOOKUP - find element in array (returns 1-based index, 0 if not found)
pos = %LOOKUP(50 : nums);
DSPLY %CHAR(pos);

pos = %LOOKUP(99 : nums);
DSPLY %CHAR(pos);

// SORTA - sort array ascending
SORTA nums;
FOR i = 1 TO 5;
  DSPLY %CHAR(nums(i));
ENDFOR;

// %LOOKUP after sort
pos = %LOOKUP(30 : nums);
DSPLY %CHAR(pos);

// String array
names(1) = 'Charlie';
names(2) = 'Alice';
names(3) = 'Bob';
names(4) = 'Dave';

SORTA names;
FOR i = 1 TO 4;
  DSPLY names(i);
ENDFOR;

*INLR = *ON;
