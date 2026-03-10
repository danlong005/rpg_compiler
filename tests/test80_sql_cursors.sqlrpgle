**FREE

// Test 80: SQL Cursor Operations
// Tests DECLARE CURSOR, OPEN, FETCH, CLOSE

DCL-S empId     INT(10);
DCL-S empName   VARCHAR(50);
DCL-S empAge    INT(10);
DCL-S empSal    PACKED(9:2);

// Create test table
EXEC SQL CREATE TABLE employees (
  id INTEGER PRIMARY KEY,
  name VARCHAR(50),
  age INTEGER,
  salary DECIMAL(9,2)
);

// Insert test data
empId = 1;
empName = 'Alice';
empAge = 30;
empSal = 75000.00;
EXEC SQL INSERT INTO employees (id, name, age, salary)
  VALUES(:empId, :empName, :empAge, :empSal);

empId = 2;
empName = 'Bob';
empAge = 25;
empSal = 65000.00;
EXEC SQL INSERT INTO employees (id, name, age, salary)
  VALUES(:empId, :empName, :empAge, :empSal);

empId = 3;
empName = 'Charlie';
empAge = 35;
empSal = 90000.00;
EXEC SQL INSERT INTO employees (id, name, age, salary)
  VALUES(:empId, :empName, :empAge, :empSal);

// Declare a cursor for all employees ordered by id
EXEC SQL DECLARE empCur CURSOR FOR
  SELECT name, age, salary FROM employees
  ORDER BY id;

// Open cursor
EXEC SQL OPEN empCur;

// Fetch rows in a loop
EXEC SQL FETCH empCur INTO :empName, :empAge, :empSal;
DOW SQLCOD = 0;
  DSPLY empName;
  DSPLY %CHAR(empAge);
  DSPLY %CHAR(empSal);
  EXEC SQL FETCH empCur INTO :empName, :empAge, :empSal;
ENDDO;

// Close cursor
EXEC SQL CLOSE empCur;

// Declare cursor with host variable in query
EXEC SQL DECLARE salCur CURSOR FOR
  SELECT name, salary FROM employees
  WHERE salary > :empSal;

empSal = 70000.00;
EXEC SQL OPEN salCur;

EXEC SQL FETCH salCur INTO :empName, :empSal;
DOW SQLCOD = 0;
  DSPLY empName;
  DSPLY %CHAR(empSal);
  EXEC SQL FETCH salCur INTO :empName, :empSal;
ENDDO;

EXEC SQL CLOSE salCur;

// Cleanup
EXEC SQL DROP TABLE employees;

*INLR = *ON;
RETURN;
