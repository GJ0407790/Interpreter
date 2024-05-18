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
  Node(token::Token token) 
    : _token{std::move(token)} {}

  // For debugging and testing purpose: print out the literal value
  virtual const std::string& tokenLiteral() const; 

  bool operator==(const Node& other) const {
    return this->_equals(other);
  };

  bool operator!=(const Node& other) const {
    return !(*this == other);
  }

protected:
  // derived class will override this function to change the equality check
  virtual bool _equals(const Node& other) const;

private:
  token::Token _token;
};


} //namespace node
} //namespace ast

#endif // NODE_HH
