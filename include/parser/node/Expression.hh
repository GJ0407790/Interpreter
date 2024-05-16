#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#include "Node.hh"

namespace ast
{
namespace expression
{

class IdentifierNode : public node::Node 
{

};

/* There are 2 types of identifier: one that produces value and one that does not
 * 
 * For example, "let x = y;".
 * In this statement, "x" does not produce any value, whereas "y" does.
 */
class NonValueIdentifierNode : public IdentifierNode
{
public:
  const std::string& tokenLiteral() const override; 
};

class ValueIdentifierNode : public IdentifierNode
{
public:
  const std::string& tokenLiteral() const override; 

private:
  std::string _value;
};

} //namespace expression
} //namespace ast

#endif
