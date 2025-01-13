#ifndef STATEMENT_HH
#define STATEMENT_HH

#include <memory>

#include "Expression.hh"

namespace ast
{
namespace statement
{

using ExpressionPtr = std::unique_ptr<expression::Expression>;
using IdentifierPtr = std::unique_ptr<expression::Identifier>;

class StatementNode : public node::Node 
{
public:
  StatementNode(token::Token token)
    : Node(std::move(token)) {}
};

/* A typical let statement:
 * 
 * let x = y + 1 * z;
 */
class LetStatement : public StatementNode
{
public:
  LetStatement(token::Token token)
    : StatementNode(std::move(token)), _name{}, _value{} {}

  // Construct _name from a given token. Assume that the token is correct
  void setName(token::Token token);

  const std::string toString() const override;
  
private:
  ExpressionPtr _name;
  IdentifierPtr _value;
};

/* Typical return statement:
 * 
 * return y + 1 * z;
 */
class ReturnStatement : public StatementNode
{
public:
  ReturnStatement(token::Token token)
    : StatementNode(std::move(token)) {}

  const std::string toString() const override;
  
private:
  ExpressionPtr _return_value;
};


/* An expression statement is a line that consist only of expression, e.g.
 *  - x + 1;
 *  - f(y + g(z));
 */
class ExpressionStatement : public StatementNode
{
public:
  ExpressionStatement(token::Token token)
    : StatementNode(std::move(token)) {}
  
  const std::string toString() const override;

private:
  ExpressionPtr _expression;
};

} //namespace statement
} //namespace ast

#endif // STATEMENT_HH