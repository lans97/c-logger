cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 23)

project(
    logger
    VERSION 1.0
    LANGUAGES C)

add_library(logger INTERFACE)
target_include_directories(logger INTERFACE src/include)

# add_executable(sample ${sources})
# target_link_libraries(samlpe PUBLIC logger)
# target_include_directories()
# target_compile_features(main PRIVATE c_std_23)
