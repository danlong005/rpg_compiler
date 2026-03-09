**FREE
DCL-S price PACKED(7:2);
DCL-S qty INT(10);
DCL-S total PACKED(9:2);
DCL-S name VARCHAR(50);
DCL-S MAX_SIZE INT(10) CONST INZ(100);
DCL-S greeting CHAR(20) INZ('Hi there');
DCL-S counter INT(10) INZ(5);
price = 19.99;
qty = 3;
total = price * qty;
name = 'RPG Program';
DSPLY name;
DSPLY %CHAR(total);
DSPLY greeting;
DSPLY %CHAR(MAX_SIZE);
DSPLY %CHAR(counter);
*INLR = *ON;
