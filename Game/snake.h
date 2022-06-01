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
SnakeNode* addNodeTail(Snake*,int,int);
int isSnakeIntercepts(Snake*,short,short);
int isSnakeBodyIntercepts(Snake*,short,short);
#endif //SNAKE_SNAKE_H
