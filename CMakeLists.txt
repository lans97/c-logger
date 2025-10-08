cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 23)

project(
    logger
    VERSION 1.0
    LANGUAGES C)

add_library(logger INTERFACE include/logger.h)
target_include_directories(logger INTERFACE include/)

# Expose include directory (for FetchContent)
target_include_directories(logger INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

option(BUILD_EXAMPLES "Build the examples" OFF)

if(BUILD_EXAMPLES)
    add_executable(example example/example.c)
    target_link_libraries(example PRIVATE logger)
endif()

