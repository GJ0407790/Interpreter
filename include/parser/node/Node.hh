#ifndef NODE_HH
#define NODE_HH

#include <string>

namespace node 
{

class Node 
{
public:
  // For debugging and testing purpose: print out the literal value
  const std::string& tokenLiteral() const; 
};

} //namespace node

#endif
