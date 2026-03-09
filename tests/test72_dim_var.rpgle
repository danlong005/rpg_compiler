**FREE
DCL-S nums INT(10) DIM(*VAR:100);
DCL-S names VARCHAR(20) DIM(*VAR:50);
DCL-S i INT(10);
DCL-S count INT(10);

// Set size and fill
%ELEM(nums) = 5;
FOR i = 1 TO 5;
  nums(i) = i * 10;
ENDFOR;

count = %ELEM(nums);
DSPLY %CHAR(count);  // 5

// Display values
DSPLY %CHAR(nums(1));  // 10
DSPLY %CHAR(nums(5));  // 50

// Resize down
%ELEM(nums) = 3;
count = %ELEM(nums);
DSPLY %CHAR(count);  // 3

*INLR = *ON;
