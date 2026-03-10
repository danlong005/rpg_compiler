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
    std::string EMPNAME;
    int EMPAGE = 0;
    double EMPSAL = 0.0;
    int EMPID = 0;
    int EMPCOUNT = 0;
    int SQLSTATUS = 0;
    std::string SQLST(5, ' ');
    // EXEC SQL CREATE TABLE employees (   id INTEGER PRIMARY KEY,   name VARCHAR(50),   age INTEGER,   salary DECIMAL(9,2) )
    __sql_env.execDirect("CREATE TABLE employees (   id INTEGER PRIMARY KEY,   name VARCHAR(50),   age INTEGER,   salary DECIMAL(9,2) )");
    EMPID = 1; // line 24
    EMPNAME = "Alice"; // line 25
    EMPAGE = 30; // line 26
    EMPSAL = 75000.0; // line 27
    // EXEC SQL INSERT INTO employees (id, name, age, salary)   VALUES(:empId, :empName, :empAge, :empSal)
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"INSERT INTO employees (id, name, age, salary)   VALUES(?, ?, ?, ?)", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        __sql_env.bindParam(__hstmt, 2, EMPNAME);
        __sql_env.bindParam(__hstmt, 3, EMPAGE);
        __sql_env.bindParam(__hstmt, 4, EMPSAL);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    SQLSTATUS = __sql_env.sqlcode; // line 32
    EMPID = 2; // line 35
    EMPNAME = "Bob"; // line 36
    EMPAGE = 25; // line 37
    EMPSAL = 65000.0; // line 38
    // EXEC SQL INSERT INTO employees (id, name, age, salary)   VALUES(:empId, :empName, :empAge, :empSal)
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"INSERT INTO employees (id, name, age, salary)   VALUES(?, ?, ?, ?)", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        __sql_env.bindParam(__hstmt, 2, EMPNAME);
        __sql_env.bindParam(__hstmt, 3, EMPAGE);
        __sql_env.bindParam(__hstmt, 4, EMPSAL);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    EMPSAL = 80000.0; // line 43
    EMPID = 1; // line 44
    // EXEC SQL UPDATE employees SET salary = :empSal WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"UPDATE employees SET salary = ? WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPSAL);
        __sql_env.bindParam(__hstmt, 2, EMPID);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    EMPID = 2; // line 48
    // EXEC SQL DELETE FROM employees WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"DELETE FROM employees WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    EMPID = 1; // line 52
    // EXEC SQL SELECT name, age, salary   INTO :empName, :empAge, :empSal   FROM employees WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"SELECT name, age, salary    FROM employees WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        char __sql_strbuf_1[4096] = {};
        char __sql_strbuf_2[4096] = {};
        char __sql_strbuf_3[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__hstmt, 1, EMPNAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLLEN __sql_ind_2 = 0;
        __sql_env.bindCol(__hstmt, 2, EMPAGE, __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
        SQLLEN __sql_ind_3 = 0;
        __sql_env.bindCol(__hstmt, 3, EMPSAL, __sql_strbuf_3, sizeof(__sql_strbuf_3), __sql_ind_3);
        SQLExecute(__hstmt);
        SQLRETURN __frc = SQLFetch(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __frc);
        RpgSqlEnv::copyStrBuf(EMPNAME, __sql_strbuf_1, __frc);
        RpgSqlEnv::copyStrBuf(EMPAGE, __sql_strbuf_2, __frc);
        RpgSqlEnv::copyStrBuf(EMPSAL, __sql_strbuf_3, __frc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    SQLST = __sql_env.sqlstate; // line 58
    std::cout << EMPNAME << std::endl;
    std::cout << rpg_to_char(EMPAGE) << std::endl;
    std::cout << rpg_to_char(EMPSAL) << std::endl;
    // EXEC SQL SELECT COUNT(*) INTO :empCount FROM employees
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"SELECT COUNT(*)  FROM employees", SQL_NTS);
        char __sql_strbuf_1[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__hstmt, 1, EMPCOUNT, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLExecute(__hstmt);
        SQLRETURN __frc = SQLFetch(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __frc);
        RpgSqlEnv::copyStrBuf(EMPCOUNT, __sql_strbuf_1, __frc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    std::cout << rpg_to_char(EMPCOUNT) << std::endl;
    EMPID = 999; // line 69
    // EXEC SQL SELECT name INTO :empName FROM employees WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"SELECT name  FROM employees WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        char __sql_strbuf_1[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__hstmt, 1, EMPNAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLExecute(__hstmt);
        SQLRETURN __frc = SQLFetch(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __frc);
        RpgSqlEnv::copyStrBuf(EMPNAME, __sql_strbuf_1, __frc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    SQLSTATUS = __sql_env.sqlcode; // line 71
    std::cout << rpg_to_char(SQLSTATUS) << std::endl;
    // EXEC SQL COMMIT
    __sql_env.commit();
    // EXEC SQL ROLLBACK
    __sql_env.rollback();
    // EXEC SQL DROP TABLE employees
    __sql_env.execDirect("DROP TABLE employees");
    return 0;
}
