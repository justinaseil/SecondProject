cmake_minimum_required(VERSION 3.25)
project(FirstProject1)
include_directories(Include)
file(GLOB SOURCE "*.cpp")
add_executable(FirstProject1 main.cpp stud.cpp)




