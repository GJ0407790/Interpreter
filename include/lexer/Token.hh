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

const std::map<char, TokenType> CharToTokenType = 
{
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
public:
	Token(TokenType tt, std::string literal) : 
			_type{tt}, _literal{std::move(literal)} {}

	bool operator==(const Token& rhs) const;
	bool operator!=(const Token& rhs) const;

private:
	TokenType _type;
	std::string _literal;
};

} //namespace token

#endif