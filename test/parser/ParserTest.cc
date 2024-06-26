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

testing::AssertionResult compareStatements(std::vector<StatementPtr>& expected_statements, std::string& input)
{
  auto parser = parser::Parser{input};
  auto program = parser.parseProgram();

  if (checkAnyErrors(parser) == testing::AssertionFailure())
  {
    return testing::AssertionFailure() << "Parser encountered an error!\n";
  }

  size_t idx = 0;

  for (const auto& statement : expected_statements) 
  {
    if (program._statements.size() <= idx)
    {
      return testing::AssertionFailure() << "Program has insufficient statements!\n"; 
    }

    if (*statement != *(program._statements[idx]))
    {
      return testing::AssertionFailure() << "Expected: " << *statement << ", got: " << *(program._statements[idx]) << "\n"; 
    }

    idx++;
  }

  return testing::AssertionSuccess();
}

// TEST(ParserTest, BasicLetStatement) 
// {
//   std::string let_statements_str = " \
//     let x = 5;                     \
//     let y = 10;                     \
//     let foobar = 838383;";

//   std::vector<StatementPtr> expected_statements = {
//     std::make_shared<statement::LetStatement>(Token{TokenType::LET, "let"}, Token{TokenType::IDENT, "x"}),
//     std::make_shared<statement::LetStatement>(Token{TokenType::LET, "let"}, Token{TokenType::IDENT, "y"}),
//     std::make_shared<statement::LetStatement>(Token{TokenType::LET, "let"}, Token{TokenType::IDENT, "foobar"})
//   };

//   EXPECT_TRUE(compareStatements(expected_statements, let_statements_str));
// }

TEST(ParserTest, BasicLetStatementParseFail) 
{
  std::string let_statements_str = " \
    let 5;";

  std::vector<StatementPtr> expected_statements = {
    std::make_shared<statement::LetStatement>(Token{TokenType::LET, "let"}, Token{TokenType::IDENT, "x"}),
  };

  EXPECT_FALSE(compareStatements(expected_statements, let_statements_str));
}
