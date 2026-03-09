**FREE
DCL-S a INT(10);
DCL-S b INT(10);
DCL-S c INT(10);
DCL-S result INT(10);
DCL-S s1 VARCHAR(20);
DCL-S s2 VARCHAR(20);
DCL-S sResult VARCHAR(20);

// %MAX with two integers
a = 10;
b = 25;
result = %MAX(a : b);
DSPLY %CHAR(result);

// %MIN with two integers
result = %MIN(a : b);
DSPLY %CHAR(result);

// %MAX with three integers
c = 15;
result = %MAX(a : b : c);
DSPLY %CHAR(result);

// %MIN with three integers
result = %MIN(a : b : c);
DSPLY %CHAR(result);

// %MAX / %MIN with literals
result = %MAX(3 : 7 : 1 : 9 : 4);
DSPLY %CHAR(result);
result = %MIN(3 : 7 : 1 : 9 : 4);
DSPLY %CHAR(result);

// %MAX / %MIN with strings (lexicographic)
s1 = 'Apple';
s2 = 'Banana';
sResult = %MAX(s1 : s2);
DSPLY sResult;
sResult = %MIN(s1 : s2);
DSPLY sResult;

*INLR = *ON;
