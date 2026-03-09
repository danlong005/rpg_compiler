**FREE
CTL-OPT MAIN(myMain);

DCL-PROC myMain;
  DCL-PI myMain;
  END-PI;

  DCL-S msg VARCHAR(50);
  msg = 'Hello from MAIN proc';
  DSPLY msg;
  DSPLY 'Done';
END-PROC;
