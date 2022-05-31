//
// Created by arels on 31/05/2022.
//

#include "snake.h"
#include <stdio.h>
#include <malloc.h>


SnakeNode* addNodeTail(Snake* s,int posX,int posY){
    SnakeNode* node = malloc(sizeof (SnakeNode));
    node->next = NULL;
    node->prev = NULL;
    node->posX = posX;
    node->posY = posY;

    s->tail->prev = node;
    node->next = s->tail;
    s->tail = node;

}