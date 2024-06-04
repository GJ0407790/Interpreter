#include "../../../include/parser/node/Statement.hh"

namespace ast
{
using namespace expression;

namespace statement
{

void LetStatement::setName(token::Token token)
{
  _name = NonValueIdentifierNode(std::move(token));
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

void LetStatement::printInfo(std::ostream &out) const
{
  Node::printInfo(out);
  out << "\n";

  out << "_name: " << _name;
}

} //namespace statement
} //namespace ast