cmake_minimum_required(VERSION 3.16)
project(cps_utility_console VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/validators.cpp
)

# Include directories
include_directories(include)

# Executable
add_executable(cps_utility_console ${SOURCES})

# Install target
install(TARGETS cps_utility_console DESTINATION bin)