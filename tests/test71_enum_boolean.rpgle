**FREE
DCL-S isActive BOOLEAN;
DCL-S status INT(10);

DCL-ENUM Colors QUALIFIED;
  RED = 1;
  GREEN = 2;
  BLUE = 3;
END-ENUM;

// BOOLEAN is an alias for IND
isActive = *ON;
IF isActive;
  DSPLY 'Active';
ENDIF;

isActive = *OFF;
IF NOT isActive;
  DSPLY 'Inactive';
ENDIF;

// Enum usage
status = 2;
IF status = Colors.GREEN;
  DSPLY 'Green';
ENDIF;

*INLR = *ON;
