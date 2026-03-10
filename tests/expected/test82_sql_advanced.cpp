#include "rpg_runtime.h"
#include "rpg_sql_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
static RpgSqlEnv __sql_env;

int main() {
    bool rpg_indicators[100] = {};
    int EMPID = 0;
    std::string EMPNAME;
    double EMPSAL = 0.0;
    int ROWCOUNT = 0;
    int RETSTATUS = 0;
    std::string PARAM1;
    int PARAM2 = 0;
    // EXEC SQL CREATE TABLE advtest (   id INTEGER PRIMARY KEY,   name VARCHAR(50),   salary DECIMAL(9,2) )
    __sql_env.execDirect("CREATE TABLE advtest (   id INTEGER PRIMARY KEY,   name VARCHAR(50),   salary DECIMAL(9,2) )");
    EMPID = 1; // line 22
    EMPNAME = "Alice"; // line 23
    EMPSAL = 75000.0; // line 24
    // EXEC SQL INSERT INTO advtest (id, name, salary)   VALUES(:empId, :empName, :empSal)
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"INSERT INTO advtest (id, name, salary)   VALUES(?, ?, ?)", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        __sql_env.bindParam(__hstmt, 2, EMPNAME);
        __sql_env.bindParam(__hstmt, 3, EMPSAL);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    EMPID = 2; // line 28
    EMPNAME = "Bob"; // line 29
    EMPSAL = 65000.0; // line 30
    // EXEC SQL INSERT INTO advtest (id, name, salary)   VALUES(:empId, :empName, :empSal)
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"INSERT INTO advtest (id, name, salary)   VALUES(?, ?, ?)", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        __sql_env.bindParam(__hstmt, 2, EMPNAME);
        __sql_env.bindParam(__hstmt, 3, EMPSAL);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    EMPID = 3; // line 34
    EMPNAME = "Charlie"; // line 35
    EMPSAL = 90000.0; // line 36
    // EXEC SQL INSERT INTO advtest (id, name, salary)   VALUES(:empId, :empName, :empSal)
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"INSERT INTO advtest (id, name, salary)   VALUES(?, ?, ?)", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        __sql_env.bindParam(__hstmt, 2, EMPNAME);
        __sql_env.bindParam(__hstmt, 3, EMPSAL);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    // EXEC SQL UPDATE advtest SET salary = salary * 1.1   WHERE salary < 80000
    __sql_env.execDirect("UPDATE advtest SET salary = salary * 1.1   WHERE salary < 80000");
    // EXEC SQL GET DIAGNOSTICS :rowCount = ROW_COUNT
    ROWCOUNT = static_cast<int>(__sql_env.row_count);
    std::cout << rpg_to_char(ROWCOUNT) << std::endl;
    // EXEC SQL SAVEPOINT sp1
    __sql_env.execDirect("SAVEPOINT sp1");
    // EXEC SQL DELETE FROM advtest WHERE id = 3
    __sql_env.execDirect("DELETE FROM advtest WHERE id = 3");
    // EXEC SQL GET DIAGNOSTICS :rowCount = ROW_COUNT
    ROWCOUNT = static_cast<int>(__sql_env.row_count);
    std::cout << rpg_to_char(ROWCOUNT) << std::endl;
    // EXEC SQL ROLLBACK TO SAVEPOINT sp1
    __sql_env.execDirect("ROLLBACK TO SAVEPOINT sp1");
    PARAM1 = "test_value"; // line 57
    PARAM2 = 42; // line 58
    // EXEC SQL CALL myproc(:param1, :param2)
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"{CALL myproc(?, ?)}", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, PARAM1);
        __sql_env.bindParam(__hstmt, 2, PARAM2);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    // EXEC SQL GET DIAGNOSTICS :retStatus = RETURN_STATUS
    RETSTATUS = __sql_env.sqlcode;
    std::cout << rpg_to_char(RETSTATUS) << std::endl;
    // EXEC SQL DROP TABLE advtest
    __sql_env.execDirect("DROP TABLE advtest");
    return 0;
    return 0;
}
