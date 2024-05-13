#include "../../include/lexer/Token.hh"

namespace token 
{

bool Token::operator==(const Token& rhs) const
{
  return _type == rhs._type && _literal == rhs._literal;
}

bool Token::operator!=(const Token& rhs) const
{
  return _type != rhs._type || _literal != rhs._literal;
}

} //namespace token