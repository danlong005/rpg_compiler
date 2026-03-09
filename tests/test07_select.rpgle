**FREE
DCL-S day INT(10);
DCL-S name VARCHAR(20);

day = 3;
SELECT;
  WHEN day = 1;
    name = 'Monday';
  WHEN day = 2;
    name = 'Tuesday';
  WHEN day = 3;
    name = 'Wednesday';
  OTHER;
    name = 'Other';
ENDSL;
DSPLY name;

day = 99;
SELECT;
  WHEN day = 1;
    name = 'Monday';
  OTHER;
    name = 'Unknown';
ENDSL;
DSPLY name;
*INLR = *ON;
