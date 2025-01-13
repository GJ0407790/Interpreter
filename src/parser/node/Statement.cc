#include "../../../include/parser/node/Statement.hh"

namespace ast
{
using namespace expression;

namespace statement
{

/*******************************************************************************************/
/*******************************   LET STATEMENT   *****************************************/
/*******************************************************************************************/

void LetStatement::setName(token::Token token)
{
  auto literal = token.getLiteral();
  _name = std::make_unique<Identifier>(std::move(token), std::move(literal));
}

const std::string LetStatement::toString() const
{
  std::ostringstream os;
  
  os << this->tokenLiteral() << " ";
  
  if (_name != nullptr)
  {
    os << _name->toString();
  }
  
  os  << " = "; 
  
  if (_value != nullptr)
  {
    os << _value->toString();
  }

  os << ";";

  return os.str();
}

/*******************************************************************************************/
/*****************************   RETURN STATEMENT   ****************************************/
/*******************************************************************************************/

const std::string ReturnStatement::toString() const
{
  std::ostringstream os;
  
  os << this->tokenLiteral() << " " << _return_value->toString() << ";";

  return os.str();
}

/*******************************************************************************************/
/***************************   EXPRESSION STATEMENT   **************************************/
/*******************************************************************************************/

const std::string ExpressionStatement::toString() const
{
  std::ostringstream os;
  
  os << _expression->toString();

  return os.str();
}

} //namespace statement
} //namespace ast