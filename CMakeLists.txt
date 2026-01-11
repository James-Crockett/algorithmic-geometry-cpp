# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# cmake_minimum_required(VERSION 3.20)
# project(algorithmic_geometry_cpp LANGUAGES C CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # --- 1. GLFW (The Windowing Library) ---
# include(FetchContent)
# FetchContent_Declare(
#   glfw
#   GIT_REPOSITORY https://github.com/glfw/glfw.git
#   GIT_TAG 3.3.9
# )
# # This replaces the complex "Populate" block and fixes the missing headers
# FetchContent_MakeAvailable(glfw)

# # --- 2. GLAD (The OpenGL Loader) ---
# # We use CMAKE_CURRENT_SOURCE_DIR to ensure the path is always correct
# add_library(glad STATIC
#   "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/src/glad.c"
# )
# target_include_directories(glad PUBLIC
#   "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad/include"
# )

# # --- 3. The Executable ---
# add_executable(basic_shapes
#   basic-shapes/shapes.cpp
# )

# # Link both. GLFW automatically adds its own include paths now.
# target_link_libraries(basic_shapes PRIVATE glad glfw)

cmake_minimum_required(VERSION 3.20)
project(algorithmic_geometry_cpp C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Helps IntelliSense match the real build
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- GLAD (local) ----
add_library(glad STATIC
  ${CMAKE_SOURCE_DIR}/dependencies/glad/src/glad.c
)
target_include_directories(glad PUBLIC
  ${CMAKE_SOURCE_DIR}/dependencies/glad/include
)

# ---- GLFW (local source) ----
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/dependencies/glfw)

# ---- Your app ----
add_executable(basic_shapes basic-shapes/shapes.cpp)
target_link_libraries(basic_shapes PRIVATE glad glfw)

# Windows often needs this explicitly
if (WIN32)
  target_link_libraries(basic_shapes PRIVATE opengl32)
endif()
