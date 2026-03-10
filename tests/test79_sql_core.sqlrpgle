**FREE

// Test 79: Core SQL statements with SQLCODE/SQLSTATE
// Tests INSERT, UPDATE, DELETE, SELECT INTO, COMMIT, ROLLBACK
// and SQLCOD/SQLSTT diagnostic variables

DCL-S empName   VARCHAR(50);
DCL-S empAge    INT(10);
DCL-S empSal    PACKED(9:2);
DCL-S empId     INT(10);
DCL-S empCount  INT(10);
DCL-S sqlStatus INT(10);
DCL-S sqlSt     CHAR(5);

// Create table (uses general SQL passthrough)
EXEC SQL CREATE TABLE employees (
  id INTEGER PRIMARY KEY,
  name VARCHAR(50),
  age INTEGER,
  salary DECIMAL(9,2)
);

// Insert with host variables
empId = 1;
empName = 'Alice';
empAge = 30;
empSal = 75000.00;
EXEC SQL INSERT INTO employees (id, name, age, salary)
  VALUES(:empId, :empName, :empAge, :empSal);

// Check SQLCODE after insert
sqlStatus = SQLCOD;

// Insert another row
empId = 2;
empName = 'Bob';
empAge = 25;
empSal = 65000.00;
EXEC SQL INSERT INTO employees (id, name, age, salary)
  VALUES(:empId, :empName, :empAge, :empSal);

// Update with host variables
empSal = 80000.00;
empId = 1;
EXEC SQL UPDATE employees SET salary = :empSal WHERE id = :empId;

// Delete with host variable
empId = 2;
EXEC SQL DELETE FROM employees WHERE id = :empId;

// SELECT INTO - single row
empId = 1;
EXEC SQL SELECT name, age, salary
  INTO :empName, :empAge, :empSal
  FROM employees WHERE id = :empId;

// Check SQLSTATE after select
sqlSt = SQLSTT;

DSPLY empName;
DSPLY %CHAR(empAge);
DSPLY %CHAR(empSal);

// SELECT INTO - count
EXEC SQL SELECT COUNT(*) INTO :empCount FROM employees;
DSPLY %CHAR(empCount);

// SELECT INTO - not found (should set SQLCODE = 100)
empId = 999;
EXEC SQL SELECT name INTO :empName FROM employees WHERE id = :empId;
sqlStatus = SQLCOD;
DSPLY %CHAR(sqlStatus);

// Transaction control
EXEC SQL COMMIT;
EXEC SQL ROLLBACK;

// Cleanup
EXEC SQL DROP TABLE employees;

*INLR = *ON;
