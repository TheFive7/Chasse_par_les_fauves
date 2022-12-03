cmake_minimum_required(VERSION 3.21)
project(projet_programmation_s5)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_programmation_s5 GameManager.h GameManager.cpp Player.cpp Player.h Level.cpp Level.h Enemy.cpp Enemy.h main.cpp)
