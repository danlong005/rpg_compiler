**FREE
DCL-S pos INT(10);
DCL-S text VARCHAR(50);

text = 'Hello World Hello';

// %SCANR — find last occurrence of 'Hello'
pos = %SCANR('Hello':text);
DSPLY %CHAR(pos);  // 13

// %SCANR — find last occurrence of 'o'
pos = %SCANR('o':text);
DSPLY %CHAR(pos);  // 17

// %SCANR — not found
pos = %SCANR('xyz':text);
DSPLY %CHAR(pos);  // 0

// %SCANR — with start position (search up to position 10)
pos = %SCANR('Hello':text:10);
DSPLY %CHAR(pos);  // 1

*INLR = *ON;
