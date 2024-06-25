#include "../../../include/parser/node/Expression.hh"

namespace ast
{
namespace expression
{

bool Expression::_equals(const Node& other) const
{
  if (typeid(*this) != typeid(other))
  {
    return false;
  }

  auto that = static_cast<const Expression&>(other);
  
  if (this->_value != that._value)
  {
    return false;
  }

  return Node::_equals(other);
}

const std::string Expression::toString() const
{
  return "";
}

const std::string Identifier::toString() const
{
  std::ostringstream os;
  
  os << tokenLiteral();

  return os.str();
}

} //namespace expresison
} //namespace ast
