cmake_minimum_required(VERSION 3.13)

project(QuoridorAI)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(includes)

add_executable(QurodidorAI main.cpp)

target_link_libraries(QurodidorAI QuoridorAIIncludes)