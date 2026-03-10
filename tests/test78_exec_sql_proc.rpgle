**FREE

// Test 78: Embedded SQL in procedures and mixed with regular code

DCL-S result VARCHAR(100);

DCL-PROC GetEmployeeName;
  DCL-PI VARCHAR(100);
    empId INT(10) VALUE;
  END-PI;

  DCL-S empName VARCHAR(100);

  EXEC SQL SELECT name INTO :empName FROM employees WHERE id = :empId;

  RETURN empName;
END-PROC;

DCL-PROC UpdateSalary;
  DCL-PI;
    empId  INT(10) VALUE;
    amount PACKED(9:2) VALUE;
  END-PI;

  EXEC SQL UPDATE employees SET salary = salary + :amount WHERE id = :empId;
  EXEC SQL COMMIT;

END-PROC;

// No SQL in main body - just regular code
result = 'Test 78 passed';
DSPLY result;

*INLR = *ON;
