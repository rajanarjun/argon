
/* TODO: 
1. differences of '=' and '=='
2. alphanumeric case which starts search for following types: identifiers, keywords, and numeric etc.
3. need a lookup table with regexes for above to match them to correct tokentype
   */


#include "lexer.hpp"
#include <iostream>
#include <cctype>


void advance() {
    current_position++;
    current_column++;
}


Token Lexer::get_next_token() {

    Token current_token;
    while (True) {

        if (current_position >= input_text.length())
            return {TokenType::END_OF_FILE};

        char c = input_text[current_position];

        // maybe a condition for whitespace or ignore it completely?
        if (isalnum(c)) {
            // here we pop into another function to figure out if this could
            // be an keyword, identifier or numeric value

        } else {

            switch (c) {
                case '\n':
                    current_line++;
                    current_column = 1;
                    continue;
                case '(':
                    current_token = {TokenType::PUNCTUATION_OPENPAREN, current_line, current_column};
                    advance();
                    break;
                case ')':
                    current_token = {TokenType::PUNCTUATION_CLOSEPAREN, current_line, current_column};
                    advance();
                    break;
                case ':':
                    current_token = {TokenType::PUNCTUATION_COLON, current_line, current_column};
                    advance();
                    break;
                case '#':
                    current_token = {TokenType::PUNCTUATION_COMMENT, current_line, current_column};
                    advance();
                    break;
                case '+':
                    current_token = {TokenType::OPERATOR_PLUS, current_line, current_column};
                    advance();
                    break;
                case '-':
                    current_token = {TokenType::OPERATOR_MINUS, current_line, current_column};
                    advance();
                    break;
                case '*':
                    current_token = {TokenType::OPERATOR_MULTIPLY, current_line, current_column};
                    advance();
                    break;
                case '/':
                    current_token = {TokenType::OPERATOR_DIVIDE, current_line, current_column};
                    advance();
                    break;

                case '=':
                    // this one will have two cases of EQUAL and ASSIGNMENT
                    break;
                case '>':
                    // this will have >= as well
                    break;
                case '<':
                    // this will have <= as well
                    break;

                default:
                    continue;
            }

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
