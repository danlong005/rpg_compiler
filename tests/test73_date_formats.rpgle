**FREE
CTL-OPT DATFMT(*JUL);

DCL-S myDate DATE;
DCL-S result VARCHAR(20);

myDate = %DATE('2024-03-15');

// With DATFMT(*JUL), %CHAR should output Julian format
// 2024-03-15 is day 75 of 2024 (leap year)
result = %CHAR(myDate);
DSPLY result;

*INLR = *ON;
