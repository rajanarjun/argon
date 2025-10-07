#include <iostream>
#include <string>
#include <fstream>
#include "lexer.hpp"


std::string get_file_contents(const std::string& filename) {

    std::ifstream input_file(filename, std::ios::binary);

    if (!input_file) {
        std::cerr << "   argon: Failed to open file: " << filename << std::endl;
        return NULL;
    }

    input_file.seekg(0, std::ios::end);
    streamsize fsize = input_file.tellg();
    input_file.seekg(0, std::ios::beg);

    std::string contents(fsize, '\0');
    if (!input_file.read(&contents[0], fsize)) {
        std::cerr << "   argon: Failed to read file: " << filename << std::endl;
        return NULL;
    }

    return contents;
}


int main(int argc, char** argv) {

    if (argc < 2) {
        std::cerr << "   argon: \033[1;31m (fatal error)\033[0m no input files" << std::endl;
        std::cout << "Compilation Terminated" << std::endl;
        return 1;
    }

    std::string source_file;
    int file_found = 0;

    for (int i = 0; i < argc; i++) {
        source_file = argv[i];
        std::size_t pos = source_file.find_last_of('.');
        if (pos != std::string::npos) {
            if (source_file.substr(pos + 1)== "ar") {
                file_found = 1;
                break;
            }
        }
    }

    if (file_found == 0) {
        std::cerr << "   argon: file format not recognized" << std::endl;
        return 1;
    }

    std::string source_file_contents = get_file_contents(source_file);

    Lexer lexer(source_file_contents);

    return 0;
}
