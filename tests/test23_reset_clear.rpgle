**FREE
DCL-S myInt INT(10) INZ(42);
DCL-S myStr VARCHAR(50) INZ('Hello');
DCL-S myDec PACKED(9:2) INZ(3.14);
DCL-S myChar CHAR(10) INZ('RPG');

// Show initial values
DSPLY %CHAR(myInt);
DSPLY myStr;

// Change values
myInt = 100;
myStr = 'Changed';
myDec = 99.99;
myChar = 'Modified';

DSPLY %CHAR(myInt);
DSPLY myStr;

// RESET restores to INZ value
RESET myInt;
RESET myStr;
DSPLY %CHAR(myInt);
DSPLY myStr;

// CLEAR sets to type default (0, empty string, etc.)
CLEAR myInt;
CLEAR myStr;
CLEAR myDec;
CLEAR myChar;
DSPLY %CHAR(myInt);
DSPLY myStr;
DSPLY %CHAR(myDec);
DSPLY myChar;

*INLR = *ON;
