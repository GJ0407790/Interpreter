#include "../../include/lexer/Lexer.hh"

using namespace token;

namespace lexer
{

token::TokenType Lexer::lookupIdent(const std::string& lit)
{
	if (KeywordsToTokenType.find(lit) != KeywordsToTokenType.end()) 
	{
			return KeywordsToTokenType.at(lit);
	}

	return TokenType::IDENT;
}


void Lexer::readChar() 
{
	if (_read_pos > _input.size()) 
	{
			_chr = 0;
	} 
	else 
	{
		_chr = _input[_read_pos];
	}

	_pos = _read_pos;
	_read_pos++;
}

std::string Lexer::readIdentifier()
{
	auto start = _pos;

	while (isalpha(_chr))
	{
		readChar();
	}

	return _input.substr(start, _pos - start);
}

std::string Lexer::readNumber()
{
	auto start = _pos;

	while (isdigit(_chr))
	{
		readChar();
	}

	return _input.substr(start, _pos - start);
}

void Lexer::skipWhiteSpaces() 
{
	while (std::isspace(_chr))
	{
		readChar();
	}
}

Token Lexer::nextToken()
{
	auto token = Token{TokenType::ILLEGAL, ""};

	// skip all the spaces before continuing on the next token
	skipWhiteSpaces();

	if (CharToTokenType.find(_chr) != CharToTokenType.end()) 
	{
		auto token_type = CharToTokenType.at(_chr);
		auto lit = _chr == 0 ? "" : std::string(1, _chr);
		
		token = Token{token_type, lit};
	} 
	else if (isalpha(_chr))
	{
		auto ident = readIdentifier();
		auto token_type = lookupIdent(ident);

		// need to return here because _pos is at the next char after ident
		return Token{token_type, std::move(ident)}; 
	}
	else if (isdigit(_chr))
	{
		auto num = readNumber();

		return Token{TokenType::INT, std::move(num)};
	}

	readChar(); // read the next char
	return token;
}

} //namespace lexer

