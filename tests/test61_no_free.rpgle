// Test 61: No **FREE directive
DCL-S x INT(10);
DCL-S msg CHAR(20);
x = 42;
msg = 'No FREE needed';
DSPLY msg;
DSPLY %CHAR(x);
*INLR = *ON;
