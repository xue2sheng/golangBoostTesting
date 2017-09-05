cmake_minimum_required(VERSION 3.0)

project(example C CXX)

add_subdirectory(src)

# include(CTest)
enable_testing()
add_subdirectory("test")
