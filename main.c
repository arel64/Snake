

#include <malloc.h>


#include "Timing/KeyListener.h"
#include "Game/game.h"
#define MSCOEFFICENT 1000000


int main(void) {
   initListener();
   Game *g = (Game*)malloc(sizeof(Game));
   initGame(g);
   redraw(g);
   addNodeTail(&g->snake,g->snake.head->posX,g->snake.head->posY+1);
   while(1){
       switch(lastNavKey){
           case 'a':
           case 'd':
           case 'w':
           case 's':
               if(update(g,lastNavKey) == 1){
                   break;
               }
               break;
           default:
               break;
       }
       usleep(g->speed * MSCOEFFICENT * 0.5);

   }
    pthread_join(listenerT,NULL);
    printf("Done");
    return 0;
}

