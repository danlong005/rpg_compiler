**FREE
DCL-S statusCode INT(10);
DCL-S errFlag INT(10);

// %STATUS returns last error status (0 = no error)
statusCode = %STATUS();
DSPLY %CHAR(statusCode);

// %ERROR returns whether last operation had an error (0=false, 1=true)
errFlag = %ERROR();
DSPLY %CHAR(errFlag);

// Normal operation - status stays 0
statusCode = 42;
statusCode = %STATUS();
DSPLY %CHAR(statusCode);

*INLR = *ON;
