#include "../../include/parser/Parser.hh"

using namespace token;
using namespace ast;
using namespace ast::program;

namespace parser
{

Program Parser::parseProgram()
{
  Program program;

  while (_cur_token.getTokenType() != TokenType::ENDOFFILE)
  {
    auto statement = parseStatement();

    if (statement != nullptr)
    {
      program.addStatement(std::move(statement));
    }
  }

  return program;
}

void Parser::nextToken()
{
  _cur_token = std::move(_next_token);
  _next_token = _lexer.nextToken();
}

StatementPtr Parser::parseStatement()
{
  switch (_cur_token.getTokenType() )
  {
  case TokenType::LET:
    return parseLetStatement();
  default:
    return nullptr;
  }  
}

StatementPtr Parser::parseLetStatement()
{
  
}

} //namespace parser