//
// Created by arels on 31/05/2022.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include "windows.h"
#include "snake.h"
#define BOARD_SIZE 40

typedef char Board [][BOARD_SIZE];


void clearBoard(Board b);
void addSnake(Board, Snake*);

#endif //SNAKE_BOARD_H
