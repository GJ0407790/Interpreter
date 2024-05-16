#ifndef NODE_HH
#define NODE_HH

#include <string>

#include "../../lexer/Token.hh"

namespace ast
{
namespace node 
{

class Node 
{
public:
  // For debugging and testing purpose: print out the literal value
  virtual const std::string& tokenLiteral() const = 0; 

private:
  token::Token _token;
};


} //namespace node
} //namespace ast

#endif // NODE_HH
