cmake_minimum_required(VERSION 3.14) # Upgraded to 3.14 to allow auto-downloading
project(algorithmic-geometry-cpp VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

add_executable(basic_shapes basic-shapes/shapes.cpp src/glad.c)

target_include_directories(basic_shapes PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(basic_shapes PRIVATE glfw)

