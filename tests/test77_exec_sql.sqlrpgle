**FREE

// Test 77: Embedded SQL — parsing and code generation
// Tests that EXEC SQL statements parse correctly and generate valid C++

DCL-S name    VARCHAR(50);
DCL-S age     INT(10);
DCL-S salary  PACKED(9:2);
DCL-S empId   INT(10);
DCL-S count   INT(10);

// Simple INSERT with host variables
EXEC SQL INSERT INTO employees (name, age) VALUES(:name, :age);

// Simple UPDATE
EXEC SQL UPDATE employees SET salary = :salary WHERE id = :empId;

// Simple DELETE
EXEC SQL DELETE FROM employees WHERE id = :empId;

// SELECT INTO with host variables
EXEC SQL SELECT name, age INTO :name, :age FROM employees WHERE id = :empId;

// COMMIT and ROLLBACK
EXEC SQL COMMIT;
EXEC SQL ROLLBACK;

// Simple SELECT without host variables
EXEC SQL SELECT COUNT(*) INTO :count FROM employees;

DSPLY %CHAR(count);

*INLR = *ON;
