//
// Created by arels on 31/05/2022.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "board.h"
#include "snake.h"
#include <time.h>
#include <stdlib.h>
#include "malloc.h"
#include <stdio.h>


typedef struct{
    unsigned score;
    unsigned speed;
    Snake snake;
    Board *board;
}Game;
int initGame(Game*);
int isRunning();
void redraw(Game*);
int update(Game*,char);
void printBoard(Game*);
void modConsolePos(int,int,char);
#endif //SNAKE_GAME_H
