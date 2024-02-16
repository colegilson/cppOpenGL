cmake_minimum_required(VERSION 3.0.0)
project(my_proj VERSION 0.1.0)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(my_proj src/play.cpp 
src/glew.h 
src/glew.c
)

target_link_libraries(my_proj glfw OpenGL::GL)