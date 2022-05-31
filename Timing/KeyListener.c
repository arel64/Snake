//
// Created by arels on 31/05/2022.
//

#include "KeyListener.h"


pthread_t listenerT;
pthread_mutex_t mutexNav;
char lastNavKey = 'a';

int isNavKey(char c){
    if(c=='a'||c=='s'||c=='d'||c=='w')
        return 1;
    return 0;
}
//TODO Make this not stupid
int isOppositeNav(char a, char b){
    switch (a) {
        case 'a':
            return b=='d'?1:0;
        break;

        case 'd':
            return b=='a'?1:0;
            break;

        case 'w':
            return b=='s'?1:0;
            break;

        case 's':
            return b=='w'?1:0;
            break;
        default:
            break;
    }
    return 0;
}
void* listenKey(void* args){
    int temp;
    while(1){
        temp = getch();
        if(isNavKey((char)temp) && lastNavKey != (char)temp && isOppositeNav(lastNavKey,temp) != 1){
            pthread_mutex_lock(&mutexNav);
            lastNavKey = (char)temp;
            pthread_mutex_unlock(&mutexNav);
        }
    }
}

int initListener() {

    if(pthread_mutex_init(&mutexNav, NULL)){
        perror("mutex failed");
        exit(1); // this will cause all threads to also exit
    }

    if (pthread_create(&listenerT, NULL, listenKey, NULL)) { // then pthread_create failed
        perror("pthread_create failed");
        exit(1); // this will cause all threads to also exit
    }
    return 0;
}
