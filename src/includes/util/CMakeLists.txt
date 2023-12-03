cmake_minimum_required(VERSION 3.21)

project(QuoridorAI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB UAITargets *.cpp)

add_library(QuoridorAIUtilIncludes ${UAITargets})