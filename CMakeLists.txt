cmake_minimum_required(VERSION 3.23)
project(poc_mario_physics)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR ./libs/SDL/include)
set(SDL2_LIB_DIR ./libs/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(poc_mario_physics main.cpp)

target_link_libraries(poc_mario_physics SDL2main SDL2)

target_link_libraries(poc_mario_physics -static)