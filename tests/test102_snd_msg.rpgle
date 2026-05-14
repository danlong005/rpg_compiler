**FREE

// Test 102: SND-MSG — send messages to stderr

DCL-S msg VARCHAR(100);

// *INFO — informational message
SND-MSG *INFO 'Starting process';

// *DIAG — diagnostic message
msg = 'Diagnostic: value out of range';
SND-MSG *DIAG msg;

// TYPE(*INFO) keyword form
SND-MSG TYPE(*INFO) 'Processing complete';

// Plain form — defaults to *INFO
SND-MSG 'Default info message';

// *ESCAPE inside MONITOR — should be caught
MONITOR;
  SND-MSG *ESCAPE 'Something went wrong';
ON-ERROR;
  DSPLY 'Caught escape message';
ENDMON;

DSPLY 'Done';

RETURN;
