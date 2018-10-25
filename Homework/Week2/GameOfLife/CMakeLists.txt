cmake_minimum_required(VERSION 3.12)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameOfLife)

add_executable(GameOfLife
        GameOfLife/Beehive.cpp
        GameOfLife/Beehive.h
        GameOfLife/Blink.cpp
        GameOfLife/Blink.h
        GameOfLife/Block.cpp
        GameOfLife/Block.h
        GameOfLife/CustomRules.cpp
        GameOfLife/CustomRules.h
        GameOfLife/GameOfLife.cpp
        GameOfLife/GameRules.cpp
        GameOfLife/GameRules.h
        GameOfLife/Glider.cpp
        GameOfLife/Glider.h
        GameOfLife/GosperGliderGun.cpp
        GameOfLife/GosperGliderGun.h
        GameOfLife/Loaf.cpp
        GameOfLife/Loaf.h
        GameOfLife/MatrixDrawer.cpp
        GameOfLife/MatrixDrawer.h
        GameOfLife/OriginalRules.cpp
        GameOfLife/OriginalRules.h
        GameOfLife/RandomRules.cpp
        GameOfLife/RandomRules.h
        GameOfLife/Toad.cpp
        GameOfLife/Toad.h)
