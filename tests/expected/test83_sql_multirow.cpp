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
    std::array<int, 10> IDS;
    std::array<std::string, 10> NAMES;
    std::array<double, 10> SALARIES;
    int NROWS = 0;
    int I = 0;
    // EXEC SQL CREATE TABLE mrtest (   id INTEGER,   name VARCHAR(50),   salary DECIMAL(9,2) )
    __sql_env.execDirect("CREATE TABLE mrtest (   id INTEGER,   name VARCHAR(50),   salary DECIMAL(9,2) )");
    IDS[1 - 1] = 1; // line 20
    NAMES[1 - 1] = "Alice"; // line 21
    SALARIES[1 - 1] = 75000.0; // line 22
    IDS[2 - 1] = 2; // line 23
    NAMES[2 - 1] = "Bob"; // line 24
    SALARIES[2 - 1] = 65000.0; // line 25
    IDS[3 - 1] = 3; // line 26
    NAMES[3 - 1] = "Charlie"; // line 27
    SALARIES[3 - 1] = 90000.0; // line 28
    NROWS = 3; // line 31
    // EXEC SQL INSERT INTO mrtest (id, name, salary)   VALUES(:ids, :names, :salaries)   FOR :nRows ROWS
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        SQLPrepare(__hstmt, (SQLCHAR*)"INSERT INTO mrtest (id, name, salary)   VALUES(?, ?, ?)", SQL_NTS);
        for (int __ri = 0; __ri < NROWS; __ri++) {
            __sql_env.clearParamBufs();
            __sql_env.bindParam(__hstmt, 1, IDS[__ri]);
            __sql_env.bindParam(__hstmt, 2, NAMES[__ri]);
            __sql_env.bindParam(__hstmt, 3, SALARIES[__ri]);
            SQLRETURN __erc = SQLExecute(__hstmt);
            __sql_env.updateStmtDiag(__hstmt, __erc);
            if (__erc != SQL_SUCCESS && __erc != SQL_SUCCESS_WITH_INFO) break;
        }
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    // EXEC SQL DECLARE mrCur CURSOR FOR   SELECT id, name, salary FROM mrtest ORDER BY id
    __sql_env.declareCursor("MRCUR", "SELECT id, name, salary FROM mrtest ORDER BY id");
    // EXEC SQL OPEN mrCur
    __sql_env.openCursor("MRCUR");
    NROWS = 10; // line 43
    // EXEC SQL FETCH mrCur FOR :nRows ROWS   INTO :ids, :names, :salaries
    {
        SQLHSTMT __cstmt = __sql_env.getCursorStmt("MRCUR");
        for (int __ri = 0; __ri < NROWS; __ri++) {
            char __sql_strbuf_1[4096] = {};
            char __sql_strbuf_2[4096] = {};
            char __sql_strbuf_3[4096] = {};
            SQLLEN __sql_ind_1 = 0;
            __sql_env.bindCol(__cstmt, 1, IDS[__ri], __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
            SQLLEN __sql_ind_2 = 0;
            __sql_env.bindCol(__cstmt, 2, NAMES[__ri], __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
            SQLLEN __sql_ind_3 = 0;
            __sql_env.bindCol(__cstmt, 3, SALARIES[__ri], __sql_strbuf_3, sizeof(__sql_strbuf_3), __sql_ind_3);
            SQLRETURN __frc = SQLFetch(__cstmt);
            __sql_env.updateStmtDiag(__cstmt, __frc);
            if (__frc != SQL_SUCCESS && __frc != SQL_SUCCESS_WITH_INFO) break;
            RpgSqlEnv::copyStrBuf(IDS[__ri], __sql_strbuf_1, __frc);
            RpgSqlEnv::copyStrBuf(NAMES[__ri], __sql_strbuf_2, __frc);
            RpgSqlEnv::copyStrBuf(SALARIES[__ri], __sql_strbuf_3, __frc);
        }
    }
    // EXEC SQL CLOSE mrCur
    __sql_env.closeCursor("MRCUR");
    for (I = 1; I <= 3; I += 1) {
        std::cout << rpg_to_char(IDS[I - 1]) << std::endl;
        std::cout << NAMES[I - 1] << std::endl;
        std::cout << rpg_to_char(SALARIES[I - 1]) << std::endl;
    }
    // EXEC SQL DROP TABLE mrtest
    __sql_env.execDirect("DROP TABLE mrtest");
    return 0;
    return 0;
}
