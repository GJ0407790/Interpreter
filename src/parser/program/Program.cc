#include "../../../include/parser/program/Program.hh"

namespace ast
{
namespace program
{

void Program::addStatement(StatementPtr statement)
{
  _statements.push_back(std::move(statement));
}

const std::string Program::toString() const
{
  std::ostringstream os;

  for (const auto& statement : _statements)
  {
    os << statement->toString() << "\n";
  }

  return os.str();
}

} //namespace program
} //namespace ast