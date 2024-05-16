#ifndef PARSER_HH
#define PARSER_HH

#include "../lexer/Lexer.hh"
#include "program/Program.hh"

namespace parser
{

class Parser 
{
public:
  Parser(std::string input) : _lexer{std::move(input)} 
  {
    // advance two times so that _cur_token points to the first token
    // and _next_token points to the second
    nextToken();
    nextToken();
  }

  ast::program::Program parseProgram();

private:
  // Advance the token pointers to the next token
  void nextToken();

  // Check the token type and call the respective function
  ast::StatementPtr parseStatement();

  ast::StatementPtr parseLetStatement();

private:
  lexer::Lexer _lexer;
  token::Token _cur_token;
  token::Token _next_token;
};

} //namespace parser

#endif //PARSER_HH