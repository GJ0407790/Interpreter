#include "../../../include/parser/node/Expression.hh"

namespace ast
{
namespace expression
{

bool NonValueIdentifierNode::_equals(const Node& other) const
{
  if (typeid(*this) != typeid(other))
  {
    return false;
  }

  // There are no members in NonValueIdentifierNode
  // If there is, need to check the equality of each member here

  return IdentifierNode::_equals(other);
}

} //namespace expresison
} //namespace ast
