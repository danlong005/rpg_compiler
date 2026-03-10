**FREE

// Test 84: SQL Connection Management
// Tests CONNECT (DSN, user/pass, connection string), DISCONNECT, CONNECT RESET

DCL-S dsn       VARCHAR(100);
DCL-S dbUser    VARCHAR(50);
DCL-S dbPass    VARCHAR(50);
DCL-S connStr   VARCHAR(256);
DCL-S empName   VARCHAR(50);
DCL-S empId     INT(10);

// Connect using DSN with user/password
dsn = 'MYDB';
dbUser = 'admin';
dbPass = 'secret';
EXEC SQL CONNECT TO :dsn USER :dbUser USING :dbPass;

// Do some work
empId = 1;
EXEC SQL SELECT name INTO :empName
  FROM employees WHERE id = :empId;

DSPLY empName;

// Disconnect
EXEC SQL DISCONNECT;

// Connect with DSN only (no user/password)
dsn = 'TESTDB';
EXEC SQL CONNECT TO :dsn;

EXEC SQL CREATE TABLE temp_test (id INTEGER);
EXEC SQL DROP TABLE temp_test;

// Disconnect and reconnect using connection string
EXEC SQL DISCONNECT;

connStr = 'Driver={SQLite3};Database=test.db';
EXEC SQL CONNECT USING :connStr;

EXEC SQL CREATE TABLE temp_test2 (id INTEGER);
EXEC SQL DROP TABLE temp_test2;

// Use CONNECT RESET to disconnect
EXEC SQL CONNECT RESET;

*INLR = *ON;
RETURN;
