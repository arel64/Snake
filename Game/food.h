//
// Created by arels on 01/06/2022.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H


#include <stdlib.h>
#include <time.h>


struct food{
    short posX;
    short posY;
    short scoreVal;
}typedef Food;

void initFood(Food*);
void repostion(Food*);
#endif //SNAKE_FOOD_H
