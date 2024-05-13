#include <gtest/gtest.h>

#include "../../include/lexer/Lexer.hh"

using namespace token;
using namespace lexer;

bool compareTokens(std::vector<Token>& expected_tokens, std::string& input)
{
  auto lexer = Lexer{input};

  for (const auto& token : expected_tokens) 
  {
    auto parsed_token = lexer.nextToken();

    if (token != parsed_token)
    {
      return false;
    }
  }

  return true;
}

TEST(LexerTest, BasicSingleCharacter) {
  std::string basic_single_char_str = "=+(){},;";

  std::vector<Token> expected_token = {
    Token{TokenType::ASSIGN, "="},
    Token{TokenType::PLUS, "+"},
    Token{TokenType::LPAREN, "("},
    Token{TokenType::RPAREN, ")"},
    Token{TokenType::LBRACE, "{"},
    Token{TokenType::RBRACE, "}"},
    Token{TokenType::COMMA, ","},
    Token{TokenType::SEMICOLON, ";"}
  };

  auto lexer = lexer::Lexer{basic_single_char_str};

  EXPECT_TRUE(compareTokens(expected_token, basic_single_char_str));
}
