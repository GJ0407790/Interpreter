#include "../../include/lexer/Lexer.hh"

using namespace lexer;
using namespace token;

// REPL version of lexer
// takes in input and outputs the list of tokens
int main()
{
	std::cout << "Hi there! This is the Monkey programming language!\n" 
						<< "Feel free to type in commands!\n"
						<< ">>> ";
	
	std::string input;
  std::getline(std::cin, input);

  Lexer lexer{input};

  auto token = lexer.nextToken();

  while (token.getTokenType() != TokenType::ENDOFFILE)
  {
    std::cout << token << "\n";

    token = lexer.nextToken();
  }

	return 0;
}

