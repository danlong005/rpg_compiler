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
    std::string SQLSTR;
    int EMPID = 0;
    std::string EMPNAME;
    double EMPSAL = 0.0;
    SQLSTR = "CREATE TABLE dyntest (id INTEGER, name VARCHAR(50), salary DECIMAL(9,2))"; // line 12
    // EXEC SQL EXECUTE IMMEDIATE :sqlStr
    __sql_env.execDirect(SQLSTR);
    SQLSTR = "INSERT INTO dyntest (id, name, salary) VALUES(?, ?, ?)"; // line 16
    // EXEC SQL PREPARE INS1 FROM :sqlStr
    __sql_env.prepareStmt("INS1", SQLSTR);
    EMPID = 1; // line 20
    EMPNAME = "Alice"; // line 21
    EMPSAL = 75000.0; // line 22
    // EXEC SQL EXECUTE INS1 USING :empId, :empName, :empSal
    {
        SQLHSTMT __pstmt = __sql_env.getPreparedStmt("INS1");
        __sql_env.clearParamBufs();
        __sql_env.bindParam(__pstmt, 1, EMPID);
        __sql_env.bindParam(__pstmt, 2, EMPNAME);
        __sql_env.bindParam(__pstmt, 3, EMPSAL);
    }
    __sql_env.executeStmt("INS1");
    EMPID = 2; // line 25
    EMPNAME = "Bob"; // line 26
    EMPSAL = 65000.0; // line 27
    // EXEC SQL EXECUTE INS1 USING :empId, :empName, :empSal
    {
        SQLHSTMT __pstmt = __sql_env.getPreparedStmt("INS1");
        __sql_env.clearParamBufs();
        __sql_env.bindParam(__pstmt, 1, EMPID);
        __sql_env.bindParam(__pstmt, 2, EMPNAME);
        __sql_env.bindParam(__pstmt, 3, EMPSAL);
    }
    __sql_env.executeStmt("INS1");
    SQLSTR = "SELECT name, salary FROM dyntest WHERE id = ?"; // line 31
    // EXEC SQL PREPARE SEL1 FROM :sqlStr
    __sql_env.prepareStmt("SEL1", SQLSTR);
    EMPID = 1; // line 35
    // EXEC SQL SELECT name, salary   INTO :empName, :empSal   FROM dyntest WHERE id = :empId
    {
        SQLHSTMT __hstmt = __sql_env.allocStmt();
        __sql_env.clearParamBufs();
        SQLPrepare(__hstmt, (SQLCHAR*)"SELECT name, salary    FROM dyntest WHERE id = ?", SQL_NTS);
        __sql_env.bindParam(__hstmt, 1, EMPID);
        char __sql_strbuf_1[4096] = {};
        char __sql_strbuf_2[4096] = {};
        SQLLEN __sql_ind_1 = 0;
        __sql_env.bindCol(__hstmt, 1, EMPNAME, __sql_strbuf_1, sizeof(__sql_strbuf_1), __sql_ind_1);
        SQLLEN __sql_ind_2 = 0;
        __sql_env.bindCol(__hstmt, 2, EMPSAL, __sql_strbuf_2, sizeof(__sql_strbuf_2), __sql_ind_2);
        SQLExecute(__hstmt);
        SQLRETURN __frc = SQLFetch(__hstmt);
        __sql_env.updateStmtDiag(__hstmt, __frc);
        RpgSqlEnv::copyStrBuf(EMPNAME, __sql_strbuf_1, __frc);
        RpgSqlEnv::copyStrBuf(EMPSAL, __sql_strbuf_2, __frc);
        SQLFreeHandle(SQL_HANDLE_STMT, __hstmt);
    }
    std::cout << EMPNAME << std::endl;
    std::cout << rpg_to_char(EMPSAL) << std::endl;
    SQLSTR = "DROP TABLE dyntest"; // line 44
    // EXEC SQL EXECUTE IMMEDIATE :sqlStr
    __sql_env.execDirect(SQLSTR);
    return 0;
    return 0;
}
