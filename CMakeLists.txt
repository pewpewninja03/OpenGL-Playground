cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(MyOpenGL LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Threads REQUIRED)

add_executable(test src/test.cpp src/glad.c)

target_link_libraries(test glfw OpenGL::GL Threads::Threads dl)
