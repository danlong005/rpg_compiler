#include "rpg_runtime.h"
#include "rpg_sql_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
static RpgSqlEnv __sql_env;

std::string GETEMPLOYEENAME(int EMPID) {
    std::string EMPNAME;
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
    return EMPNAME;
}
void UPDATESALARY(int EMPID, double AMOUNT) {
    // EXEC SQL UPDATE employees SET salary = salary + :amount WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"UPDATE employees SET salary = salary + ? WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, AMOUNT);
        __sql_env.bindParam(__hstmt, 2, EMPID);
        SQLRETURN __erc = SQLExecute(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __erc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    // EXEC SQL COMMIT
    __sql_env.commit();
}
int main() {
    bool rpg_indicators[100] = {};
    std::string RESULT;
    RESULT = "Test 78 passed"; // line 31
    std::cout << RESULT << std::endl;
    return 0;
}
