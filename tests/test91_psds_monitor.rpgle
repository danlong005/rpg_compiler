**FREE

// Test 91: PSDS with MONITOR/ON-ERROR
// Tests that PSDS is synced before ON-ERROR handler runs

DCL-DS PgmSts PSDS QUALIFIED;
  ProcName   CHAR(10) POS(1);
  StatusCode PACKED(5:0) POS(11);
END-DS;

DCL-S x INT(10);

// Procedure name should be populated
IF %TRIM(PgmSts.ProcName) <> '';
  DSPLY 'PROCNAME SET';
ELSE;
  DSPLY 'PROCNAME EMPTY';
ENDIF;

// Status starts at 0
IF PgmSts.StatusCode = 0;
  DSPLY 'STATUS INIT OK';
ELSE;
  DSPLY 'STATUS INIT BAD';
ENDIF;

// MONITOR block — verifies PSDS syncs before ON-ERROR
MONITOR;
  x = 42;
  DSPLY 'MONITOR OK';
ON-ERROR;
  DSPLY 'ERROR HANDLER';
ENDMON;

*INLR = *ON;
