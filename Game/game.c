//
// Created by arels on 31/05/2022.
//

#include "game.h"
#define INBOUNDS(X,Y) ((X>=BOARD_SIZE-1 || X < 1 || Y<1 || Y>=BOARD_SIZE-1)? 1:0)


HANDLE hStdout;
int initGame(Game* g){
    //Score
    g->score = 0;

    //Speed 1-9
    g->speed = 1;

    //Board
    Board *b = (Board*)malloc(sizeof(char)*BOARD_SIZE*BOARD_SIZE);
    clearBoard(*b);
    g->board = b;

    //Snake
    SnakeNode* node = malloc(sizeof(SnakeNode));
    g->snake.head = node;
    g->snake.tail = node;
    g->snake.head->posX = BOARD_SIZE/2;
    g->snake.head->posY = BOARD_SIZE/2;
    g->snake.head->next = NULL;
    g->snake.head->prev = NULL;


    //Food
    initFood(&g->food);

    //Init CMD Handlers
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE ){
        return 1;
    }

    return 0;

}
void redraw(Game* g){
    clearBoard(g->board);
    addSnake(g->board,&g->snake);
    addFood(g->board,g->food);
    printBoard(g);
}
int update(Game* g,char direction){

    SnakeNode* iter = g->snake.head;

    unsigned tempPosX,prevTempPosX;
    unsigned tempPosY,prevTempPosY;


    tempPosX = g->snake.head->posX;
    tempPosY = g->snake.head->posY;

    //Determine position by last pressed key

    if(direction == 'a' || direction == 'd'){
        iter->posX -= direction=='d'? -1:1;
    }

    if(direction == 's' || direction == 'w'){
        iter->posY -= direction=='s'? -1:1;
    }


    //Snake is outside grid

    if(INBOUNDS(iter->posX,iter->posY)!= 0){
        return 1;
    }


    // Food Detection and console snake advance representation

    if(isSnakeIntercepts(&g->snake,g->food.posX,g->food.posY) == 1){
        modConsolePos(g->food.posX,g->food.posY,'s');
        repostion(&g->food);
        addNodeTail(&g->snake,tempPosX,tempPosY);
        modConsolePos(g->food.posX,g->food.posY,'A');

    }else{
        modConsolePos(g->snake.tail->posX,g->snake.tail->posY,' ');
    }
    modConsolePos(iter->posX,iter->posY,'s');


    //Advance snake
    iter = iter->prev;

    while(iter != NULL){
        prevTempPosX = iter->posX;
        prevTempPosY = iter->posY;
        iter->posX = tempPosX;
        iter->posY = tempPosY;
        tempPosX = prevTempPosX;
        tempPosY = prevTempPosY;

        iter = iter->prev;
    }
    if(isSnakeBodyIntercepts(&g->snake,g->snake.head->posX,g->snake.head->posY) == 1) {
        return 1;
    }
    return 0;
}
void printBoard(Game* g){

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c", (*(g->board))[i][j]);
        }
        printf("\n");
    }
}
void modConsolePos(short posX,short posY,char c){
    COORD* temp = malloc(sizeof(COORD));
    temp->X = posX;
    temp->Y = posY;
    char str[2];
    str[0] = c;
    str[1] ='\0';
    LPCTSTR lpcstr = (LPCSTR)str;
    DWORD numberOfCharsWritten = 0;

    WriteConsoleOutputCharacter(hStdout,lpcstr,1,*temp,&numberOfCharsWritten);
    free(temp);
}
void destroyGame(Game* g){
    free(g->board);
    SnakeNode* iter = g->snake.head;
    SnakeNode* temp;
    while(iter != NULL){
        temp = iter->prev;
        free(iter);
        iter = temp;
    }
    temp =NULL;
    free(g);
    g =NULL;
}