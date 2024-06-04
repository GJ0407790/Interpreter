cmake_minimum_required(VERSION 3.14)
project(parser_test)

set(PROJECT_BINARY_DIR build/bin)
set(PROJECT_INCLUDE_DIR ../../include)
set(PROJECT_SOURCE_DIR ../../src)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug) # This is essential to trigger debugger

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories("${PROJECT_INCLUDE_DIR}/parser")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-sign-compare -Wno-ignored-attributes")

add_executable(
  ParserTest
  ParserTest.cc
  "${PROJECT_SOURCE_DIR}/parser/program/Program.cc"
  "${PROJECT_SOURCE_DIR}/parser/Parser.cc"
  "${PROJECT_SOURCE_DIR}/parser/node/Node.cc"
  "${PROJECT_SOURCE_DIR}/parser/node/Expression.cc"
  "${PROJECT_SOURCE_DIR}/parser/node/Statement.cc"
  "${PROJECT_SOURCE_DIR}/parser/node/Statement.cc"
  "${PROJECT_SOURCE_DIR}/lexer/Lexer.cc"
  "${PROJECT_SOURCE_DIR}/lexer/Token.cc"
)

target_link_libraries(
  ParserTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ParserTest)

