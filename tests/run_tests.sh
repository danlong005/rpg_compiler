#!/bin/bash
# RPG Compiler Test Runner
# Validates runtime output against expected output

set -e

UPDATE_MODE=false
if [ "$1" = "--update" ]; then
    UPDATE_MODE=true
fi

RPGC="./rpgc"
CXX="clang++"
CXXFLAGS="-std=c++17 -Iruntime"
CXXFLAGS_SQL="-std=c++17 -Iruntime -I/opt/homebrew/include -L/opt/homebrew/lib -lodbc"
TESTDIR="tests"
EXPECTED_OUT="$TESTDIR/expected_output"
TMPDIR="/tmp/rpgc_test"

PASS=0
FAIL=0
FAILURES=""

mkdir -p "$TMPDIR"

# Colors (if terminal supports it)
if [ -t 1 ]; then
    GREEN='\033[0;32m'
    RED='\033[0;31m'
    YELLOW='\033[0;33m'
    NC='\033[0m'
else
    GREEN=''
    RED=''
    YELLOW=''
    NC=''
fi

run_test() {
    local testnum="$1"
    local label="$2"
    local src="$3"
    local mode="$4"  # "run", "compile-only", "parse-only", "error"
    local extra="$5" # extra compile args (e.g., /tmp/rpgc_test/test48.o)

    printf "Test %s: %-35s " "$testnum" "$label"

    case "$mode" in
        error)
            if $RPGC "$src" -o /dev/null 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (should have failed)"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi
            echo -e "${GREEN}PASS${NC}"
            PASS=$((PASS + 1))
            ;;
        parse-only)
            if ! $RPGC -S "$src" -o "$TMPDIR/test${testnum}.cpp" 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (transpile failed)"
                cat "$TMPDIR/test${testnum}_err.txt"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi
            echo -e "${GREEN}PASS${NC}"
            PASS=$((PASS + 1))
            ;;
        compile-only)
            if ! $RPGC -S "$src" -o "$TMPDIR/test${testnum}.cpp" 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (transpile failed)"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi
            if ! $CXX $CXXFLAGS -c -o "$TMPDIR/test${testnum}.o" "$TMPDIR/test${testnum}.cpp" 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (compile failed)"
                cat "$TMPDIR/test${testnum}_err.txt"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi
            echo -e "${GREEN}PASS${NC}"
            PASS=$((PASS + 1))
            ;;
        run)
            # Transpile
            if ! $RPGC -S "$src" -o "$TMPDIR/test${testnum}.cpp" 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (transpile failed)"
                cat "$TMPDIR/test${testnum}_err.txt"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi

            # Compile
            if ! $CXX $CXXFLAGS -o "$TMPDIR/test${testnum}" "$TMPDIR/test${testnum}.cpp" $extra 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (compile failed)"
                cat "$TMPDIR/test${testnum}_err.txt"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi

            # Run and check output
            local actual="$TMPDIR/test${testnum}.actual"
            "$TMPDIR/test${testnum}" > "$actual" 2>&1 || true

            local expected="$EXPECTED_OUT/test${testnum}.out"
            if $UPDATE_MODE; then
                cp "$actual" "$expected"
                echo -e "${YELLOW}UPDATED${NC}"
                PASS=$((PASS + 1))
            elif [ -f "$expected" ]; then
                if diff -q "$actual" "$expected" > /dev/null 2>&1; then
                    echo -e "${GREEN}PASS${NC}"
                    PASS=$((PASS + 1))
                else
                    echo -e "${RED}FAIL${NC} (output mismatch)"
                    diff --unified=3 "$expected" "$actual" | head -20
                    FAIL=$((FAIL + 1))
                    FAILURES="$FAILURES\n  Test $testnum ($label)"
                fi
            else
                # No expected output file — just verify it ran
                echo -e "${GREEN}PASS${NC} (no output check)"
                PASS=$((PASS + 1))
            fi
            ;;
        run-sql)
            # Clean up any previous test database
            rm -f "/tmp/rpgc_test${testnum}.sqlite"

            # Transpile
            if ! $RPGC -S "$src" -o "$TMPDIR/test${testnum}.cpp" 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (transpile failed)"
                cat "$TMPDIR/test${testnum}_err.txt"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi

            # Compile with ODBC flags
            if ! $CXX $CXXFLAGS_SQL -o "$TMPDIR/test${testnum}" "$TMPDIR/test${testnum}.cpp" $extra 2>"$TMPDIR/test${testnum}_err.txt"; then
                echo -e "${RED}FAIL${NC} (compile failed)"
                cat "$TMPDIR/test${testnum}_err.txt"
                FAIL=$((FAIL + 1))
                FAILURES="$FAILURES\n  Test $testnum ($label)"
                return
            fi

            # Run and check output
            local actual="$TMPDIR/test${testnum}.actual"
            "$TMPDIR/test${testnum}" > "$actual" 2>&1 || true

            # Clean up temp database
            rm -f "/tmp/rpgc_test${testnum}.sqlite"

            local expected="$EXPECTED_OUT/test${testnum}.out"
            if $UPDATE_MODE; then
                cp "$actual" "$expected"
                echo -e "${YELLOW}UPDATED${NC}"
                PASS=$((PASS + 1))
            elif [ -f "$expected" ]; then
                if diff -q "$actual" "$expected" > /dev/null 2>&1; then
                    echo -e "${GREEN}PASS${NC}"
                    PASS=$((PASS + 1))
                else
                    echo -e "${RED}FAIL${NC} (output mismatch)"
                    diff --unified=3 "$expected" "$actual" | head -20
                    FAIL=$((FAIL + 1))
                    FAILURES="$FAILURES\n  Test $testnum ($label)"
                fi
            else
                # No expected output file — just verify it ran
                echo -e "${GREEN}PASS${NC} (no output check)"
                PASS=$((PASS + 1))
            fi
            ;;
    esac
}

