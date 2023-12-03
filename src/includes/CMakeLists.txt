cmake_minimum_required(VERSION 3.21)

project(QuoridorAI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB QAIITargets *.cpp)

add_subdirectory(indexer)
add_subdirectory(hasher)
add_subdirectory(dijkstra)
add_subdirectory(util)

add_library(QuoridorAIIncludes ${QAIITargets})

target_link_libraries(QuoridorAIIncludes QuoridorAIIndexerIncludes)
target_link_libraries(QuoridorAIIncludes QuoridorAIHasherIncludes)
target_link_libraries(QuoridorAIIncludes QuoridorAIDijkstraIncludes)
target_link_libraries(QuoridorAIIncludes QuoridorAIUtilIncludes)