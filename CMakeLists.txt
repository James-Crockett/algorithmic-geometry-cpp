cmake_minimum_required(VERSION 3.20)
project(algorithmic_geometry_cpp C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- GLAD ----
add_library(glad STATIC
  ${CMAKE_SOURCE_DIR}/dependencies/glad/src/glad.c
)
target_include_directories(glad PUBLIC
  ${CMAKE_SOURCE_DIR}/dependencies/glad/include
)

# ---- GLFW ----
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/dependencies/glfw)

add_executable(basic_shapes basic-shapes/shapes.cpp)
target_link_libraries(basic_shapes PRIVATE glad glfw)

if (WIN32)
  target_link_libraries(basic_shapes PRIVATE opengl32)
endif()
