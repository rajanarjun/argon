#include "lexer.hpp"
#include <iostream>

Lexer::Lexer(const std::string &source_contents) : input_text(source_contents), 
                                                   current_position(0), 
                                                   current_line(1), 
                                                   current_column(1) {}


void advance() {
    current_position++;
    current_column++;
}


Token Lexer::get_next_token() {

    Token current_token;

    while (True) {

        if (current_position >= input_text.length())
            return Token(TokenType::END_OF_FILE);

        char c = input_text[current_position];
        switch (c) {
            case '\n':
                current_line++;
                current_column = 1;
                continue;
            case '(':
                current_token = Token(TokenType::PUNCTUATION_OPENPAREN, "", current_line, current_column);
                advance();
                break;
            case ')':
                current_token = Token(TokenType::PUNCTUATION_CLOSEPAREN, "", current_line, current_column);
                advance();
                break;
            case ':':
                current_token = Token(TokenType::PUNCTUATION_COLON, "", current_line, current_column);
                advance();
                break;
            case '#':
                current_token = Token(TokenType::PUNCTUATION_HASH, "", current_line, current_column);
                advance();
                break;
            default:
                advance();
                continue;
        }
    }

    return current_token;
}


vector<Token> Lexer::generate_tokens() {

    while (True) {

        Token token = get_next_token();
        token_stream.push_back(token);

        if (token.type == TokenType::END_OF_FILE) {
            break;
        }
    }

    return token_stream;
}
