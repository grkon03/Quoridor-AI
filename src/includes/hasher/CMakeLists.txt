cmake_minimum_required(VERSION 3.21)

project(QuoridorAI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB HAITargets *.cpp)

add_library(QuoridorAIHasherIncludes ${HAITargets})