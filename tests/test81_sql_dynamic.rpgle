**FREE

// Test 81: Dynamic SQL
// Tests PREPARE, EXECUTE, EXECUTE IMMEDIATE

DCL-S sqlStr    VARCHAR(256);
DCL-S empId     INT(10);
DCL-S empName   VARCHAR(50);
DCL-S empSal    PACKED(9:2);

// Create table using EXECUTE IMMEDIATE with host variable
sqlStr = 'CREATE TABLE dyntest (id INTEGER, name VARCHAR(50), salary DECIMAL(9,2))';
EXEC SQL EXECUTE IMMEDIATE :sqlStr;

// Prepare an INSERT statement
sqlStr = 'INSERT INTO dyntest (id, name, salary) VALUES(?, ?, ?)';
EXEC SQL PREPARE INS1 FROM :sqlStr;

// Execute with parameters
empId = 1;
empName = 'Alice';
empSal = 75000.00;
EXEC SQL EXECUTE INS1 USING :empId, :empName, :empSal;

empId = 2;
empName = 'Bob';
empSal = 65000.00;
EXEC SQL EXECUTE INS1 USING :empId, :empName, :empSal;

// Prepare a SELECT
sqlStr = 'SELECT name, salary FROM dyntest WHERE id = ?';
EXEC SQL PREPARE SEL1 FROM :sqlStr;

// Verify data with SELECT INTO
empId = 1;
EXEC SQL SELECT name, salary
  INTO :empName, :empSal
  FROM dyntest WHERE id = :empId;

DSPLY empName;
DSPLY %CHAR(empSal);

// Execute immediate with literal (cleanup)
sqlStr = 'DROP TABLE dyntest';
EXEC SQL EXECUTE IMMEDIATE :sqlStr;

*INLR = *ON;
RETURN;
