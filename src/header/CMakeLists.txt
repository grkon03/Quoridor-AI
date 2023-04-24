cmake_minimum_required(VERSION 3.13)

project(QuoridorAI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB, QAIITargets, *.cpp)

add_library(QuoridorAIIncludes ${QAIITargets})