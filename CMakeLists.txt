cmake_minimum_required(VERSION 3.21)
project(projet_programmation_s5)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_programmation_s5 main.cpp Sources/Mobile/Mobile.cpp Headers/Mobile/Mobile.h Sources/Field/Field.cpp Headers/Field/Field.h Sources/Mobile/Player.cpp Headers/Mobile/Player.h Sources/Mobile/Fawn.cpp Headers/Mobile/Fawn.h Sources/Mobile/Lion.cpp Headers/Mobile/Lion.h Sources/Mobile/Tiger.cpp Headers/Mobile/Tiger.h Sources/Field/Trap.cpp Headers/Field/Trap.h Sources/Field/Obstacle.cpp Headers/Field/Obstacle.h Sources/Field/BasicTrap.cpp Headers/Field/BasicTrap.h Sources/Board/Board.cpp Headers/Board/Board.h Sources/Empty.cpp Headers/Empty.h Sources/Empty.cpp Headers/Empty.h)
