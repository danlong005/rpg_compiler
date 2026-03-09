**FREE
DCL-S i INT(10);
DCL-S sum INT(10);

// FOR loop
sum = 0;
FOR i = 1 TO 5;
  sum = sum + i;
ENDFOR;
DSPLY %CHAR(sum);

// FOR with BY
sum = 0;
FOR i = 0 TO 10 BY 2;
  sum = sum + i;
ENDFOR;
DSPLY %CHAR(sum);

// DOWNTO
sum = 0;
FOR i = 5 DOWNTO 1;
  sum = sum + i;
ENDFOR;
DSPLY %CHAR(sum);

// DOW loop
i = 1;
sum = 0;
DOW i <= 5;
  sum = sum + i;
  i = i + 1;
ENDDO;
DSPLY %CHAR(sum);

// ITER and LEAVE
sum = 0;
FOR i = 1 TO 10;
  IF i = 3;
    ITER;
  ENDIF;
  IF i = 7;
    LEAVE;
  ENDIF;
  sum = sum + i;
ENDFOR;
DSPLY %CHAR(sum);
*INLR = *ON;
