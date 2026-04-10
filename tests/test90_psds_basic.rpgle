**FREE

// Test 90: PSDS — Program Status Data Structure
// Tests that PSDS fields are populated at program start

DCL-DS PgmInfo PSDS QUALIFIED;
  PgmName CHAR(10) POS(81);
  UserID  CHAR(10) POS(91);
  JobNum  CHAR(8)  POS(101);
  RunDate CHAR(8)  POS(109);
  RunTime CHAR(6)  POS(119);
END-DS;

DCL-S len INT(10);

// Program name should be non-empty
IF %TRIM(PgmInfo.PgmName) <> '';
  DSPLY 'PGMNAME SET';
ELSE;
  DSPLY 'PGMNAME EMPTY';
ENDIF;

// User profile should be non-empty
IF %TRIM(PgmInfo.UserID) <> '';
  DSPLY 'USER SET';
ELSE;
  DSPLY 'USER EMPTY';
ENDIF;

// Job number should be 8 characters (PID zero-padded)
len = %LEN(%TRIM(PgmInfo.JobNum));
IF len > 0;
  DSPLY 'JOBNUM SET';
ELSE;
  DSPLY 'JOBNUM EMPTY';
ENDIF;

// Run date should be 8 characters (YYYYMMDD)
IF %LEN(PgmInfo.RunDate) = 8;
  DSPLY 'DATE OK';
ELSE;
  DSPLY 'DATE BAD';
ENDIF;

// Run time should be 6 characters (HHMMSS)
IF %LEN(PgmInfo.RunTime) = 6;
  DSPLY 'TIME OK';
ELSE;
  DSPLY 'TIME BAD';
ENDIF;

*INLR = *ON;
