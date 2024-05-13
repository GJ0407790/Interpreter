cmake_minimum_required(VERSION 3.14)
project(lexer_test)

set(PROJECT_BINARY_DIR build/bin)
set(PROJECT_INCLUDE_DIR ../../include)
set(PROJECT_SOURCE_DIR ../../src)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories("${PROJECT_INCLUDE_DIR}/lexer")


add_executable(
  LexerTest
  LexerTest.cc
  "${PROJECT_SOURCE_DIR}/lexer/Lexer.cc"
  "${PROJECT_SOURCE_DIR}/lexer/Token.cc"
)

target_link_libraries(
  LexerTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(LexerTest)

