**FREE
// test_exfmt.rpgle — integration test for DCL-F WORKSTN + EXFMT
//
// Compile:
//   dspfc tests/CUSTMENU.dspf        (produces CUSTMENU.dspfd + CUSTMENU_dspf.h)
//   rpgc  tests/test_exfmt.rpgle     (links CUSTMENU.dspfd at runtime)

DCL-F CUSTMENU WORKSTN;

DCL-S choice CHAR(1);

// Display the main menu and wait for user selection
EXFMT MAINMENU;

IF *IN03;
  DSPLY 'F3 pressed — exiting';
ELSE;
  choice = OPTION;
  DSPLY ('You selected option: ' + choice);

  IF choice = '1';
    // Populate CUSTDSP and show the customer record
    CUSTNO   = 'ACME001   ';
    CUSTNAME = 'ACME Corporation                                  ';
    CUSTBAL  = 12345.67;
    ERRMSG   = ' ';

    EXFMT CUSTDSP;

    IF *IN03;
      DSPLY 'F3 — back to menu';
    ELSEIF *IN06;
      DSPLY ('Saving customer: ' + %TRIM(CUSTNO));
    ELSEIF *IN12;
      DSPLY 'Cancelled';
    ENDIF;
  ENDIF;
ENDIF;

*INLR = *ON;
