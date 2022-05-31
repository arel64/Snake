//
// Created by arels on 31/05/2022.
//

#include "game.h"
#define INBOUNDS(X,Y) ((X>=BOARD_SIZE || X < 0 || Y<0 || Y>=BOARD_SIZE)? 1:0)


HANDLE hStdout;
COORD* dwCursorPosition;
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

    //Init CMD Handlers
    dwCursorPosition = malloc(sizeof (COORD));
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE ){
        return 1;
    }
    dwCursorPosition->X = 0;
    dwCursorPosition->Y = 0;
    return 0;

}
void redraw(Game* g){
    clearBoard(g->board);
    addSnake(g->board,&g->snake);
    printBoard(g);
}
int update(Game* g,char direction){
    //addNodeTail(&g->snake,g->snake.head->posX,g->snake.head->posY);
    SnakeNode* iter = g->snake.head;

    unsigned tempPosX,prevTempPosX;
    unsigned tempPosY,prevTempPosY;


    tempPosX = g->snake.head->posX;
    tempPosY = g->snake.head->posY;

    if(direction == 'a' || direction == 'd'){
        iter->posX -= direction=='d'? -1:1;
    }

    if(direction == 's' || direction == 'w'){
        iter->posY -= direction=='s'? -1:1;
    }

    if(INBOUNDS(iter->posX,iter->posY)!= 0){
        return 1;
    }
    modConsolePos(g->snake.tail->posX,g->snake.tail->posY,' ');
    modConsolePos(iter->posX,iter->posY,'s');

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
void modConsolePos(int posX,int posY,char c){
    COORD* temp = malloc(sizeof(COORD));
    temp->X =posX;
    temp->Y =posY;
    char str[2];
    str[0] = c;
    str[1] ='\0';
    LPCTSTR lpcstr = (LPCSTR)str;
    DWORD numberOfCharsWritten = 0;

    WriteConsoleOutputCharacter(hStdout,lpcstr,1,*temp,&numberOfCharsWritten);
    free(temp);
}