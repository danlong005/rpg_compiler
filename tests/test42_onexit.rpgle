**FREE
DCL-PR doWork;
END-PR;

DCL-PROC doWork;
  DCL-PI doWork;
  END-PI;
  DSPLY 'Working';
  ON-EXIT;
    DSPLY 'Cleanup';
END-PROC;

doWork();
DSPLY 'Done';

*INLR = *ON;
