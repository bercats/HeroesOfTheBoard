cmake_minimum_required(VERSION 3.25)
project(HeroesOfTheBoard)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HeroesOfTheBoard
        Board.cpp
        Board.h
        LICENSE
        README.md main.cpp Piece.h Piece.cpp Melee.h Melee.cpp Ranged.h Ranged.cpp Bowman.h Bowman.cpp Elf.h Elf.cpp Mage.h Mage.cpp Swordsman.h Swordsman.cpp Spearman.h Spearman.cpp Ranger.h Ranger.cpp Knight.h Knight.cpp Game.h Game.cpp)
