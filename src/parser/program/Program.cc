#include "../../../include/parser/program/Program.hh"

namespace ast
{
namespace program
{

void Program::addStatement(StatementPtr statement)
{
  _statements.push_back(std::move(statement));
}

} //namespace program
} //namespace ast