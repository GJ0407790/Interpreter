#ifndef TOKEN_HH
#define TOKEN_HH

#include <iostream>
#include <map>
#include <string>

namespace token 
{

enum class TokenType {
	ILLEGAL,
	END_OF_FILE,
	
	// Identifiers and literals
	IDENT, // add, foobar, x, y, ...
	INT,   // 123456

	// Operators
	ASSIGN,
	PLUS,
	MINUS,
	BANG,
	ASTERISK,
	SLASH,
	LT,
	GT,
	EQ,
	NOT_EQ,

	// Delimiters
	COMMA,
	SEMICOLON,

	LPAREN,
	RPAREN,
	LBRACE,
	RBRACE,

	// Keywords
	FUNCTION,
	LET,
	TRUE,
	FALSE,
	IF,
	ELSE,
	RETURN
};

// Maps the token type to string representation
const std::map<TokenType, std::string> TokenTypeToString =
{
	{TokenType::ILLEGAL, "ILLEGAL"},
	{TokenType::END_OF_FILE, "END_OF_FILE"},
	{TokenType::IDENT, "IDENT"},
	{TokenType::INT, "INT"},
	{TokenType::ASSIGN, "ASSIGN"},
	{TokenType::PLUS, "PLUS"},
	{TokenType::MINUS, "MINUS"},
	{TokenType::BANG, "BANG"},
	{TokenType::ASTERISK, "ASTERISK"},
	{TokenType::SLASH, "SLASH"},
	{TokenType::LT, "LT"},
	{TokenType::GT, "GT"},
	{TokenType::EQ, "EQ"},
	{TokenType::NOT_EQ, "NOT_EQ"},
	{TokenType::COMMA, "COMMA"},
	{TokenType::SEMICOLON, "SEMICOLON"},
	{TokenType::LPAREN, "LPAREN"},
	{TokenType::RPAREN, "RPAREN"},
	{TokenType::LBRACE, "LBRACE"},
	{TokenType::RBRACE, "RBRACE"},
	{TokenType::FUNCTION, "FUNCTION"},
	{TokenType::LET, "LET"},
	{TokenType::TRUE, "TRUE"},
	{TokenType::FALSE, "FALSE"},
	{TokenType::IF, "IF"},
	{TokenType::ELSE, "ELSE"},
	{TokenType::RETURN, "RETURN"}
};

const std::map<char, TokenType> CharToTokenType = 
{
	{'+', TokenType::PLUS},
	{'-', TokenType::MINUS},
	{'*', TokenType::ASTERISK},
	{'/', TokenType::SLASH},
	{'<', TokenType::LT},
	{'>', TokenType::GT},
	{',', TokenType::COMMA},
	{';', TokenType::SEMICOLON},
	{'(', TokenType::LPAREN},
	{')', TokenType::RPAREN},
	{'{', TokenType::LBRACE},
	{'}', TokenType::RBRACE},
	{0  , TokenType::END_OF_FILE}
};

const std::map<std::string, TokenType> KeywordsToTokenType =
{
	{"let", TokenType::LET},
	{"fn" , TokenType::FUNCTION},
	{"true", TokenType::TRUE},
	{"false", TokenType::FALSE},
	{"if", TokenType::IF},
	{"else", TokenType::ELSE},
	{"return", TokenType::RETURN}
};

class Token {
public:
	Token() : _type{TokenType::ILLEGAL}, _literal{} {}

	Token(TokenType tt, std::string literal) : 
			_type{tt}, _literal{std::move(literal)} {}

	bool operator==(const Token& rhs) const;
	bool operator!=(const Token& rhs) const;
	friend std::ostream& operator<<(std::ostream &out, const Token& token);

	// getters
	const std::string& getLiteral() const { return _literal; }
	TokenType getTokenType() const { return _type; }

private:
	TokenType _type;
	std::string _literal;
};

} //namespace token

#endif // TOKEN_HH
