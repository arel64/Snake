//
// Created by arels on 31/05/2022.
//

#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

typedef struct node{
    unsigned short posX;
    unsigned short posY;
    struct node* next;
    struct node* prev;
}SnakeNode;


#endif //SNAKE_NODE_H
