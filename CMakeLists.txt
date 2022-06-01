cmake_minimum_required(VERSION 3.22)
project(Snake C)

set(CMAKE_C_STANDARD 11)

add_executable(Snake main.c Game/board.c Game/board.h Game/game.c Game/game.h Game/snake.c Game/snake.h Game/node.c Game/node.h Timing/KeyListener.c Timing/KeyListener.h Game/food.c Game/food.h)
