#ifndef TOKEN_HH
#define TOKEN_HH

#include <map>
#include <string>

namespace token 
{

enum class TokenType {
    ILLEGAL,
    ENDOFFILE,
    
    // Identifiers and literals
    IDENT, // add, foobar, x, y, ...
    INT,   // 123456

    // Operators
    ASSIGN,
    PLUS,

    // Delimiters
    COMMA,
    SEMICOLON,

    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    // Keywords
    FUNCTION,
    LET
};

std::map<char, TokenType> CharToTokenType = {
    {'=', TokenType::ASSIGN},
    {'+', TokenType::PLUS},
    {',', TokenType::COMMA},
    {';', TokenType::SEMICOLON},
    {'(', TokenType::LPAREN},
    {')', TokenType::RPAREN},
    {'{', TokenType::LBRACE},
    {'}', TokenType::RBRACE},
};

class Token {
private:
    TokenType _type;
    std::string _literal;
};

} //namespace token

#endif