cmake_minimum_required(VERSION 3.0)

project(example C CXX)

# Find source files
file(GLOB SOURCES *.cpp)

# Include header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create shared library
add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCES})

# Install library
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION /tmp/lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION /tmp/include/${CMAKE_PROJECT_NAME})
