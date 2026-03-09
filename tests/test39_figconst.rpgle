**FREE
DCL-S str CHAR(10);
DCL-S num INT(10);
DCL-S dec PACKED(7:2);

// *BLANKS / *ZEROS
str = *BLANKS;
DSPLY str;

num = *ZEROS;
DSPLY %CHAR(num);

dec = *ZEROS;
DSPLY %CHAR(dec);

// *HIVAL / *LOVAL
num = *HIVAL;
DSPLY %CHAR(num);

num = *LOVAL;
DSPLY %CHAR(num);

*INLR = *ON;
