#include "../../include/lexer/Lexer.hh"

using namespace token;

namespace lexer
{

void Lexer::readChar() 
{
	if (_read_pos > _input.size()) 
	{
			_chr = 0;
	} else 
	{
		_chr = _input[_read_pos];
	}

	_pos = _read_pos;
	_read_pos++;
}

Token Lexer::nextToken()
{
	auto token = Token{TokenType::ILLEGAL, ""};

	if (CharToTokenType.find(_chr) != CharToTokenType.end()) 
	{
		auto token_type = CharToTokenType.at(_chr);

		// Create a length 1 string
		token = Token{token_type, std::string(1, _chr)};
	}

	readChar(); // read the next char
	return token;
}

} //namespace lexer

