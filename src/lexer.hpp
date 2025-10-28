/* TODO:
   Need to add more token types as according to lexer.cpp implemetation
   */


#pragma once

#include <string>
#include <vector>

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
    OPERATOR_ASSIGNMENT,
    OPERATOR_NOTEQUAL,
    OPERATOR_LESS,
    OPERATOR_GREATER,
    OPERATOR_PLUS,
    OPERATOR_MINUS,
    OPERATOR_MULTIPLY,
    OPERATOR_DIVIDE,
    PUNCTUATION_OPENPAREN,
    PUNCTUATION_CLOSEPAREN,
    PUNCTUATION_COLON,
    PUNCTUATION_COMMENT,
    END_OF_FILE
};


struct Token {
    TokenType type;
    int line = 0;
    int column = 0;
    std::string value = "";
};


class Lexer {
public:
    Lexer(const std::string &source_contents) : input_text(source_contents), 
                                                current_position(0), 
                                                current_line(1), 
                                                current_column(1) {}

    std::vector<Token> generate_tokens();
    Token get_next_token();
    Token get_identifier_or_keyword();
    Token get_integer_or_float();
    void advance();
    char peek();
    

private:
    std::string input_text;
    TokenType current_token;
    int current_position;
    int current_line;
    int current_column;
    std::vector<Token> token_stream;
};
