cmake_minimum_required(VERSION 3.14)
project(lexer_test)

set(PROJECT_BINARY_DIR build/bin)
set(PROJECT_INCLUDE_DIR ../../include)
set(PROJECT_SOURCE_DIR ../)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_INCLUDE_DIR}/lexer")

add_executable(
  LexerMain
  LexerMain.cc
  "${PROJECT_SOURCE_DIR}/lexer/Lexer.cc"
  "${PROJECT_SOURCE_DIR}/lexer/Token.cc"
)

