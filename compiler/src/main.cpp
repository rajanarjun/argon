#include <iostream>
#include <fstream>
#include "lexer.hpp"


using namespace std;


string get_file_contents(const string& filename) {

    ifstream input_file(filename, ios::binary);

    if (!input_file) {
        cerr << "   argon: Failed to open file: " << filename << endl;
        return NULL;
    }

    input_file.seekg(0, ios::end);
    streamsize fsize = input_file.tellg();
    input_file.seekg(0, ios::beg);

    string contents(fsize, '\0');
    if (!input_file.read(&contents[0], fsize)) {
        cerr << "   argon: Failed to read file: " << filename << endl;
        return NULL;
    }

    return contents;
}


int main(int argc, char** argv) {

    if (argc < 2) {
        cerr << "   argon: \033[1;31m (fatal error)\033[0m no input files" << endl;
        cout << "Compilation Terminated" << endl;
        return 1;
    }

    string source_file;
    int file_found = 0;

    for (int i = 0; i < argc; i++) {
        source_file = argv[i];
        size_t pos = source_file.find_last_of('.');
        if (pos != string::npos) {
            if (source_file.substr(pos + 1)== "ar") {
                file_found = 1;
                break;
            }
        }
    }

    if (file_found == 0) {
        cerr << "   argon: file format not recognized" << endl;
        return 1;
    }

    string source_file_contents = get_file_contents(source_file);

    cout << source_file_contents << endl;
   

    return 0;
}
