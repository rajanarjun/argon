
/* TODO: 
1. cases: ==, >=, <=, !=
2. read_number function to get integer and float
3. cases for char and string after going into ' or "
   */

#include "lexer.hpp"
#include <iostream>
#include <cctype>
#include <string>
#include <vector>


Lexer::Lexer(const std::string &source_contents) : input_text(source_contents), 
                                                   current_position(0), 
                                                   current_line(1), 
                                                   current_column(1) {}


void Lexer::advance() {
    current_position++;
    current_column++;
}


char Lexer::peek() {
    return input_text[current_position];
}

TokenType Lexer::check_for_keyword(std::string k_word) {

    if (k_word == "let") {
        return TokenType::KEYWORD_LET;
    } else if (k_word == "if") {
        return TokenType::KEYWORD_IF;
    } else if (k_word == "elseif") {
        return TokenType::KEYWORD_ELSEIF;
    } else if (k_word == "else") {
        return TokenType::KEYWORD_ELSE;
    } else if (k_word == "print") {
        return TokenType::KEYWORD_PRINT;
    } else if (k_word == "num") {
        return TokenType::KEYWORD_NUM;
    } else if (k_word == "dec") {
        return TokenType::KEYWORD_DEC;
    } else if (k_word == "alp") {
        return TokenType::KEYWORD_ALP;
    } else if (k_word == "text") {
        return TokenType::KEYWORD_TEXT;
    }

    return TokenType::NO_TOKEN;
}


Token Lexer::read_identifier() {
    std::string word = "";

    // keep peeking and appending to word until invalid char appears
    char c = peek();
    while (true) {

        // punctuation
        if (c == '(' || c == ')' || c == '\'' || c == '"' || c == ',') {
            break;
        }
        // math operators
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            break;
        }
        // comparison operators
        if (c == '=' || c == '>' || c == '<') {
            break;
        }
        // whitespace
        if (c == ' ') {
            break;
        }

        word += c;
        advance();
        c = peek();
    }

    // now check if the word is a keyword from a lookup
    TokenType keyword_token = check_for_keyword(word);
    if (keyword_token != TokenType::NO_TOKEN) {
        return {keyword_token, current_line, current_column, word};
    }

    return {TokenType::IDENTIFIER, current_line, current_column, word};
}

// TODO:
//Token Lexer::read_number() {
//
//}


void Lexer::advance_until_newline() {
   char c = peek();
   while (c != '\n') {
       advance();
       c = peek();
   }
}


Token Lexer::get_next_token() {

    Token current_token;
    while (true) {

        if (current_position >= input_text.length() - 1) {
            return {TokenType::END_OF_FILE};
        }

        char c = peek();

        if (std::isalpha(c) || c == '_') {
            current_token = read_identifier();
            break;
        } 

        //else if (std::isdigit(c)) {
            //current_token = read_number();
            //break;
        //}

        else {

            switch (c) {
                case '\n':
                    current_line++;
                    current_column = 1;
                    continue;
                case '#':
                    advance_until_newline();
                    current_line++;
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
                    // this one will also have "==" assignment case
                    current_token = {TokenType::OPERATOR_EQUAL, current_line, current_column};
                    advance();
                    break;
                case '!':
                    // for != case
                    current_token = {TokenType::OPERATOR_NOTEQUAL, current_line, current_column};
                    advance();
                    break;
                case '>':
                    // this will have >= as well
                    current_token = {TokenType::OPERATOR_GREATER, current_line, current_column};
                    advance();
                    break;
                case '<':
                    // this will have <= as well
                    current_token = {TokenType::OPERATOR_LESS, current_line, current_column};
                    advance();
                    break;
                case '\'':
                    // this will be char case 'x'
                    current_token = {TokenType::PUNCTUATION_QUOTE, current_line, current_column};
                    advance();
                    break;
                case '"':
                    // this will be string case "helloworld"
                    current_token = {TokenType::PUNCTUATION_DQUOTE, current_line, current_column};
                    advance();
                    break;
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
