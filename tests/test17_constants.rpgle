**FREE
DCL-C MAX_SIZE 100;
DCL-C GREETING 'Hello from constant';
DCL-C TAX_RATE 0.08;

DCL-S items INT(10);
DCL-S msg VARCHAR(50);
DCL-S total PACKED(9:2);

items = MAX_SIZE;
DSPLY %CHAR(items);

msg = GREETING;
DSPLY msg;

total = 500.00 * TAX_RATE;
DSPLY %CHAR(total);

// Use constant in expression
items = MAX_SIZE - 10;
DSPLY %CHAR(items);

*INLR = *ON;
