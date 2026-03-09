**FREE

DCL-PR myProc INT(10);
  p1 INT(10) VALUE;
  p2 INT(10) VALUE;
  p3 INT(10) VALUE;
END-PR;

DCL-S result INT(10);

result = myProc(10 : 20 : 30);
DSPLY %CHAR(result);

*INLR = *ON;

DCL-PROC myProc;
  DCL-PI myProc INT(10);
    p1 INT(10) VALUE;
    p2 INT(10) VALUE;
    p3 INT(10) VALUE;
  END-PI;

  DCL-S numParms INT(10);
  numParms = %PARMS();
  DSPLY %CHAR(numParms);

  RETURN p1 + p2 + p3;
END-PROC;
