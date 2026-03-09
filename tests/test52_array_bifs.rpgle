**FREE
// Test 52: Array BIFs - %MAXARR, %MINARR, %LOOKUPxx
DCL-S nums INT(10) DIM(5);
DCL-S idx INT(10);

nums(1) = 30;
nums(2) = 10;
nums(3) = 50;
nums(4) = 20;
nums(5) = 40;

// %MAXARR - index of max element
idx = %MAXARR(nums);
DSPLY %CHAR(idx);

// %MINARR - index of min element
idx = %MINARR(nums);
DSPLY %CHAR(idx);

// %LOOKUPGE - find first >= 25
idx = %LOOKUPGE(25 : nums);
DSPLY %CHAR(idx);

// %LOOKUPLT - find first < 25
idx = %LOOKUPLT(25 : nums);
DSPLY %CHAR(idx);

*INLR = *ON;
