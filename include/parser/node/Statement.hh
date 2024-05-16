#ifndef STATEMENT_HH
#define STATEMENT_HH

#include "Expression.hh"

namespace ast
{
namespace statement
{

class StatementNode : public node::Node 
{

};

class LetStatement : public StatementNode
{
private:
  expression::NonValueIdentifierNode _name;
};

} //namespace statement
} //namespace ast

#endif // STATEMENT_HH