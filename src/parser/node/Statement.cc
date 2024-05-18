#include "../../../include/parser/node/Statement.hh"

namespace ast
{
namespace statement
{

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

} //namespace statement
} //namespace ast