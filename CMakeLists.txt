# Minimum version of CMake required
cmake_minimum_required(VERSION 3.31)

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project name
project(GrzeLib C)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR}/headers)

add_library(GrzeLib STATIC
src/string.c
)
