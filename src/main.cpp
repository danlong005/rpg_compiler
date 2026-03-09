#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "ast.h"
#include "codegen.h"

extern FILE* yyin;
extern rpg::Program* get_parsed_program();
extern int get_parse_error_count();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: rpgc <input.rpgle> [-S] [-o output] [--keep-cpp]\n";
        std::cerr << "  -S           Emit C++ source only, do not compile\n";
        std::cerr << "  -o file      Output file (executable, or C++ file with -S)\n";
        std::cerr << "  --keep-cpp   Keep the intermediate .cpp file after compiling\n";
        return 1;
    }

    const char* input_file = nullptr;
    const char* output_file = nullptr;
    bool emit_only = false;
    bool keep_cpp = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-S") == 0) {
            emit_only = true;
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
        } else if (strcmp(argv[i], "--keep-cpp") == 0) {
            keep_cpp = true;
        } else if (!input_file) {
            input_file = argv[i];
        }
    }

    if (!input_file) {
        std::cerr << "Error: no input file specified.\n";
        return 1;
    }

    // Determine base name from input
    std::string base(input_file);
    auto dot = base.rfind('.');
    if (dot != std::string::npos) base = base.substr(0, dot);
    auto slash = base.rfind('/');
    if (slash != std::string::npos) base = base.substr(slash + 1);

    yyin = fopen(input_file, "r");
    if (!yyin) {
        std::cerr << "Error: cannot open " << input_file << "\n";
        return 1;
    }

    rpg::Program* program = get_parsed_program();
    fclose(yyin);

    int errors = get_parse_error_count();
    if (errors > 0) {
        std::cerr << errors << " error(s) found. Compilation failed.\n";
        delete program;
        return 1;
    }

    rpg::CodeGen codegen;
    std::string cpp_code = codegen.generate(*program);

    if (emit_only) {
        // -S: emit C++ only
        std::string cpp_path = output_file ? output_file : base + ".cpp";
        std::ofstream out(cpp_path);
        if (!out) {
            std::cerr << "Error: cannot write to " << cpp_path << "\n";
            delete program;
            return 1;
        }
        out << cpp_code;
        delete program;
        return 0;
    }

    // Default: compile to executable
    std::string exe_path = output_file ? output_file : base;

    // Write C++ to temp file (or kept file)
    std::string cpp_path;
    if (keep_cpp) {
        cpp_path = base + ".cpp";
    } else {
        cpp_path = "/tmp/" + base + ".cpp";
    }

    {
        std::ofstream out(cpp_path);
        if (!out) {
            std::cerr << "Error: cannot write to " << cpp_path << "\n";
            delete program;
            return 1;
        }
        out << cpp_code;
    }

    std::string runtime_dir = "runtime";
    std::string cmd = "clang++ -std=c++17 -I" + runtime_dir +
                      " -o " + exe_path + " " + cpp_path;
    int rc = system(cmd.c_str());

    if (!keep_cpp) {
        std::remove(cpp_path.c_str());
    }

    if (rc != 0) {
        std::cerr << "C++ compilation failed.\n";
        delete program;
        return 1;
    }

    delete program;
    return 0;
}
