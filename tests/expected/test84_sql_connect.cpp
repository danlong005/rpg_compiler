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
    std::string DSN;
    std::string DBUSER;
    std::string DBPASS;
    std::string CONNSTR;
    std::string EMPNAME;
    int EMPID = 0;
    DSN = "MYDB"; // line 14
    DBUSER = "admin"; // line 15
    DBPASS = "secret"; // line 16
    // EXEC SQL CONNECT TO :dsn USER :dbUser USING :dbPass
    __sql_env.connect(DSN, DBUSER, DBPASS);
    EMPID = 1; // line 20
    // EXEC SQL SELECT name INTO :empName   FROM employees WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"SELECT name    FROM employees WHERE id = ?", SQL_NTS);
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
    std::cout << EMPNAME << std::endl;
    // EXEC SQL DISCONNECT
    __sql_env.disconnect();
    DSN = "TESTDB"; // line 30
    // EXEC SQL CONNECT TO :dsn
    __sql_env.connect(DSN);
    // EXEC SQL CREATE TABLE temp_test (id INTEGER)
    __sql_env.execDirect("CREATE TABLE temp_test (id INTEGER)");
    // EXEC SQL DROP TABLE temp_test
    __sql_env.execDirect("DROP TABLE temp_test");
    // EXEC SQL DISCONNECT
    __sql_env.disconnect();
    CONNSTR = "Driver={SQLite3};Database=test.db"; // line 39
    // EXEC SQL CONNECT USING :connStr
    __sql_env.connectStr(CONNSTR);
    // EXEC SQL CREATE TABLE temp_test2 (id INTEGER)
    __sql_env.execDirect("CREATE TABLE temp_test2 (id INTEGER)");
    // EXEC SQL DROP TABLE temp_test2
    __sql_env.execDirect("DROP TABLE temp_test2");
    // EXEC SQL CONNECT RESET
    __sql_env.disconnect();
    return 0;
    return 0;
}
