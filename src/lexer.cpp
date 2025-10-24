/*
 * Lexical Analyzer
 *
 * First step of the compiler:
 * This file will take in the source code as a
 * series of characters and group it into tokens.
 *
 */

#include "lexer.hpp"
#include <iostream>

Lexer::Lexer(const std::string &source_contents)
    : input_text(source_contents), cpos(0), cline(1), ccol(1) {

  std::cout << source_contents << std::endl;
}
