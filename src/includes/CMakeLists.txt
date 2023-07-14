cmake_minimum_required(VERSION 3.21)

project(QuoridorAI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB QAIITargets *.cpp)

add_subdirectory(indexer)

add_library(QuoridorAIIncludes ${QAIITargets})

target_link_libraries(QuoridorAIIncludes QuoridorAIIndexerIncludes)