#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#include "Node.hh"

namespace ast
{
namespace expression
{

class IdentifierNode : public node::Node 
{
public:
  IdentifierNode() {}

  IdentifierNode(token::Token token)
    : Node(std::move(token)) {}
};

/* There are 2 types of identifier: one that produces value and one that does not
 * 
 * For example, "let x = y;".
 * In this statement, "x" does not produce any value, whereas "y" does.
 */
class NonValueIdentifierNode : public IdentifierNode
{
public:
  NonValueIdentifierNode() {}

  NonValueIdentifierNode(token::Token token)
    : IdentifierNode{std::move(token)} {}

protected:
  bool _equals(const Node& other) const;
};

class ValueIdentifierNode : public IdentifierNode
{
private:
  std::string _value;
};

} //namespace expression
} //namespace ast

#endif