echo "========================================"
echo "  RPG Compiler Test Suite"
echo "========================================"
echo ""

# Tests 01-10: Core language
run_test "01" "Hello World" "$TESTDIR/test01_hello.rpgle" "run"
run_test "02" "Arithmetic" "$TESTDIR/test02_arithmetic.rpgle" "run"
run_test "03" "Types" "$TESTDIR/test03_types.rpgle" "run"
run_test "04" "BIFs" "$TESTDIR/test04_bifs.rpgle" "run"
run_test "05" "IF" "$TESTDIR/test05_if.rpgle" "run"
run_test "06" "Loops" "$TESTDIR/test06_loops.rpgle" "run"
run_test "07" "Select" "$TESTDIR/test07_select.rpgle" "run"
run_test "08" "Procedures" "$TESTDIR/test08_procedures.rpgle" "run"
run_test "09" "Data Structures" "$TESTDIR/test09_datastructs.rpgle" "run"
run_test "10" "Expanded BIFs" "$TESTDIR/test10_bifs_expanded.rpgle" "run"

# Test 11: Error reporting (multiple sub-tests)
for errfile in $TESTDIR/test11*.rpgle; do
    name=$(basename "$errfile" .rpgle)
    run_test "${name#test}" "$name" "$errfile" "error"
done

