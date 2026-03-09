**FREE
DCL-S nums INT(10) DIM(5);
DCL-S total INT(10);

// Fill array
nums(1) = 10;
nums(2) = 20;
nums(3) = 30;
nums(4) = 40;
nums(5) = 50;

// %XFOOT - sum all elements
total = %XFOOT(nums);
DSPLY %CHAR(total);

*INLR = *ON;
