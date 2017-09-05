# Find source files
file(GLOB SOURCES *.cpp)

# Include header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)

# binary
add_executable(exampleTest ${SOURCES})
add_dependencies(exampleTest ${CMAKE_PROJECT_NAME})
target_link_libraries(exampleTest ${CMAKE_PROJECT_NAME})

# List of tests
add_test(exampleTest exampleTest)
