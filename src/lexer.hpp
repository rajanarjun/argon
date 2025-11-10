/* TODO:
   Need to add more token types as according to lexer.cpp implemetation
   */


#pragma once

#include <string>
#include <vector>

enum class TokenType {
    IDENTIFIER,
    LITERAL_INTEGER,
    LITERAL_FLOAT,
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
    OPERATOR_LESSEQUAL,
    OPERATOR_GREATER,
    OPERATOR_GREATEREQUAL,
    OPERATOR_PLUS,
    OPERATOR_MINUS,
    OPERATOR_MULTIPLY,
    OPERATOR_DIVIDE,
    PUNCTUATION_OPENPAREN,
    PUNCTUATION_CLOSEPAREN,
    PUNCTUATION_COLON,
    PUNCTUATION_QUOTE,
    PUNCTUATION_DQUOTE,
    NO_TOKEN,
    ERROR,
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
    Lexer(const std::string &source_contents);
    std::vector<Token> generate_tokens();
    Token get_next_token();
    Token read_identifier();
    //Token read_number();
    void advance();
    void go_back();
    char peek();
    void advance_until_newline();
    TokenType check_for_keyword(std::string k_word);

private:
    std::string input_text;
    int current_position;
    int current_line;
    int current_column;
    std::vector<Token> token_stream;
};
