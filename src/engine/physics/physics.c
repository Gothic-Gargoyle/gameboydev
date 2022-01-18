//
// Created by hylbr on 22-3-2021.
//

#include "physics.h"

UINT8 playerlocation[2]; //X and Y of player, telt vanaf linksboven!

BYTE jumping = 0;
BYTE running = 0;

UINT8 currentSpeedY;
UINT8 currentSpeedX=2; //wordt gezet op max bij initialisatie ofzo?
UINT8 gravity = -2;
UINT8 floorYPosition = 118;

UINT8 wouldhitsurface(UINT8 projectedYPosition){
 if (projectedYPosition >= floorYPosition){
     return floorYPosition;
 }
    return -1;
}
void jump(){
    INT8 possiblesurfaceY;

    if(jumping==0){
        jumping = 1;
        currentSpeedY = 10;
        jumpsound();
    }
    currentSpeedY = currentSpeedY + gravity;

    playerlocation[1] = playerlocation[1] - currentSpeedY;

    possiblesurfaceY = wouldhitsurface(playerlocation[1]);

    if (possiblesurfaceY > -1 ){
        jumping = 0;
        move_sprite(0,playerlocation[0],possiblesurfaceY);
    } else{
        move_sprite(0,playerlocation[0],playerlocation[1]);
    }
}

void run(){
    if(running==0){
        running = 1;
        currentSpeedX += 5;
    }
}