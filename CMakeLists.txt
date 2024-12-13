cmake_minimum_required(VERSION 3.25)
project(ProjectsJS24)
include_directories(Include)
file(GLOB SOURCE "/*.cpp")

add_subdirectory(external/googletest)

add_executable(ProjectsJS24 main.cpp stud.cpp)

add_executable(ProjectsJS24Tests test.cpp stud.cpp)

target_link_libraries(ProjectsJS24Tests gtest gtest_main)

enable_testing()

add_test(NAME ProjectsJS24Tests COMMAND ProjectsJS24Tests)