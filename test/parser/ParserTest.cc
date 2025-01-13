#include <gtest/gtest.h>
#include <iostream>

#include "../../include/parser/Parser.hh"

using namespace ast;
using namespace lexer;
using namespace token;

testing::AssertionResult checkAnyErrors(parser::Parser& parser)
{
  if (parser.getErrors().size() > 0)
  {
    for (const auto& error : parser.getErrors())
    {
      std::cerr << "[ERROR]: " << error << "\n";
    }
  }

  return testing::AssertionSuccess();
}

testing::AssertionResult compareStatements(std::vector<std::string>& expected_statements_str, std::string& input)
{
  auto parser = parser::Parser{input};
  auto program = parser.parseProgram();

  if (checkAnyErrors(parser) == testing::AssertionFailure())
  {
    return testing::AssertionFailure() << "Parser encountered an error!\n";
  }

  size_t idx = 0;

  for (const auto& statement_str : expected_statements_str) 
  {
    if (program._statements.size() <= idx)
    {
      return testing::AssertionFailure() << "Program has insufficient statements!\n"; 
    }

    if (statement_str != program._statements[idx]->toString())
    {
      return testing::AssertionFailure() << "Expected: " << statement_str << ", got: " << program._statements[idx]->toString(); 
    }

    idx++;
  }

  return testing::AssertionSuccess();
}

TEST(ParserTest, BasicLetStatement) 
{
  std::string let_statements_str = " \
    let x = 5;                     \
    let y = 10;                     \
    let foobar = 838383;";

  std::vector<std::string> expected_statements = {
    "let x = ;",
    "let y = ;",
    "let foobar = ;"
  };

  EXPECT_TRUE(compareStatements(expected_statements, let_statements_str));
}

