**FREE
DCL-PR getCount INT(10);
END-PR;

DCL-PROC getCount;
  DCL-PI getCount INT(10);
  END-PI;
  DCL-S counter INT(10) STATIC;
  counter = counter + 1;
  RETURN counter;
END-PROC;

DSPLY %CHAR(getCount());
DSPLY %CHAR(getCount());
DSPLY %CHAR(getCount());

*INLR = *ON;
