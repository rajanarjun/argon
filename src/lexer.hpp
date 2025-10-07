#pragma once

enum class TokenType {
    IDENTIFIER,  // x, y ,c, s, add
    CHAR,        // 'a'
    STRING,      // "hello world"
    NUMBER,      // 12, 99.9
    LET,         // let
    EQUAL,       // =
    END,         // end
    IF,          // if
    ELSE,        // else
    QMARK,       // ?
    PRINT,       // print
    LESS,        // <
    GREATER,     // >
    COLON,       // :
    PLUS,        // +
    MINUS,       // -
    STAR,        // *
    SLASH,       // /
    HASH,        // #
    NUM_TYPE,    // num
    DEC_TYPE,    // dec
    ALP_TYPE,    // alp
    TEXT_TYPE,   // text
    EOF          // END OF FILE
}


class Lexer {
    private:
        std::string input_text;
        int cpos;
        int cline;
        int ccol;
    public:
        Lexer(const std::string& source_contents);

}
