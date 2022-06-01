//
// Created by arels on 31/05/2022.
//

#include "snake.h"
#include <stdio.h>
#include <malloc.h>
#define isEquals(x1,y1,x2,y2) ((x1==x2)&&(y1==y2))?1:0

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
int isSnakeIntercepts(Snake*s ,short posX, short posY){
    SnakeNode* iter = s->head;
    if((iter->posX == posX)&&(iter->posY == posY)) {
        return 1;
    }
    return isSnakeBodyIntercepts(s,posX,posY);
}
int isSnakeBodyIntercepts(Snake*s ,short posX, short posY){
    SnakeNode* iter = s->head->prev;

    while(iter != NULL){
        if((iter->posX == posX)&&(iter->posY == posY)) {
            return 1;
        }
        iter = iter->prev;
    }
    return 0;
}