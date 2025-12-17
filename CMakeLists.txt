cmake_minimum_required(VERSION 3.16)

project(TowerDefense LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

file (GLOB_RECURSE SOURCES
     src/*.cpp
)

add_executable(TowerDefense ${SOURCES})