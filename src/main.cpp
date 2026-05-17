#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <climits>
#include <cstdlib>
#include "ast.h"
#include "codegen.h"
#include "conf.h"
#include "extdesc.h"

#ifndef RPGC_RUNTIME_DIR
#define RPGC_RUNTIME_DIR "/usr/local/share/rpgc/runtime"
#endif

#ifndef RPGC_VERSION
#define RPGC_VERSION "dev"
#endif

extern FILE* yyin;
extern rpg::Program* get_parsed_program();
extern int get_parse_error_count();

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "--version") == 0) {
        std::cout << "rpgc " << RPGC_VERSION << "\n";
        return 0;
    }

    if (argc < 2) {
        std::cerr << "Usage: rpgc <input.rpgle> [-S] [-g] [-o output] [--keep-cpp]\n";
        std::cerr << "  -S           Emit C++ source only, do not compile\n";
        std::cerr << "  -g           Compile with debug info (for GDB/LLDB/VS Code)\n";
        std::cerr << "  -o file      Output file (executable, or C++ file with -S)\n";
        std::cerr << "  --keep-cpp   Keep the intermediate .cpp file after compiling\n";
        std::cerr << "  --version    Print version and exit\n";
        return 1;
    }

    const char* input_file = nullptr;
    const char* output_file = nullptr;
    bool emit_only = false;
    bool keep_cpp = false;
    bool debug_mode = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-S") == 0) {
            emit_only = true;
        } else if (strcmp(argv[i], "-g") == 0) {
            debug_mode = true;
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

    // Load rpgc.conf
    RpgConf conf = RpgConf::load();

    // Read source for pre-pass (extdesc query)
    std::string src_text;
    {
        std::ifstream src_f(input_file);
        if (!src_f) {
            std::cerr << "Error: cannot open " << input_file << "\n";
            return 1;
        }
        std::ostringstream ss;
        ss << src_f.rdbuf();
        src_text = ss.str();
    }

    // Determine source directory for .extdesc cache lookup
    std::string src_dir;
    {
        std::string inp(input_file);
        auto sl = inp.rfind('/');
        src_dir = (sl != std::string::npos) ? inp.substr(0, sl) : ".";
    }

    // Preemptive EXTDESC pass: query DB schema (or read cache)
    auto ext_descs = queryExternalDescs(src_text, src_dir, conf);

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

    // Resolve absolute path to source file for #line directives
    std::string abs_source;
    {
        char buf[PATH_MAX];
        if (realpath(input_file, buf)) abs_source = buf;
        else abs_source = input_file;
    }

    bool has_rla = !ext_descs.empty();

    rpg::CodeGen codegen;
    if (debug_mode) codegen.setDebugMode(true, abs_source);
    codegen.setExtFileDescs(std::move(ext_descs));
    if (!conf.db_dsn.empty()) codegen.setConfDsn(conf.db_dsn);
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

    // Detect SQL/RLA source: .sqlrpgle extension or source contains DCL-F DISK
    std::string input_str(input_file);
    bool is_sql = false;
    if (input_str.size() >= 9) {
        std::string ext = input_str.substr(input_str.size() - 9);
        for (auto& c : ext) c = tolower(static_cast<unsigned char>(c));
        if (ext == ".sqlrpgle") is_sql = true;
    }
    // Also flag as SQL if any DCL-F DISK file was found (needs ODBC link)
    if (has_rla) is_sql = true;

    // Find runtime headers: check relative to binary, cwd, then install prefix
    auto dir_exists = [](const std::string& path) {
        struct stat st;
        return stat(path.c_str(), &st) == 0 && S_ISDIR(st.st_mode);
    };

    std::string runtime_dir;
    // 1) Relative to the rpgc binary (e.g. ./runtime when run from source tree)
    std::string self(argv[0]);
    size_t last_slash = self.find_last_of("/\\");
    if (last_slash != std::string::npos) {
        std::string bin_dir = self.substr(0, last_slash);
        if (dir_exists(bin_dir + "/runtime"))
            runtime_dir = bin_dir + "/runtime";
    }
    // 2) Current working directory
    if (runtime_dir.empty() && dir_exists("runtime"))
        runtime_dir = "runtime";
    // 3) Installed location (compile-time default)
    if (runtime_dir.empty() && dir_exists(RPGC_RUNTIME_DIR))
        runtime_dir = RPGC_RUNTIME_DIR;

    if (runtime_dir.empty()) {
        std::cerr << "Error: cannot find rpgc runtime headers.\n"
                  << "Looked in: ./runtime, " << RPGC_RUNTIME_DIR << "\n";
        delete program;
        return 1;
    }

    std::string cmd = "clang++ -std=c++17 -I" + runtime_dir;
    if (debug_mode) {
        cmd += " -g -O0";
    }
    if (is_sql) {
        cmd += " -I/opt/homebrew/include -L/opt/homebrew/lib -lodbc";
    }
    cmd += " -o " + exe_path + " " + cpp_path;
    int rc = system(cmd.c_str());

    if (!keep_cpp) {
        std::remove(cpp_path.c_str());
    }

    if (rc != 0) {
        std::cerr << "C++ compilation failed.\n";
        delete program;
        return 1;
    }

    // Generate .vscode/launch.json for VS Code debugging
    if (debug_mode) {
        // Resolve absolute path to the output binary
        std::string abs_exe;
        {
            char buf[PATH_MAX];
            if (realpath(exe_path.c_str(), buf)) abs_exe = buf;
            else abs_exe = exe_path;
        }

        // Create .vscode directory if needed
        struct stat st;
        if (stat(".vscode", &st) != 0) {
            mkdir(".vscode", 0755);
        }

        // Choose debugger type based on platform
#if defined(_WIN32)
        std::string dbg_type = "cppvsdbg";
        std::string dbg_ext  = "ms-vscode.cpptools";
        std::string dbg_ext_name = "C/C++ (ms-vscode.cpptools)";
#else
        std::string dbg_type = "lldb";
        std::string dbg_ext  = "vadimcn.vscode-lldb";
        std::string dbg_ext_name = "CodeLLDB (vadimcn.vscode-lldb)";
#endif

        std::ofstream launch(".vscode/launch.json");
        if (launch) {
            launch << "{\n";
            launch << "    \"version\": \"0.2.0\",\n";
            launch << "    \"configurations\": [\n";
            launch << "        {\n";
            launch << "            \"type\": \"" << dbg_type << "\",\n";
            launch << "            \"request\": \"launch\",\n";
            launch << "            \"name\": \"Debug " << base << "\",\n";
            launch << "            \"program\": \"" << abs_exe << "\",\n";
            launch << "            \"args\": [],\n";
            launch << "            \"cwd\": \"${workspaceFolder}\"\n";
            launch << "        }\n";
            launch << "    ]\n";
            launch << "}\n";
            std::cerr << "Debug info written to .vscode/launch.json\n";
            std::cerr << "Install the " << dbg_ext_name << " extension in VS Code, then press F5 to debug.\n";
        }
    }

    delete program;
    return 0;
}
