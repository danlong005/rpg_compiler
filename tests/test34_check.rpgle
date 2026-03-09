**FREE
DCL-S str VARCHAR(20);
DCL-S pos INT(10);

str = '  Hello';

// %CHECK(comparator : base {: start})
// Returns position of first char in base NOT in comparator
pos = %CHECK(' ' : str);
DSPLY %CHAR(pos);

// %CHECK with start position
pos = %CHECK('Helo' : str : 3);
DSPLY %CHAR(pos);

// All chars found → returns 0
pos = %CHECK('Helo ' : str);
DSPLY %CHAR(pos);

// %CHECKR - same but from right
str = 'Hello   ';
pos = %CHECKR(' ' : str);
DSPLY %CHAR(pos);

*INLR = *ON;
