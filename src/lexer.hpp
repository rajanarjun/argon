#pragma once

#include <string>

enum class TokenType {
    IDENTIFIER,
    CONSTANT_INTEGER,
    CONSTANT_FLOATING,
    LITERAL_CHAR,
    LITERAL_STRING,
    KEYWORD_LET,
    KEYWORD_IF, 
    KEYWORD_ELSEIF,
    KEYWORD_ELSE,
    KEYWORD_PRINT,
    KEYWORD_NUM,
    KEYWORD_DEC,
    KEYWORD_ALP,
    KEYWORD_TEXT,
    OPERATOR_EQUAL,
    OPERATOR_LESS,
    OPERATOR_GREATER,
    OPERATOR_PLUS,
    OPERATOR_MINUS,
    OPERATOR_STAR,
    OPERATOR_SLASH,
    PUNCTUATION_OPENPAREN,
    PUNCTUATION_CLOSEPAREN,
    PUNCTUATION_COLON,
    PUNCTUATION_HASH,
    END_OF_FILE
};

class Lexer {
private:
    std::string input_text;
    int cpos;
    int cline;
    int ccol;

public:
    Lexer(const std::string &source_contents);
};
