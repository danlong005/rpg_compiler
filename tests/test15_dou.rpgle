**FREE
DCL-S i INT(10);
DCL-S sum INT(10);

// DOU loop - executes body first, then checks condition
i = 1;
sum = 0;
DOU i > 5;
  sum = sum + i;
  i = i + 1;
ENDDO;
DSPLY %CHAR(sum);

// DOU always executes at least once (condition already true)
i = 10;
sum = 0;
DOU i > 5;
  sum = sum + i;
  i = i + 1;
  IF i > 12;
    LEAVE;
  ENDIF;
ENDDO;
DSPLY %CHAR(sum);

*INLR = *ON;
