#include "../../../include/parser/node/Node.hh"

namespace ast
{
namespace node
{

const std::string& Node::tokenLiteral() const
{
  return _token.getLiteral();
}

std::ostream& operator<<(std::ostream &out, const Node& node) 
{
  out << node.toString();

  return out;
}

} //namespace node
} //namespace ast