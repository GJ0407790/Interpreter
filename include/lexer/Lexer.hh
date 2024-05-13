#ifndef LEXER_HH
#define LEXER_HH

#include <string>
#include <vector>

#include "Token.hh"

namespace lexer 
{

class Lexer {
public:
	Lexer(std::string input) : _input{std::move(input)} 
	{
		readChar();
	}

	// Get the next token in the _input
	token::Token nextToken();

private:
		// Reads the current char and advance the _readPos
	void readChar();

private:
	std::string _input;
	int _pos = 0;
	int _read_pos = 0;
	char _chr = 0; // current character being inspected
};

} //namespace lexer

#endif