#ifndef LEXER_HH
#define LEXER_HH

#include <string>

namespace lexer 
{

class Lexer {
public:
    Lexer(std::string input) : _input{std::move(input)} {}

    // Reads the current char and advance the _readPos
    void readChar();

private:
    std::string _input;
    int _pos = 0;
    int _read_pos = 0;
    char _chr; // current character being inspected
};

} //namespace lexer

#endif