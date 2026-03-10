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
    int EMPAGE = 0;
    double EMPSAL = 0.0;
    // EXEC SQL CREATE TABLE employees (   id INTEGER PRIMARY KEY,   name VARCHAR(50),   age INTEGER,   salary DECIMAL(9,2) )
    __sql_env.execDirect("CREATE TABLE employees (   id INTEGER PRIMARY KEY,   name VARCHAR(50),   age INTEGER,   salary DECIMAL(9,2) )");
    EMPID = 1; // line 20
    EMPNAME = "Alice"; // line 21
    EMPAGE = 30; // line 22
    EMPSAL = 75000.0; // line 23
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
    EMPID = 2; // line 27
    EMPNAME = "Bob"; // line 28
    EMPAGE = 25; // line 29
    EMPSAL = 65000.0; // line 30
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
    EMPID = 3; // line 34
    EMPNAME = "Charlie"; // line 35
    EMPAGE = 35; // line 36
    EMPSAL = 90000.0; // line 37
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
    // EXEC SQL DECLARE empCur CURSOR FOR   SELECT name, age, salary FROM employees   ORDER BY id
    __sql_env.declareCursor("EMPCUR", "SELECT name, age, salary FROM employees   ORDER BY id");
    // EXEC SQL OPEN empCur
    __sql_env.openCursor("EMPCUR");
    // EXEC SQL FETCH empCur INTO :empName, :empAge, :empSal
    {
        SQLHSTMT __cstmt = __sql_env.getCursorStmt("EMPCUR");
        char __sql_strbuf_1[4096] = {};
        char __sql_strbuf_2[4096] = {};
        char __sql_strbuf_3[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__cstmt, 1, EMPNAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLLEN __sql_ind_2 = 0;
        __sql_env.bindCol(__cstmt, 2, EMPAGE, __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
        SQLLEN __sql_ind_3 = 0;
        __sql_env.bindCol(__cstmt, 3, EMPSAL, __sql_strbuf_3, sizeof(__sql_strbuf_3), __sql_ind_3);
        SQLRETURN __frc = SQLFetch(__cstmt);
        __sql_env.updateStmtDiag(__cstmt, __frc);
        RpgSqlEnv::copyStrBuf(EMPNAME, __sql_strbuf_1, __frc);
        RpgSqlEnv::copyStrBuf(EMPAGE, __sql_strbuf_2, __frc);
        RpgSqlEnv::copyStrBuf(EMPSAL, __sql_strbuf_3, __frc);
    }
    while (__sql_env.sqlcode == 0) {
        std::cout << EMPNAME << std::endl;
        std::cout << rpg_to_char(EMPAGE) << std::endl;
        std::cout << rpg_to_char(EMPSAL) << std::endl;
        // EXEC SQL FETCH empCur INTO :empName, :empAge, :empSal
        {
            SQLHSTMT __cstmt = __sql_env.getCursorStmt("EMPCUR");
            char __sql_strbuf_1[4096] = {};
            char __sql_strbuf_2[4096] = {};
            char __sql_strbuf_3[4096] = {};
            SQLLEN __sql_ind_1 = 0;
            __sql_env.bindCol(__cstmt, 1, EMPNAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
            SQLLEN __sql_ind_2 = 0;
            __sql_env.bindCol(__cstmt, 2, EMPAGE, __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
            SQLLEN __sql_ind_3 = 0;
            __sql_env.bindCol(__cstmt, 3, EMPSAL, __sql_strbuf_3, sizeof(__sql_strbuf_3), __sql_ind_3);
            SQLRETURN __frc = SQLFetch(__cstmt);
            __sql_env.updateStmtDiag(__cstmt, __frc);
            RpgSqlEnv::copyStrBuf(EMPNAME, __sql_strbuf_1, __frc);
            RpgSqlEnv::copyStrBuf(EMPAGE, __sql_strbuf_2, __frc);
            RpgSqlEnv::copyStrBuf(EMPSAL, __sql_strbuf_3, __frc);
        }
    }
    // EXEC SQL CLOSE empCur
    __sql_env.closeCursor("EMPCUR");
    // EXEC SQL DECLARE salCur CURSOR FOR   SELECT name, salary FROM employees   WHERE salary > :empSal
    __sql_env.declareCursor("SALCUR", "SELECT name, salary FROM employees   WHERE salary > ?");
    EMPSAL = 70000.0; // line 66
    // EXEC SQL OPEN salCur
    {
        SQLHSTMT __cstmt = __sql_env.getCursorStmt("SALCUR");
        __sql_env.clearParamBufs();
        __sql_env.bindParam(__cstmt, 1, EMPSAL);
    }
    __sql_env.openCursor("SALCUR");
    // EXEC SQL FETCH salCur INTO :empName, :empSal
    {
        SQLHSTMT __cstmt = __sql_env.getCursorStmt("SALCUR");
        char __sql_strbuf_1[4096] = {};
        char __sql_strbuf_2[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__cstmt, 1, EMPNAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLLEN __sql_ind_2 = 0;
        __sql_env.bindCol(__cstmt, 2, EMPSAL, __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
        SQLRETURN __frc = SQLFetch(__cstmt);
        __sql_env.updateStmtDiag(__cstmt, __frc);
        RpgSqlEnv::copyStrBuf(EMPNAME, __sql_strbuf_1, __frc);
        RpgSqlEnv::copyStrBuf(EMPSAL, __sql_strbuf_2, __frc);
    }
    while (__sql_env.sqlcode == 0) {
        std::cout << EMPNAME << std::endl;
        std::cout << rpg_to_char(EMPSAL) << std::endl;
        // EXEC SQL FETCH salCur INTO :empName, :empSal
        {
            SQLHSTMT __cstmt = __sql_env.getCursorStmt("SALCUR");
            char __sql_strbuf_1[4096] = {};
            char __sql_strbuf_2[4096] = {};
            SQLLEN __sql_ind_1 = 0;
            __sql_env.bindCol(__cstmt, 1, EMPNAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
            SQLLEN __sql_ind_2 = 0;
            __sql_env.bindCol(__cstmt, 2, EMPSAL, __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
            SQLRETURN __frc = SQLFetch(__cstmt);
            __sql_env.updateStmtDiag(__cstmt, __frc);
            RpgSqlEnv::copyStrBuf(EMPNAME, __sql_strbuf_1, __frc);
            RpgSqlEnv::copyStrBuf(EMPSAL, __sql_strbuf_2, __frc);
        }
    }
    // EXEC SQL CLOSE salCur
    __sql_env.closeCursor("SALCUR");
    // EXEC SQL DROP TABLE employees
    __sql_env.execDirect("DROP TABLE employees");
    return 0;
    return 0;
}
