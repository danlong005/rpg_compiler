**FREE
DCL-S num1 PACKED(7:2);
DCL-S num2 PACKED(7:2);
DCL-S result VARCHAR(20);

num1 = 12345.67;
num2 = -1234.56;

// %EDITC with edit code '1' - commas, no sign
result = %EDITC(num1 : '1');
DSPLY result;

// %EDITC with edit code '2' - no commas, no sign
result = %EDITC(num1 : '2');
DSPLY result;

// %EDITC with edit code '3' - commas, sign CR
result = %EDITC(num2 : '3');
DSPLY result;

// %EDITC with edit code '4' - no commas, sign CR
result = %EDITC(num2 : '4');
DSPLY result;

// %EDITC with edit code 'X' - all leading zeros shown
result = %EDITC(num1 : 'X');
DSPLY result;

// %EDITW with edit word
result = %EDITW(num1 : '  ,   .  ');
DSPLY result;

*INLR = *ON;
