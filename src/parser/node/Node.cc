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

void Node::printInfo(std::ostream &out) const
{
  out << "Node token: " << _token;
}

std::ostream& operator<<(std::ostream &out, const Node& node) 
{
  node.printInfo(out);

  return out;
}

} //namespace node
} //namespace ast