cmake_minimum_required(VERSION 3.6)
project(HelloWorld_proj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        )
add_executable(HelloWorld_proj ${SOURCE_FILES})