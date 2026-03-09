**FREE
DCL-S result INT(10);
DCL-S text VARCHAR(50);

// MONITOR/ON-ERROR → try/catch (normal case)
MONITOR;
  result = 42;
  DSPLY %CHAR(result);
ON-ERROR;
  DSPLY 'Error occurred';
ENDMON;

// Test nested monitor
MONITOR;
  text = 'Success';
  DSPLY text;
ON-ERROR;
  DSPLY 'Nested error';
ENDMON;

*INLR = *ON;