# Tests 12-76: Language features
run_test "12" "Monitor" "$TESTDIR/test12_monitor.rpgle" "run"
run_test "13" "Subroutines" "$TESTDIR/test13_subroutines.rpgle" "run"
run_test "14" "Indicators" "$TESTDIR/test14_indicators.rpgle" "run"
run_test "15" "DOU Loop" "$TESTDIR/test15_dou.rpgle" "run"
run_test "16" "/COPY Include" "$TESTDIR/test16_copy.rpgle" "run"
run_test "17" "Named Constants" "$TESTDIR/test17_constants.rpgle" "run"
run_test "18" "Date/Time" "$TESTDIR/test18_datetime.rpgle" "run"
run_test "19" "Math BIFs" "$TESTDIR/test19_math_bifs.rpgle" "run"
run_test "20" "Memory BIFs" "$TESTDIR/test20_memory_bifs.rpgle" "run"
run_test "21" "%PARMS" "$TESTDIR/test21_parms.rpgle" "run"
run_test "22" "%STATUS/%ERROR" "$TESTDIR/test22_status_error.rpgle" "run"
run_test "23" "RESET/CLEAR" "$TESTDIR/test23_reset_clear.rpgle" "run"
run_test "24" "%MAX/%MIN" "$TESTDIR/test24_max_min.rpgle" "run"
run_test "25" "DCL-F" "$TESTDIR/test25_dclf.rpgle" "run"
run_test "26" "Pointers" "$TESTDIR/test26_pointers.rpgle" "run"
run_test "27" "Arrays" "$TESTDIR/test27_arrays.rpgle" "run"
run_test "28" "Conditional Compilation" "$TESTDIR/test28_conditional.rpgle" "run"
run_test "29" "DCL-SUBF/DCL-PARM" "$TESTDIR/test29_dclsubf_parm.rpgle" "run"
run_test "30" "LIKE" "$TESTDIR/test30_like.rpgle" "run"
run_test "31" "LOOKUP and SORTA" "$TESTDIR/test31_lookup_sorta.rpgle" "run"
run_test "32" "EDITC/EDITW" "$TESTDIR/test32_editc_editw.rpgle" "run"
run_test "33" "REPLACE" "$TESTDIR/test33_replace.rpgle" "run"
run_test "34" "CHECK/CHECKR" "$TESTDIR/test34_check.rpgle" "run"
run_test "35" "EVAL-CORR" "$TESTDIR/test35_evalcorr.rpgle" "run"
run_test "36" "DS Params" "$TESTDIR/test36_ds_params.rpgle" "run"
run_test "37" "*INZSR" "$TESTDIR/test37_inzsr.rpgle" "run"
run_test "38" "CTL-OPT" "$TESTDIR/test38_ctlopt.rpgle" "run"
run_test "39" "Figurative Constants" "$TESTDIR/test39_figconst.rpgle" "run"
run_test "40" "EVALR/LEAVESR" "$TESTDIR/test40_evalr_leavesr.rpgle" "run"
run_test "41" "String/Math BIFs" "$TESTDIR/test41_string_bifs.rpgle" "run"
run_test "42" "ON-EXIT" "$TESTDIR/test42_onexit.rpgle" "run"
run_test "43" "STATIC" "$TESTDIR/test43_static.rpgle" "run"
run_test "44" "ALLOC/DEALLOC" "$TESTDIR/test44_alloc.rpgle" "run"
run_test "45" "Array BIFs" "$TESTDIR/test45_array_bifs.rpgle" "run"
run_test "46" "OPTIONS(*NOPASS)" "$TESTDIR/test46_options.rpgle" "run"
run_test "47" "TEST Opcode" "$TESTDIR/test47_test.rpgle" "run"
run_test "48" "NOMAIN Module" "$TESTDIR/test48_nomain.rpgle" "compile-only"
run_test "49" "EXTPROC/IMPORT" "$TESTDIR/test49_extproc.rpgle" "run" "$TMPDIR/test48.o"
run_test "50" "Numeric BIFs" "$TESTDIR/test50_numeric_bifs.rpgle" "run"
run_test "51" "String BIFs" "$TESTDIR/test51_string_bifs.rpgle" "run"
run_test "52" "Array BIFs" "$TESTDIR/test52_array_bifs.rpgle" "run"
run_test "53" "Date/Time BIFs" "$TESTDIR/test53_datetime_bifs.rpgle" "run"
run_test "54" "Memory/Pointer BIFs" "$TESTDIR/test54_memory_bifs.rpgle" "run"
run_test "55" "Figurative Constants" "$TESTDIR/test55_figconst.rpgle" "run"
run_test "56" "MAIN(procname)" "$TESTDIR/test56_ctlopt_main.rpgle" "run"
run_test "57" "DATFMT/TIMFMT" "$TESTDIR/test57_datfmt.rpgle" "run"
run_test "58" "FOR-EACH and IN" "$TESTDIR/test58_foreach_in.rpgle" "run"
run_test "59" "%PASSED/%OMITTED" "$TESTDIR/test59_passed_omitted.rpgle" "run"
run_test "60" "Data Types" "$TESTDIR/test60_datatypes.rpgle" "run"
run_test "61" "No **FREE" "$TESTDIR/test61_no_free.rpgle" "run"
run_test "62" "OVERLAY/POS" "$TESTDIR/test62_overlay_pos.rpgle" "run"
run_test "63" "PREFIX" "$TESTDIR/test63_prefix.rpgle" "run"
run_test "64" "OPTIONS(*OMIT)" "$TESTDIR/test64_omit.rpgle" "run"
run_test "65" "DFTACTGRP/ACTGRP" "$TESTDIR/test65_actgrp.rpgle" "run"
run_test "66" "*PSSR" "$TESTDIR/test66_pssr.rpgle" "run"
run_test "67" "*PSSR Error" "$TESTDIR/test67_pssr_error.rpgle" "run"
run_test "68" "Bitwise & Power" "$TESTDIR/test68_bitwise_power.rpgle" "run"
run_test "69" "%SCANR" "$TESTDIR/test69_scanr.rpgle" "run"
run_test "70" "%EDITFLT & %UNSH" "$TESTDIR/test70_editflt_unsh.rpgle" "run"
run_test "71" "Enum & Boolean" "$TESTDIR/test71_enum_boolean.rpgle" "run"
run_test "72" "DIM(*VAR)" "$TESTDIR/test72_dim_var.rpgle" "run"
run_test "73" "Date Formats" "$TESTDIR/test73_date_formats.rpgle" "run"
run_test "74" "%CONCAT" "$TESTDIR/test74_concat.rpgle" "run"
run_test "75" "%TLOOKUP & %ELEM" "$TESTDIR/test75_tlookup_elem.rpgle" "run"
run_test "76" "DS DIM(*VAR)" "$TESTDIR/test76_ds_dim_var.rpgle" "run"

