//
// Created by arels on 31/05/2022.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "node.h"
typedef struct snake{
    SnakeNode* head;
    SnakeNode* tail;

}Snake;
SnakeNode * insert(Snake*,SnakeNode*);
void advanceDirection(int);
int getNextDirection();
int isBound();
SnakeNode* addNodeTail(Snake* s,int,int);
#endif //SNAKE_SNAKE_H
