#include <sstream>

#include "../../include/parser/Parser.hh"

using namespace token;
using namespace ast;
using namespace ast::program;
using namespace ast::statement;

namespace parser
{

Program Parser::parseProgram()
{
  Program program;

  while (_cur_token.getTokenType() != TokenType::END_OF_FILE)
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

bool Parser::curTokenIs(TokenType token_type)
{
  return _cur_token.getTokenType() == token_type;
}

bool Parser::nextTokenIs(TokenType token_type)
{
  return _next_token.getTokenType() == token_type;
}

void Parser::expectMismatchError(TokenType token_type)
{
  std::ostringstream os;

  os << "Expected next_token to be of token_type=" << token::TokenTypeToString.at(token_type) 
     << ", got " << token::TokenTypeToString.at(_next_token.getTokenType());
  
  _errors.push_back(os.str());
}

bool Parser::expectNext(TokenType token_type)
{
  if (nextTokenIs(token_type))
  {
    nextToken();
    return true;
  }

  expectMismatchError(token_type);
  return false;
}

StatementPtr Parser::parseStatement()
{
  switch (_cur_token.getTokenType())
  {
  case TokenType::LET:
    return parseLetStatement();
  default:
    nextToken();
    return nullptr;
  }  
}

/* A general let statement format is:
 *  `let IDENT = EXPRESSION;`
 * 
 * Consist of the following in order:
 *  1. LET token
 *  2. IDENT token
 *  3. EQUAL token
 *  4. EXPRESSION node
 */
StatementPtr Parser::parseLetStatement()
{
  auto let_statement = std::make_shared<LetStatement>(_cur_token);

  if (!expectNext(TokenType::IDENT))
  {
    nextToken();
    return nullptr;
  }

  // Since expectNext will advance the pointer if the type matches
  // the current token is the ident token
  let_statement->setName(_cur_token);

  if (!expectNext(TokenType::ASSIGN))
  {
    return nullptr;
  }

  // TODO: Read equal and RHS expression
  while (!curTokenIs(TokenType::SEMICOLON))
  {
    nextToken();
  }

  nextToken();
  return let_statement;
}

} //namespace parser