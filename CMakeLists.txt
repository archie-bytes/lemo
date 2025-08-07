cmake_minimum_required(VERSION 3.15)

project(lemo)

set(CMAKE_CXX_STANDARD 20)

# 查找 SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(lemo src/main.cpp
        src/actors/hero/hero.cpp
        src/actors/hero/hero.h
        src/actors/enemy/index.txt
        src/base/level/level.cpp
        src/base/level/level.h
        src/base/game/game.cpp
        src/base/game/game.h)

target_link_libraries(lemo sfml-graphics sfml-window sfml-system)