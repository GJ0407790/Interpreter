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

  // helper functions
  
  // Check whether the tokens are of the correct type
  bool curTokenIs(token::TokenType token_type);
  bool nextTokenIs(token::TokenType token_type);

  // Check if the next token has the same type as token_type
  // If so, advance the token pointer. Otherwise, return false.
  bool expectNext(token::TokenType token_type);

  // Check the token type and call the respective function (below)
  ast::StatementPtr parseStatement();

  // Functions for parsing a specific type of statement
  ast::StatementPtr parseLetStatement();

private:
  lexer::Lexer _lexer;
  token::Token _cur_token;
  token::Token _next_token;
};

} //namespace parser

#endif //PARSER_HH