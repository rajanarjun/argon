#include <iostream>
#include <filesystem>
#include "lexer.h"


int main(int argc, char** argv) {

    if (argc < 2) {
        std::cerr << "   argon: \033[1;31m (fatal error)\033[0m no input files" << std::endl;
        std::cout << "Compilation Terminated" << std::endl;
        return 1;
    }

    std::filesystem::path _FILE;
    int file_found = 0;

    for (int i = 0; i < argc; i++) {
        _FILE = argv[i];
        if (_FILE.extension() == ".ar") {
            file_found = 1;
            break;
        }
    }

    if (file_found == 0) {
        std::cerr << "   argon: file format not recognized" << std::endl;
        return 1;
    } else {
        std::cout << "   argon: compiling file: " << _FILE << std::endl;
    }

    return 0;
}
