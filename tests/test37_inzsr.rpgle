**FREE
DCL-S counter INT(10);
DCL-S greeting VARCHAR(30);

// Main code runs after *INZSR
DSPLY greeting;
DSPLY %CHAR(counter);

*INLR = *ON;

// *INZSR runs automatically at program start
BEGSR *INZSR;
  greeting = 'Initialized!';
  counter = 42;
ENDSR;
