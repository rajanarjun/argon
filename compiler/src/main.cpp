#include <iostream>
#include "lexer.hpp"

using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cerr << "   argon: \033[1;31m (fatal error)\033[0m no input files" << endl;
        cout << "Compilation Terminated" << endl;
        return 1;
    }

    string sourceFile;
    int file_found = 0;

    for (int i = 0; i < argc; i++) {
        sourceFile = argv[i];
        size_t pos = sourceFile.find_last_of('.');
        if (pos != string::npos) {
            if (sourceFile.substr(pos + 1)== "ar") {
                file_found = 1;
                break;
            }
        }
    }

    if (file_found == 0) {
        cerr << "   argon: file format not recognized" << endl;
        return 1;
    }


    
   

    return 0;
}
