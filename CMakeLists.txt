cmake_minimum_required(VERSION 3.6)
project(CppProjects)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .gitignore
        README.md)

add_subdirectory(learning&practice)
add_executable(CppProjects ${SOURCE_FILES})