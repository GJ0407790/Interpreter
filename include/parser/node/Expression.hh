#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#include "Node.hh"

namespace ast
{
namespace expression
{

class Identifier : public node::Node
{
public:
  Identifier() {}

  Identifier(token::Token token)
    : Node(std::move(token)) {}
  
  const std::string toString() const override;
};

class Expression : public node::Node 
{
public:
  Expression() {}

  Expression(token::Token token)
    : Node(std::move(token)) {}

  const std::string toString() const override;

protected:
  bool _equals(const Node& other) const;

private:
  std::string _value; // The value it produces
};



} //namespace expression
} //namespace ast

#endif
