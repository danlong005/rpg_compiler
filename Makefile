CXX      := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wno-deprecated-register -Wno-unused-function
FLEX     := /opt/homebrew/opt/flex/bin/flex
BISON    := /opt/homebrew/opt/bison/bin/bison

SRCDIR   := src
BUILDDIR := build
TARGET   := rpgc

SRCS := $(BUILDDIR)/lexer.cpp \
        $(BUILDDIR)/parser.cpp \
        $(SRCDIR)/ast.cpp \
        $(SRCDIR)/codegen.cpp \
        $(SRCDIR)/main.cpp

OBJS := $(BUILDDIR)/lexer.o \
        $(BUILDDIR)/parser.o \
        $(BUILDDIR)/ast.o \
        $(BUILDDIR)/codegen.o \
        $(BUILDDIR)/main.o

all: $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/parser.cpp $(BUILDDIR)/parser.h: $(SRCDIR)/parser.y | $(BUILDDIR)
	$(BISON) --defines=$(BUILDDIR)/parser.h -o $(BUILDDIR)/parser.cpp $<

$(BUILDDIR)/lexer.cpp: $(SRCDIR)/lexer.l $(BUILDDIR)/parser.h | $(BUILDDIR)
	$(FLEX) -o $@ $<

$(BUILDDIR)/lexer.o: $(BUILDDIR)/lexer.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -I$(BUILDDIR) -c -o $@ $<

$(BUILDDIR)/parser.o: $(BUILDDIR)/parser.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -I$(BUILDDIR) -c -o $@ $<

$(BUILDDIR)/ast.o: $(SRCDIR)/ast.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -I$(BUILDDIR) -c -o $@ $<

$(BUILDDIR)/codegen.o: $(SRCDIR)/codegen.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -I$(BUILDDIR) -c -o $@ $<

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -I$(BUILDDIR) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(BUILDDIR) $(TARGET)

