#ifndef STATEMENT_HH
#define STATEMENT_HH

#include "Expression.hh"

namespace ast
{
namespace statement
{

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
    : StatementNode(std::move(token)) {}
  
  LetStatement(token::Token token, token::Token name)
    : StatementNode(std::move(token)), _name(std::move(name)) {}

  // Construct _name from a given token. Assume that the token is correct
  void setName(token::Token token);

  const std::string toString() const override;

protected:
  bool _equals(const Node& other) const;
  
private:
  expression::Identifier _name;
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
  expression::Expression _expression;
};

} //namespace statement
} //namespace ast

#endif // STATEMENT_HH