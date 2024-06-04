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

class LetStatement : public StatementNode
{
public:
  LetStatement(token::Token token)
    : StatementNode(std::move(token)) {}
  
  LetStatement(token::Token token, token::Token name)
    : StatementNode(std::move(token)), _name(std::move(name)) {}

  // Construct _name from a given token. Assume that the token is correct
  void setName(token::Token token);

  virtual void printInfo(std::ostream &out) const override;

protected:
  bool _equals(const Node& other) const;
  
private:
  expression::NonValueIdentifierNode _name;
};

} //namespace statement
} //namespace ast

#endif // STATEMENT_HH