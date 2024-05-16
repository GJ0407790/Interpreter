#ifndef PROGRAM_HH
#define PROGRAM_HH

#include <memory>
#include <vector>

#include "../node/Statement.hh"

namespace ast
{

using StatementPtr = std::shared_ptr<statement::StatementNode>;

namespace program
{

class Program
{
public:
  void addStatement(StatementPtr statement);

private:
  std::vector<StatementPtr> _statements;
};

} //namesapce program
} //namespace ast

#endif //PROGRAM_HH
