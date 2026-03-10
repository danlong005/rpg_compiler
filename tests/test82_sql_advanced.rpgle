**FREE

// Test 82: Advanced SQL Features
// Tests GET DIAGNOSTICS, CALL, SAVEPOINT

DCL-S empId     INT(10);
DCL-S empName   VARCHAR(50);
DCL-S empSal    PACKED(9:2);
DCL-S rowCount  INT(10);
DCL-S retStatus INT(10);
DCL-S param1    VARCHAR(50);
DCL-S param2    INT(10);

// Create test table
EXEC SQL CREATE TABLE advtest (
  id INTEGER PRIMARY KEY,
  name VARCHAR(50),
  salary DECIMAL(9,2)
);

// Insert some rows
empId = 1;
empName = 'Alice';
empSal = 75000.00;
EXEC SQL INSERT INTO advtest (id, name, salary)
  VALUES(:empId, :empName, :empSal);

empId = 2;
empName = 'Bob';
empSal = 65000.00;
EXEC SQL INSERT INTO advtest (id, name, salary)
  VALUES(:empId, :empName, :empSal);

empId = 3;
empName = 'Charlie';
empSal = 90000.00;
EXEC SQL INSERT INTO advtest (id, name, salary)
  VALUES(:empId, :empName, :empSal);

// Test GET DIAGNOSTICS with ROW_COUNT
EXEC SQL UPDATE advtest SET salary = salary * 1.1
  WHERE salary < 80000;
EXEC SQL GET DIAGNOSTICS :rowCount = ROW_COUNT;
DSPLY %CHAR(rowCount);

// Test SAVEPOINT
EXEC SQL SAVEPOINT sp1;

EXEC SQL DELETE FROM advtest WHERE id = 3;
EXEC SQL GET DIAGNOSTICS :rowCount = ROW_COUNT;
DSPLY %CHAR(rowCount);

// Rollback to savepoint
EXEC SQL ROLLBACK TO SAVEPOINT sp1;

// Test CALL (stored procedure syntax)
param1 = 'test_value';
param2 = 42;
EXEC SQL CALL myproc(:param1, :param2);

// Test GET DIAGNOSTICS with RETURN_STATUS
EXEC SQL GET DIAGNOSTICS :retStatus = RETURN_STATUS;
DSPLY %CHAR(retStatus);

// Cleanup
EXEC SQL DROP TABLE advtest;

*INLR = *ON;
RETURN;