# SQL tests (compile + run with SQLite)
run_test "77" "Embedded SQL" "$TESTDIR/test77_exec_sql.sqlrpgle" "run-sql"
run_test "78" "SQL in Procedures" "$TESTDIR/test78_exec_sql_proc.sqlrpgle" "run-sql"
run_test "79" "SQL Core Statements" "$TESTDIR/test79_sql_core.sqlrpgle" "run-sql"
run_test "80" "SQL Cursors" "$TESTDIR/test80_sql_cursors.sqlrpgle" "run-sql"
run_test "81" "Dynamic SQL" "$TESTDIR/test81_sql_dynamic.sqlrpgle" "run-sql"
run_test "82" "SQL Advanced" "$TESTDIR/test82_sql_advanced.sqlrpgle" "run-sql"
run_test "83" "SQL Multi-row" "$TESTDIR/test83_sql_multirow.sqlrpgle" "run-sql"
run_test "84" "SQL Connect" "$TESTDIR/test84_sql_connect.sqlrpgle" "run-sql"

# Test 85: %GETENV (run but no output check — env-dependent)
run_test "85" "%%GETENV" "$TESTDIR/test85_getenv.rpgle" "run"

# Test 86: SQL end-to-end
run_test "86" "SQL End-to-End" "$TESTDIR/test86.sqlrpgle" "run-sql"

echo ""
echo "========================================"
echo -e "  Results: ${GREEN}${PASS} passed${NC}, ${RED}${FAIL} failed${NC}"
echo "========================================"

if [ $FAIL -gt 0 ]; then
    echo -e "\nFailed tests:${FAILURES}"
    exit 1
fi
