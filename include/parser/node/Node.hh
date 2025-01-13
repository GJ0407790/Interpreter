#ifndef NODE_HH
#define NODE_HH

#include <string>
#include <sstream>

#include "../../lexer/Token.hh"

namespace ast
{
namespace node 
{

class Node 
{
public:
  Node() = default;

  Node(token::Token token) 
    : _token{std::move(token)} {}

  // For debugging and testing purpose: print out the literal value
  virtual const std::string& tokenLiteral() const; 
  // Print out the AST node value to compare with other AST nodes
  virtual const std::string toString() const = 0;

   // For debugging purpose
  friend std::ostream& operator<<(std::ostream &out, const Node& token);

private:
  token::Token _token;
};


} //namespace node
} //namespace ast

#endif // NODE_HH
