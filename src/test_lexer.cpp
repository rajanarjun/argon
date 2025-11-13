#include "lexer.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

string token_type_to_string(TokenType type) {
    switch (type) {
        case TokenType::IDENTIFIER:               return "IDENTIFIER";
        case TokenType::LITERAL_INTEGER:          return "LITERAL_INTEGER";
        case TokenType::LITERAL_FLOAT:            return "LITERAL_FLOAT";
        case TokenType::LITERAL_CHAR:             return "LITERAL_CHAR";
        case TokenType::LITERAL_STRING:           return "LITERAL_STRING";

        case TokenType::KEYWORD_LET:              return "KEYWORD_LET";
        case TokenType::KEYWORD_IF:               return "KEYWORD_IF";
        case TokenType::KEYWORD_ELSEIF:           return "KEYWORD_ELSEIF";
        case TokenType::KEYWORD_ELSE:             return "KEYWORD_ELSE";
        case TokenType::KEYWORD_PRINT:            return "KEYWORD_PRINT";
        case TokenType::KEYWORD_NUM:              return "KEYWORD_NUM";
        case TokenType::KEYWORD_DEC:              return "KEYWORD_DEC";
        case TokenType::KEYWORD_ALP:              return "KEYWORD_ALP";
        case TokenType::KEYWORD_TEXT:             return "KEYWORD_TEXT";

        case TokenType::OPERATOR_EQUAL:           return "OPERATOR_EQUAL";
        case TokenType::OPERATOR_ASSIGNMENT:      return "OPERATOR_ASSIGNMENT";
        case TokenType::OPERATOR_NOTEQUAL:        return "OPERATOR_NOTEQUAL";
        case TokenType::OPERATOR_LESS:            return "OPERATOR_LESS";
        case TokenType::OPERATOR_LESSEQUAL:       return "OPERATOR_LESSEQUAL";
        case TokenType::OPERATOR_GREATER:         return "OPERATOR_GREATER";
        case TokenType::OPERATOR_GREATEREQUAL:    return "OPERATOR_GREATEREQUAL";
        case TokenType::OPERATOR_PLUS:            return "OPERATOR_PLUS";
        case TokenType::OPERATOR_MINUS:           return "OPERATOR_MINUS";
        case TokenType::OPERATOR_MULTIPLY:        return "OPERATOR_MULTIPLY";
        case TokenType::OPERATOR_DIVIDE:          return "OPERATOR_DIVIDE";

        case TokenType::PUNCTUATION_OPENPAREN:    return "PUNCT_OPENPAREN";
        case TokenType::PUNCTUATION_CLOSEPAREN:   return "PUNCT_CLOSEPAREN";
        case TokenType::PUNCTUATION_COLON:        return "PUNCT_COLON";
        case TokenType::PUNCTUATION_SEMICOLON:    return "PUNCT_SEMICOLON";
        case TokenType::PUNCTUATION_QUOTE:        return "PUNCT_QUOTE";
        case TokenType::PUNCTUATION_DQUOTE:       return "PUNCT_DQUOTE";

        case TokenType::NO_TOKEN:                 return "NO_TOKEN";
        case TokenType::ERROR:                    return "ERROR";
        case TokenType::END_OF_FILE:              return "END_OF_FILE";
    }

    return "UNKNOWN";
}


void print_tokens(const vector<Token>& tokens) {
    const int WIDTH_TYPE   = 30;
    const int WIDTH_LEX    = 20;
    const int WIDTH_LINE   = 10;
    const int WIDTH_COLUMN = 10;

    cout << std::string(WIDTH_TYPE + WIDTH_LEX + WIDTH_LINE + WIDTH_COLUMN, '-') << "\n";

    cout << left
         << setw(WIDTH_TYPE)   << "Token Type"
         << setw(WIDTH_LEX)    << "Lexeme"
         << setw(WIDTH_LINE)   << "Line"
         << setw(WIDTH_COLUMN) << "Column"
         << "\n";

    cout << std::string(WIDTH_TYPE + WIDTH_LEX + WIDTH_LINE + WIDTH_COLUMN, '-') << "\n";

    for (const Token& t : tokens) {
        cout << left
             << setw(WIDTH_TYPE)   << token_type_to_string(t.type)
             << setw(WIDTH_LEX)    << t.lexeme
             << setw(WIDTH_LINE)   << t.line
             << setw(WIDTH_COLUMN) << t.column
             << "\n";
    }

    cout << std::string(WIDTH_TYPE + WIDTH_LEX + WIDTH_LINE + WIDTH_COLUMN, '-') << "\n";
    cout << "\n";
}

