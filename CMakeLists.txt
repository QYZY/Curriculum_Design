cmake_minimum_required(VERSION 3.25)
project(Curriculum_Design)

set(CMAKE_CXX_STANDARD 11)

add_executable(Curriculum_Design main.cpp menu.h function.cpp config.h user_function.cpp admin_function.cpp commodity_function.cpp)
