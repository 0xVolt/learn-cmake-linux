# Set required minimum version
cmake_minimum_required(VERSION 3.0.0)

# Set project name
project(main VERSION 0.1.0)

# Enable testing should we need it
include(CTest)
enable_testing()

# The next following functions are quintessential for this kind of design of CMake project

# Use this to add sub-directories for storing the headers and source files separately
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/source
)

# Make sure CMake can find all those files that are .h in /include/ and .cpp in /src/
file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/source/*.cpp"
)

# Linking those files found and adding them to the main.cpp executable
add_executable(${PROJECT_NAME} ${all_SRCS} main.cpp)

# Creating a CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
