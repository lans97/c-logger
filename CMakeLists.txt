cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 23)

project(
    logger
    VERSION 1.0
    LANGUAGES C)

file(GLOB_RECURSE sources src/*.c src/*.h)

add_executable(main ${sources})

target_compile_features(main PRIVATE c_std_23)

target_include_directories(main PUBLIC src)
