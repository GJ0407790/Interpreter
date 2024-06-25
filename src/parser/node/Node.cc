#include "../../../include/parser/node/Node.hh"

namespace ast
{
namespace node
{

const std::string& Node::tokenLiteral() const
{
  return _token.getLiteral();
}

bool Node::_equals(const Node& other) const
{
  if (typeid(*this) != typeid(other))
  {
    return false;
  }
            
  return this->_token == other._token;
}

std::ostream& operator<<(std::ostream &out, const Node& node) 
{
  out << node.toString();

  return out;
}

} //namespace node
} //namespace ast