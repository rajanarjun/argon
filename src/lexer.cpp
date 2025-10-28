
/* TODO: 
1. differences of '=' and '=='
2. alphanumeric case which starts search for following types: identifiers, keywords, and numeric etc.
3. need a lookup table with regexes for above to match them to correct tokentype
   */


#include "lexer.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <vector>


void Lexer::advance() {
    current_position++;
    current_column++;
}


char Lexer::peek() {
    return input_text[current_position];
}


Token Lexer::get_identifier_or_keyword() {
    std::string word = "";

    // keep peeking and appending to word until invalid char appears
    char c = peek();
    while (c != ' ') { //|| c != '=' || c != '+' || c != '*' || c != '-' || c != '/' || c != '<' || c != '>') {

        word += c;
        advance();
        c = peek();
    }
    // now check if the word is a keyword or identifier from a lookup
    return {TokenType::IDENTIFIER, current_line, current_column, word};
}


//Token Lexer::get_integer_or_float() {
    //std::string number = "";
//
//}


Token Lexer::get_next_token() {

    Token current_token;
    while (true) {

        if (current_position >= input_text.length() - 1) {
            return {TokenType::END_OF_FILE};
        }

        char c = peek();

        if (std::isalpha(c)) {
            current_token = get_identifier_or_keyword();
            break;
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
                    current_token = {TokenType::OPERATOR_EQUAL, current_line, current_column};
                    advance();
                    break;

                //case '>':
                    //// this will have >= as well
                    //break;
                //case '<':
                    //// this will have <= as well
                    //break;

                default:
                    advance();
                    continue;
            }
            break;
        }
    }
    return current_token;
}


std::vector<Token> Lexer::generate_tokens() {

    while (true) {

        Token token = get_next_token();
        token_stream.push_back(token);

        if (token.type == TokenType::END_OF_FILE) {
            break;
        }
    }

    return token_stream;
}
