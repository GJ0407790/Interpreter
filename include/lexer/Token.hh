#ifndef TOKEN_HH
#define TOKEN_HH

#include <iostream>
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
	{0  , TokenType::ENDOFFILE}
};

const std::map<std::string, TokenType> KeywordsToTokenType =
{
	{"let", TokenType::LET},
	{"fn" , TokenType::FUNCTION}
};

class Token {
public:
	Token(TokenType tt, std::string literal) : 
			_type{tt}, _literal{std::move(literal)} {}

	bool operator==(const Token& rhs) const;
	bool operator!=(const Token& rhs) const;
	friend std::ostream& operator<<(std::ostream &out, const Token& token);

	// getters
	const std::string& getLiteral() const { return _literal; }
	int getTokenType() const { return static_cast<int>(_type); }

private:
	TokenType _type;
	std::string _literal;
};

} //namespace token

#endif