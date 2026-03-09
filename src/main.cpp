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
        std::cerr << "Usage: rpgc <input.rpgle> [-o output.cpp]\n";
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = nullptr;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
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

    if (output_file) {
        std::ofstream out(output_file);
        if (!out) {
            std::cerr << "Error: cannot write to " << output_file << "\n";
            delete program;
            return 1;
        }
        out << cpp_code;
    } else {
        std::cout << cpp_code;
    }

    delete program;
    return errors > 0 ? 1 : 0;
}
