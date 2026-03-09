**FREE
DCL-S str VARCHAR(50);
DCL-S result VARCHAR(50);

str = 'Hello World';

// %REPLACE(new : source : start : length)
result = %REPLACE('RPG' : str : 7 : 5);
DSPLY result;

// %REPLACE without length (insert)
result = %REPLACE('Beautiful ' : str : 7);
DSPLY result;

// %REPLACE at position 1
result = %REPLACE('Goodbye' : str : 1 : 5);
DSPLY result;

*INLR = *ON;
