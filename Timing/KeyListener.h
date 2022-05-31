//
// Created by arels on 31/05/2022.
//

#ifndef SNAKE_KEYLISTENER_H
#define SNAKE_KEYLISTENER_H
#include "stdio.h"
#include <conio.h>
#include <unistd.h>
#include "pthread.h"
extern char lastNavKey;
extern pthread_t listenerT;
extern pthread_mutex_t mutexNav;
int initListener();
void* listenKey(void* args);
int isOppositeNav(char a, char b);
int isNavKey(char c);
#endif //SNAKE_KEYLISTENER_H
