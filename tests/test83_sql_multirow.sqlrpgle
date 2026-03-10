**FREE

// Test 83: Multiple-row FETCH and INSERT
// Tests FOR :n ROWS syntax

DCL-S ids       INT(10) DIM(10);
DCL-S names     VARCHAR(50) DIM(10);
DCL-S salaries  PACKED(9:2) DIM(10);
DCL-S nRows     INT(10);
DCL-S i         INT(10);

// Create table
EXEC SQL CREATE TABLE mrtest (
  id INTEGER,
  name VARCHAR(50),
  salary DECIMAL(9,2)
);

// Populate with single inserts
ids(1) = 1;
names(1) = 'Alice';
salaries(1) = 75000.00;
ids(2) = 2;
names(2) = 'Bob';
salaries(2) = 65000.00;
ids(3) = 3;
names(3) = 'Charlie';
salaries(3) = 90000.00;

// Multi-row INSERT
nRows = 3;
EXEC SQL INSERT INTO mrtest (id, name, salary)
  VALUES(:ids, :names, :salaries)
  FOR :nRows ROWS;

// Declare cursor for reading back
EXEC SQL DECLARE mrCur CURSOR FOR
  SELECT id, name, salary FROM mrtest ORDER BY id;

EXEC SQL OPEN mrCur;

// Multi-row FETCH
nRows = 10;
EXEC SQL FETCH mrCur FOR :nRows ROWS
  INTO :ids, :names, :salaries;

EXEC SQL CLOSE mrCur;

// Display results
FOR i = 1 TO 3;
  DSPLY %CHAR(ids(i));
  DSPLY names(i);
  DSPLY %CHAR(salaries(i));
ENDFOR;

// Cleanup
EXEC SQL DROP TABLE mrtest;

*INLR = *ON;
RETURN;
