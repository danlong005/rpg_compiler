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
    std::string NAME;
    int AGE = 0;
    double SALARY = 0.0;
    int EMPID = 0;
    int COUNT = 0;
    // EXEC SQL INSERT INTO employees (name, age) VALUES(:name, :age)
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"INSERT INTO employees (name, age) VALUES(?, ?)", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, NAME);
        __sql_env.bindParam(__hstmt, 2, AGE);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    // EXEC SQL UPDATE employees SET salary = :salary WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"UPDATE employees SET salary = ? WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, SALARY);
        __sql_env.bindParam(__hstmt, 2, EMPID);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
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
    // EXEC SQL SELECT name, age INTO :name, :age FROM employees WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"SELECT name, age  FROM employees WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        char __sql_strbuf_1[4096] = {};
        char __sql_strbuf_2[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__hstmt, 1, NAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLLEN __sql_ind_2 = 0;
        __sql_env.bindCol(__hstmt, 2, AGE, __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
        SQLExecute(__hstmt);
        SQLRETURN __frc = SQLFetch(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __frc);
        RpgSqlEnv::copyStrBuf(NAME, __sql_strbuf_1, __frc);
        RpgSqlEnv::copyStrBuf(AGE, __sql_strbuf_2, __frc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    // EXEC SQL COMMIT
    __sql_env.commit();
    // EXEC SQL ROLLBACK
    __sql_env.rollback();
    // EXEC SQL SELECT COUNT(*) INTO :count FROM employees
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"SELECT COUNT(*)  FROM employees", SQL_NTS);
        char __sql_strbuf_1[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__hstmt, 1, COUNT, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLExecute(__hstmt);
        SQLRETURN __frc = SQLFetch(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __frc);
        RpgSqlEnv::copyStrBuf(COUNT, __sql_strbuf_1, __frc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    std::cout << rpg_to_char(COUNT) << std::endl;
    return 0;
}
