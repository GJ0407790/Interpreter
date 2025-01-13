#ifndef PARSER_HH
#define PARSER_HH

#include <functional>
#include <map>

#include "../lexer/Lexer.hh"
#include "program/Program.hh"

namespace parser
{
using prefixParseFn = std::function<ast::expression::Expression()>;
// takes in a left expression as an argument
using infixParseFn  = std::function<ast::expression::Expression(ast::expression::Expression)>;

enum class Precedence
{
  LOWEST = 0,
  EQUALS = 1,      // ==
  LESSGREATER = 2, // > or <
  SUM = 3,         // +
  PRODUCT = 4,     // *
  PREFIX = 5,      // ++x
  FNCALL = 6,      // fn(x)
};

class Parser 
{
public:
  Parser(std::string input) : _lexer{std::move(input)} 
  {
    // advance two times so that _cur_token points to the first token
    // and _next_token points to the second
    nextToken();
    nextToken();

    // register infix functions
    
  }

  ast::program::Program parseProgram();

  // Getters
  const std::vector<std::string>& getErrors() const
  {
    return _errors;
  }

private:
  // Advance the token pointers to the next token
  void nextToken();

  // helper functions

  // Register the token type to the appropriate functions
  void registerPrefix(token::TokenType tt, prefixParseFn prefix_fn)
  {
    prefix_parse_fn_map[tt] = prefix_fn;
  }

  void registerInfix(token::TokenType tt, infixParseFn infix_fn)
  {
    infix_parse_fn_map[tt] = infix_fn;
  }
  
  // Check whether the tokens are of the correct type
  bool curTokenIs(token::TokenType token_type);
  bool nextTokenIs(token::TokenType token_type);

  // Append an error message to indicate the mismatch of next_token.type and token_type
  void expectMismatchError(token::TokenType token_type);

  // Check if the next token has the same type as token_type
  // If so, advance the token pointer. Otherwise, call expectMismatchError.
  bool expectNext(token::TokenType token_type);

  // Check the token type and call the respective function (below)
  ast::StatementPtr parseStatement();
  
  // Functions for parsing a specific type of statement
  ast::StatementPtr parseLetStatement();
  ast::StatementPtr parseReturnStatement();
  ast::StatementPtr parseExpressionStatement();

  // The core function: parsing expression
  ast::statement::ExpressionPtr parseExpression(Precedence prec);

private:
  lexer::Lexer _lexer;
  token::Token _cur_token;
  token::Token _next_token;
  std::vector<std::string> _errors;

  std::map<token::TokenType, prefixParseFn> prefix_parse_fn_map;
  std::map<token::TokenType, infixParseFn> infix_parse_fn_map;
};

} //namespace parser

#endif //PARSER_HH