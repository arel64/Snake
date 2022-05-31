//
// Created by arels on 31/05/2022.
//

#include "board.h"
#include "snake.h"

void clearBoard(Board b){
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if(i==0 || i==BOARD_SIZE-1 || j==0 || j==BOARD_SIZE-1){
                b[i][j] = '#';
            }else{
                b[i][j] = ' ';
            }
        }
    }
}
void addSnake(Board b, Snake* s){
    SnakeNode* iter = s->head;
    do{
        b[iter->posY][iter->posX] = 's';
        iter = iter->prev;
    }while(iter != NULL);
}

