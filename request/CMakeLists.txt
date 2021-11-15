cmake_minimum_required(VERSION 3.20)
project(request)

set(CMAKE_CXX_STANDARD 98)

add_executable(request main.cpp Request.cpp Request.hpp)
