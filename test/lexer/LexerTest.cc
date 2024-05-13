#include <gtest/gtest.h>
#include <iostream>

#include "../../include/lexer/Lexer.hh"

using namespace token;
using namespace lexer;

testing::AssertionResult compareTokens(std::vector<Token>& expected_tokens, std::string& input)
{
  auto lexer = Lexer{input};

  for (const auto& token : expected_tokens) 
  {
    auto parsed_token = lexer.nextToken();

    if (token != parsed_token)
    {
      return testing::AssertionFailure() << "Expected: " << token << ", got: " << parsed_token << "\n"; 
    }
  }

  return testing::AssertionSuccess();
}

TEST(LexerTest, BasicSingleCharacter) 
{
  std::string basic_single_char_str = "=+(){},;";

  std::vector<Token> expected_tokens = {
    {TokenType::ASSIGN, "="},
    {TokenType::PLUS, "+"},
    {TokenType::LPAREN, "("},
    {TokenType::RPAREN, ")"},
    {TokenType::LBRACE, "{"},
    {TokenType::RBRACE, "}"},
    {TokenType::COMMA, ","},
    {TokenType::SEMICOLON, ";"},
    {TokenType::ENDOFFILE, ""}
  };

  EXPECT_TRUE(compareTokens(expected_tokens, basic_single_char_str));
}

TEST(LexerTest, SimpleSrcCode)
{
  std::string simple_src_code_str = " \
    let five = 5;                     \
    let ten = 10;                     \
    let add = fn(x, y) {              \
                x + y;                \
              };                      \
    let result = add(five, ten);";

  std::vector<Token> expected_tokens = {
      {TokenType::LET, "let"},
      {TokenType::IDENT, "five"},
      {TokenType::ASSIGN, "="},
      {TokenType::INT, "5"},
      {TokenType::SEMICOLON, ";"},
      {TokenType::LET, "let"},
      {TokenType::IDENT, "ten"},
      {TokenType::ASSIGN, "="},
      {TokenType::INT, "10"},
      {TokenType::SEMICOLON, ";"},
      {TokenType::LET, "let"},
      {TokenType::IDENT, "add"},
      {TokenType::ASSIGN, "="},
      {TokenType::FUNCTION, "fn"},
      {TokenType::LPAREN, "("},
      {TokenType::IDENT, "x"},
      {TokenType::COMMA, ","},
      {TokenType::IDENT, "y"},
      {TokenType::RPAREN, ")"},
      {TokenType::LBRACE, "{"},
      {TokenType::IDENT, "x"},
      {TokenType::PLUS, "+"},
      {TokenType::IDENT, "y"},
      {TokenType::SEMICOLON, ";"},
      {TokenType::RBRACE, "}"},
      {TokenType::SEMICOLON, ";"},
      {TokenType::LET, "let"},
      {TokenType::IDENT, "result"},
      {TokenType::ASSIGN, "="},
      {TokenType::IDENT, "add"},
      {TokenType::LPAREN, "("},
      {TokenType::IDENT, "five"},
      {TokenType::COMMA, ","},
      {TokenType::IDENT, "ten"},
      {TokenType::RPAREN, ")"},
      {TokenType::SEMICOLON, ";"},
      {TokenType::ENDOFFILE, ""}
    };

  EXPECT_TRUE(compareTokens(expected_tokens, simple_src_code_str));
}
