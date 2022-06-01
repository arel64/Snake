//
// Created by arels on 31/05/2022.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "board.h"
#include "snake.h"
#include "food.h"
#include <time.h>
#include <malloc.h>
#include <stdio.h>


typedef struct{
    unsigned score;
    unsigned speed;
    Snake snake;
    Food food;
    Board *board;
}Game;
int initGame(Game*);
int isRunning();
void redraw(Game*);
int update(Game*,char);
void printBoard(Game*);
void modConsolePos(short,short,char);
void destroyGame(Game*);
#endif //SNAKE_GAME_H