test: $(TARGET)
	@echo "=== Test 01: Hello World ==="
	./$(TARGET) tests/test01_hello.rpgle -o /tmp/test01.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test01 /tmp/test01.cpp
	/tmp/test01
	@echo ""
	@echo "=== Test 02: Arithmetic ==="
	./$(TARGET) tests/test02_arithmetic.rpgle -o /tmp/test02.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test02 /tmp/test02.cpp
	/tmp/test02
	@echo ""
	@echo "=== Test 03: Types ==="
	./$(TARGET) tests/test03_types.rpgle -o /tmp/test03.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test03 /tmp/test03.cpp
	/tmp/test03
	@echo ""
	@echo "=== Test 04: BIFs ==="
	./$(TARGET) tests/test04_bifs.rpgle -o /tmp/test04.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test04 /tmp/test04.cpp
	/tmp/test04
	@echo ""
	@echo "=== Test 05: IF ==="
	./$(TARGET) tests/test05_if.rpgle -o /tmp/test05.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test05 /tmp/test05.cpp
	/tmp/test05
	@echo ""
	@echo "=== Test 06: Loops ==="
	./$(TARGET) tests/test06_loops.rpgle -o /tmp/test06.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test06 /tmp/test06.cpp
	/tmp/test06
	@echo ""
	@echo "=== Test 07: Select ==="
	./$(TARGET) tests/test07_select.rpgle -o /tmp/test07.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test07 /tmp/test07.cpp
	/tmp/test07
	@echo ""
	@echo "=== Test 08: Procedures ==="
	./$(TARGET) tests/test08_procedures.rpgle -o /tmp/test08.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test08 /tmp/test08.cpp
	/tmp/test08
	@echo ""
	@echo "=== Test 09: Data Structures ==="
	./$(TARGET) tests/test09_datastructs.rpgle -o /tmp/test09.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test09 /tmp/test09.cpp
	/tmp/test09
	@echo ""
	@echo "=== Test 10: Expanded BIFs ==="
	./$(TARGET) tests/test10_bifs_expanded.rpgle -o /tmp/test10.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test10 /tmp/test10.cpp
	/tmp/test10
	@echo ""
	@echo "=== Test 11: Error Recovery ==="
	./$(TARGET) tests/test11_errors.rpgle -o /tmp/test11.cpp 2>/dev/null; \
	$(CXX) -std=c++17 -Iruntime -o /tmp/test11 /tmp/test11.cpp && /tmp/test11
	@echo ""
	@echo "=== Test 12: Monitor ==="
	./$(TARGET) tests/test12_monitor.rpgle -o /tmp/test12.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test12 /tmp/test12.cpp
	/tmp/test12
	@echo ""
	@echo "=== Test 13: Subroutines ==="
	./$(TARGET) tests/test13_subroutines.rpgle -o /tmp/test13.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test13 /tmp/test13.cpp
	/tmp/test13
	@echo ""
	@echo "=== Test 14: Indicators ==="
	./$(TARGET) tests/test14_indicators.rpgle -o /tmp/test14.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test14 /tmp/test14.cpp
	/tmp/test14
	@echo ""
	@echo "=== Test 15: DOU Loop ==="
	./$(TARGET) tests/test15_dou.rpgle -o /tmp/test15.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test15 /tmp/test15.cpp
	/tmp/test15
	@echo ""
	@echo "=== Test 16: /COPY Include ==="
	./$(TARGET) tests/test16_copy.rpgle -o /tmp/test16.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test16 /tmp/test16.cpp
	/tmp/test16
	@echo ""
	@echo "=== Test 17: Named Constants ==="
	./$(TARGET) tests/test17_constants.rpgle -o /tmp/test17.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test17 /tmp/test17.cpp
	/tmp/test17
	@echo ""
	@echo "=== Test 18: Date/Time ==="
	./$(TARGET) tests/test18_datetime.rpgle -o /tmp/test18.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test18 /tmp/test18.cpp
	/tmp/test18
	@echo ""
	@echo "=== Test 19: Math BIFs ==="
	./$(TARGET) tests/test19_math_bifs.rpgle -o /tmp/test19.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test19 /tmp/test19.cpp
	/tmp/test19
	@echo ""
	@echo "=== Test 20: Memory BIFs ==="
	./$(TARGET) tests/test20_memory_bifs.rpgle -o /tmp/test20.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test20 /tmp/test20.cpp
	/tmp/test20
	@echo ""
	@echo "=== Test 21: %PARMS ==="
	./$(TARGET) tests/test21_parms.rpgle -o /tmp/test21.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test21 /tmp/test21.cpp
	/tmp/test21
	@echo ""
	@echo "=== Test 22: %STATUS/%ERROR ==="
	./$(TARGET) tests/test22_status_error.rpgle -o /tmp/test22.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test22 /tmp/test22.cpp
	/tmp/test22
	@echo ""
	@echo "=== Test 23: RESET/CLEAR ==="
	./$(TARGET) tests/test23_reset_clear.rpgle -o /tmp/test23.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test23 /tmp/test23.cpp
	/tmp/test23
	@echo ""
	@echo "=== Test 24: %MAX/%MIN ==="
	./$(TARGET) tests/test24_max_min.rpgle -o /tmp/test24.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test24 /tmp/test24.cpp
	/tmp/test24
	@echo ""
	@echo "=== Test 25: DCL-F ==="
	./$(TARGET) tests/test25_dclf.rpgle -o /tmp/test25.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test25 /tmp/test25.cpp
	/tmp/test25
	@echo ""
	@echo "=== Test 26: Pointers ==="
	./$(TARGET) tests/test26_pointers.rpgle -o /tmp/test26.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test26 /tmp/test26.cpp
	/tmp/test26
	@echo ""
	@echo "=== Test 27: Arrays ==="
	./$(TARGET) tests/test27_arrays.rpgle -o /tmp/test27.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test27 /tmp/test27.cpp
	/tmp/test27
	@echo ""
	@echo "=== Test 28: Conditional Compilation ==="
	./$(TARGET) tests/test28_conditional.rpgle -o /tmp/test28.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test28 /tmp/test28.cpp
	/tmp/test28
	@echo ""
	@echo "=== Test 29: DCL-SUBF/DCL-PARM ==="
	./$(TARGET) tests/test29_dclsubf_parm.rpgle -o /tmp/test29.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test29 /tmp/test29.cpp
	/tmp/test29
	@echo ""
	@echo "=== Test 30: LIKE ==="
	./$(TARGET) tests/test30_like.rpgle -o /tmp/test30.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test30 /tmp/test30.cpp
	/tmp/test30
	@echo ""
	@echo "=== Test 31: LOOKUP and SORTA ==="
	./$(TARGET) tests/test31_lookup_sorta.rpgle -o /tmp/test31.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test31 /tmp/test31.cpp
	/tmp/test31
	@echo ""
	@echo "=== Test 32: EDITC/EDITW ==="
	./$(TARGET) tests/test32_editc_editw.rpgle -o /tmp/test32.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test32 /tmp/test32.cpp
	/tmp/test32
	@echo ""
	@echo "=== Test 33: REPLACE ==="
	./$(TARGET) tests/test33_replace.rpgle -o /tmp/test33.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test33 /tmp/test33.cpp
	/tmp/test33
	@echo ""
	@echo "=== Test 34: CHECK/CHECKR ==="
	./$(TARGET) tests/test34_check.rpgle -o /tmp/test34.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test34 /tmp/test34.cpp
	/tmp/test34
	@echo ""
	@echo "=== Test 35: EVAL-CORR ==="
	./$(TARGET) tests/test35_evalcorr.rpgle -o /tmp/test35.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test35 /tmp/test35.cpp
	/tmp/test35
	@echo ""
	@echo "=== Test 36: DS Params ==="
	./$(TARGET) tests/test36_ds_params.rpgle -o /tmp/test36.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test36 /tmp/test36.cpp
	/tmp/test36
	@echo ""
	@echo "=== Test 37: *INZSR ==="
	./$(TARGET) tests/test37_inzsr.rpgle -o /tmp/test37.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test37 /tmp/test37.cpp
	/tmp/test37
	@echo ""
	@echo "=== Test 38: CTL-OPT ==="
	./$(TARGET) tests/test38_ctlopt.rpgle -o /tmp/test38.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test38 /tmp/test38.cpp
	/tmp/test38
	@echo ""
	@echo "=== Test 39: Figurative Constants ==="
	./$(TARGET) tests/test39_figconst.rpgle -o /tmp/test39.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test39 /tmp/test39.cpp
	/tmp/test39
	@echo ""
	@echo "=== Test 40: EVALR/LEAVESR ==="
	./$(TARGET) tests/test40_evalr_leavesr.rpgle -o /tmp/test40.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test40 /tmp/test40.cpp
	/tmp/test40
	@echo ""
	@echo "=== Test 41: String/Math BIFs ==="
	./$(TARGET) tests/test41_string_bifs.rpgle -o /tmp/test41.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test41 /tmp/test41.cpp
	/tmp/test41
	@echo ""
	@echo "=== Test 42: ON-EXIT ==="
	./$(TARGET) tests/test42_onexit.rpgle -o /tmp/test42.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test42 /tmp/test42.cpp
	/tmp/test42
	@echo ""
	@echo "=== Test 43: STATIC ==="
	./$(TARGET) tests/test43_static.rpgle -o /tmp/test43.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test43 /tmp/test43.cpp
	/tmp/test43
	@echo ""
	@echo "=== Test 44: ALLOC/DEALLOC ==="
	./$(TARGET) tests/test44_alloc.rpgle -o /tmp/test44.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test44 /tmp/test44.cpp
	/tmp/test44
	@echo ""
	@echo "=== Test 45: Array BIFs ==="
	./$(TARGET) tests/test45_array_bifs.rpgle -o /tmp/test45.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test45 /tmp/test45.cpp
	/tmp/test45
	@echo ""
	@echo "=== Test 46: OPTIONS(*NOPASS) ==="
	./$(TARGET) tests/test46_options.rpgle -o /tmp/test46.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test46 /tmp/test46.cpp
	/tmp/test46
	@echo ""
	@echo "=== Test 47: TEST Opcode ==="
	./$(TARGET) tests/test47_test.rpgle -o /tmp/test47.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test47 /tmp/test47.cpp
	/tmp/test47
	@echo ""
	@echo "=== Test 48: NOMAIN Module ==="
	./$(TARGET) tests/test48_nomain.rpgle -o /tmp/test48.cpp
	$(CXX) -std=c++17 -Iruntime -c -o /tmp/test48.o /tmp/test48.cpp
	@echo "Compiled to .o (no main)"
	@echo ""
	@echo "=== Test 49: EXTPROC/IMPORT ==="
	./$(TARGET) tests/test49_extproc.rpgle -o /tmp/test49.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test49 /tmp/test49.cpp /tmp/test48.o
	/tmp/test49
	@echo ""
	@echo "=== Test 50: Numeric BIFs ==="
	./$(TARGET) tests/test50_numeric_bifs.rpgle -o /tmp/test50.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test50 /tmp/test50.cpp
	/tmp/test50
	@echo ""
	@echo "=== Test 51: String BIFs ==="
	./$(TARGET) tests/test51_string_bifs.rpgle -o /tmp/test51.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test51 /tmp/test51.cpp
	/tmp/test51
	@echo ""
	@echo "=== Test 52: Array BIFs ==="
	./$(TARGET) tests/test52_array_bifs.rpgle -o /tmp/test52.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test52 /tmp/test52.cpp
	/tmp/test52
	@echo ""
	@echo "=== Test 53: Date/Time BIFs ==="
	./$(TARGET) tests/test53_datetime_bifs.rpgle -o /tmp/test53.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test53 /tmp/test53.cpp
	/tmp/test53
	@echo ""
	@echo "=== Test 54: Memory/Pointer BIFs ==="
	./$(TARGET) tests/test54_memory_bifs.rpgle -o /tmp/test54.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test54 /tmp/test54.cpp
	/tmp/test54
	@echo ""
	@echo "=== Test 55: Figurative Constants ==="
	./$(TARGET) tests/test55_figconst.rpgle -o /tmp/test55.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test55 /tmp/test55.cpp
	/tmp/test55
	@echo ""
	@echo "=== Test 56: MAIN(procname) ==="
	./$(TARGET) tests/test56_ctlopt_main.rpgle -o /tmp/test56.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test56 /tmp/test56.cpp
	/tmp/test56
	@echo ""
	@echo "=== Test 57: DATFMT/TIMFMT ==="
	./$(TARGET) tests/test57_datfmt.rpgle -o /tmp/test57.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test57 /tmp/test57.cpp
	/tmp/test57
	@echo ""
	@echo "=== Test 58: FOR-EACH and IN ==="
	./$(TARGET) tests/test58_foreach_in.rpgle -o /tmp/test58.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test58 /tmp/test58.cpp
	/tmp/test58
	@echo ""
	@echo "=== Test 59: %PASSED/%OMITTED ==="
	./$(TARGET) tests/test59_passed_omitted.rpgle -o /tmp/test59.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test59 /tmp/test59.cpp
	/tmp/test59
	@echo ""
	@echo "=== Test 60: Data Types ==="
	./$(TARGET) tests/test60_datatypes.rpgle -o /tmp/test60.cpp
	$(CXX) -std=c++17 -Iruntime -o /tmp/test60 /tmp/test60.cpp
	/tmp/test60
	@echo ""
	@echo "All tests passed."

.PHONY: all clean test
