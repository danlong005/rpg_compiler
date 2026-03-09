**FREE
DCL-S myDate DATE;
DCL-S valid IND;

// TEST(D) - test if date is valid
myDate = %DATE('2024-03-15');
TEST(D) myDate;
valid = NOT %ERROR();
IF valid;
  DSPLY 'Date valid';
ENDIF;

DSPLY 'Test done';

*INLR = *ON;
