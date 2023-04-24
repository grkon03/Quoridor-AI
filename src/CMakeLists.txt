cmake_minimum_required(VERSION 3.21)

project(QuoridorAI)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(includes)

add_executable(QuoridorAI main.cpp)

target_link_libraries(QuoridorAI QuoridorAIIncludes)