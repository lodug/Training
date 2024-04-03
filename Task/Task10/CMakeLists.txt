#minimum required version of cmake to build the project
cmake_minimum_required(VERSION 3.15)

project(MyProject CXX)

#source files and executable
add_executable(executable src/main.cpp src/automobil.cpp src/masina1.cpp src/masina2.cpp)

# include directories
include_directories(include)







