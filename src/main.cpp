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
        std::cerr << "Usage: rpgc <input.rpgle> [-o output] [-x]\n";
        std::cerr << "  -o file   Write C++ output to file (default: stdout)\n";
        std::cerr << "  -x        Compile the generated C++ into an executable\n";
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = nullptr;
    bool compile = false;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
        } else if (strcmp(argv[i], "-x") == 0) {
            compile = true;
        }
    }

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

    // Determine the C++ output path
    std::string cpp_path;
    if (output_file) {
        cpp_path = output_file;
        if (compile && cpp_path.size() > 4 && cpp_path.substr(cpp_path.size() - 4) != ".cpp") {
            // If -x and output doesn't end in .cpp, treat -o as the executable name
            // and use a temp file for the C++
            cpp_path = std::string(output_file) + ".cpp";
        }
    } else if (compile) {
        // Need a temp file for the C++ when compiling without -o
        std::string base(input_file);
        auto dot = base.rfind('.');
        if (dot != std::string::npos) base = base.substr(0, dot);
        auto slash = base.rfind('/');
        if (slash != std::string::npos) base = base.substr(slash + 1);
        cpp_path = "/tmp/" + base + ".cpp";
    }

    if (!cpp_path.empty()) {
        std::ofstream out(cpp_path);
        if (!out) {
            std::cerr << "Error: cannot write to " << cpp_path << "\n";
            delete program;
            return 1;
        }
        out << cpp_code;
    } else {
        std::cout << cpp_code;
    }

    if (compile) {
        // Determine executable output name
        std::string exe_path;
        if (output_file) {
            exe_path = output_file;
            // If -o ends in .cpp, strip it for the executable
            if (exe_path.size() > 4 && exe_path.substr(exe_path.size() - 4) == ".cpp") {
                exe_path = exe_path.substr(0, exe_path.size() - 4);
            }
        } else {
            std::string base(input_file);
            auto dot = base.rfind('.');
            if (dot != std::string::npos) base = base.substr(0, dot);
            auto slash = base.rfind('/');
            if (slash != std::string::npos) base = base.substr(slash + 1);
            exe_path = base;
        }

        // Find runtime directory relative to the rpgc executable
        std::string runtime_dir = "runtime";

        std::string cmd = "clang++ -std=c++17 -I" + runtime_dir +
                          " -o " + exe_path + " " + cpp_path;
        int rc = system(cmd.c_str());
        if (rc != 0) {
            std::cerr << "C++ compilation failed.\n";
            delete program;
            return 1;
        }
    }

    delete program;
    return 0;
}
