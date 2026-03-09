**FREE
/DEFINE USE_GREETING
/DEFINE DEBUG_MODE

DCL-S msg VARCHAR(50);

/IF DEFINED(USE_GREETING)
msg = 'Greeting enabled';
DSPLY msg;
/ENDIF

/IF DEFINED(MISSING_SYMBOL)
msg = 'Should not appear';
DSPLY msg;
/ENDIF

/IF NOT DEFINED(MISSING_SYMBOL)
msg = 'Not defined works';
DSPLY msg;
/ENDIF

/IF DEFINED(DEBUG_MODE)
msg = 'Debug on';
/ELSE
msg = 'Debug off';
/ENDIF
DSPLY msg;

/UNDEFINE DEBUG_MODE

/IF DEFINED(DEBUG_MODE)
msg = 'Should not appear';
DSPLY msg;
/ENDIF

/IF NOT DEFINED(DEBUG_MODE)
msg = 'Undef worked';
DSPLY msg;
/ENDIF

*INLR = *ON;
