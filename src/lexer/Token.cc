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

std::ostream& operator<<(std::ostream &out, const Token& token) 
{
  out << "(" << TokenTypeToString.at(token.getTokenType()) << ", " << token.getLiteral() << ")";

  return out;
}

} //namespace token