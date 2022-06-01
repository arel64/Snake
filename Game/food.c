//
// Created by arels on 01/06/2022.
//

#include "food.h"
#include "board.h"

void initFood(Food* d){
    srand(time(NULL));
    d->scoreVal = 10;
    repostion(d);
}
void repostion(Food* d){
    d->posX = rand()%(BOARD_SIZE-3)+2;
    d->posY = rand()%(BOARD_SIZE-3)+2;
}
