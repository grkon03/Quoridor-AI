cmake_minimum_required(VERSION 3.14)
project(QuoridorAITest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

# avoid warning
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(../src/includes)

file(GLOB Includes 
../src/includes/*.cpp
../src/includes/indexer/*.cpp
../src/includes/hasher/*.cpp)

file(GLOB TestTargets 
*.cpp 
indexer/*.cpp)

add_executable(
  QuoridorAITest
  ${TestTargets}
  ${Includes}
)
target_link_libraries(
  QuoridorAITest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(QuoridorAITest)