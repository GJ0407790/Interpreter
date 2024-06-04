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
  Node() = default;

  Node(token::Token token) 
    : _token{std::move(token)} {}

  // For debugging and testing purpose: print out the literal value
  virtual const std::string& tokenLiteral() const; 

  virtual void printInfo(std::ostream &out) const;

  bool operator==(const Node& other) const {
    return this->_equals(other);
  };

  bool operator!=(const Node& other) const {
    return !(*this == other);
  }

   // For debugging purpose
  friend std::ostream& operator<<(std::ostream &out, const Node& token);

protected:
  // derived class will override this function to change the equality check
  virtual bool _equals(const Node& other) const;

private:
  token::Token _token;
};


} //namespace node
} //namespace ast

#endif // NODE_HH
