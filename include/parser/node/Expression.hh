#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#include "Node.hh"

namespace ast
{
namespace expression
{

class Expression : public node::Node 
{
public:
  Expression() {}

  Expression(token::Token token)
    : Node(std::move(token)) {}

  const std::string toString() const override;
};

class Identifier : public Expression
{
public:
  Identifier() {}

  Identifier(token::Token token, std::string val)
    : Expression(std::move(token)), _value{std::move(val)} {}
  
  const std::string toString() const override;

private:
  std::string _value; // The value it produces
};

} //namespace expression
} //namespace ast

#endif
