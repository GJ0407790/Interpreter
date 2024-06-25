#include "../../../include/parser/node/Statement.hh"

namespace ast
{
using namespace expression;

namespace statement
{

void LetStatement::setName(token::Token token)
{
  _name = Identifier(std::move(token));
}

bool LetStatement::_equals(const Node& other) const
{
  if (typeid(*this) != typeid(other))
  {
    return false;
  }
            
  auto that = static_cast<const LetStatement&>(other);
  
  if (this->_name != that._name)
  {
    return false;
  }
  
  return StatementNode::_equals(other);
}

const std::string LetStatement::toString() const
{
  std::ostringstream os;
  
  // [TODO]: Add the value in
  os << this->tokenLiteral() << " " << _name.toString() << " = ";

  return os.str();
}

const std::string ExpressionStatement::toString() const
{
  std::ostringstream os;
  
  os << _expression.toString();

  return os.str();
}

} //namespace statement
} //namespace ast