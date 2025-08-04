cmake_minimum_required(VERSION 3.15)

project(sfml01)

set(CMAKE_CXX_STANDARD 20)

# 查找 SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(sfml01 src/main.cpp
        src/actors/hero/hero.cpp
        src/actors/hero/hero.h
        src/actors/enemy/index.txt)

target_link_libraries(sfml01 sfml-graphics sfml-window sfml-system)