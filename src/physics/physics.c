//
// Created by hylbr on 22-3-2021.
//

#include "physics.h"
BYTE jumping;
BYTE running;
INT8 playerlocation[2]; //X and y of player
UINT8 gravity = -2;
UINT8 currentspeedY;
UINT8 currentSpeedX;
UINT8 floorYposition = 101;

INT8 wouldhitsurface(UINT8 projectedYPosition){
    if (projectedYPosition >= floorYposition){
        return  floorYposition;
    }
    return -1;
}

//void run(){
//    if (running == 0){
//        running = 1;
//        currentSpeedX = 4; //Ik snap physics niet, also cant use floating points :')
//    } else{
//        running = 0;
//        currentSpeedX = 2;
//    }
//}


void jump(UINT8 spriteid,UINT8 spritelocation[2]){
    INT8 possiblesurfaceY;

    if (jumping == 0){
        jumping = 1 ;
        currentspeedY = 10;
    }
    currentspeedY = currentspeedY + gravity;
    spritelocation[1] = spritelocation[1] - currentspeedY;
    possiblesurfaceY = wouldhitsurface(spritelocation[1]);

    if(possiblesurfaceY >- -1){
        jumping = 0;
        move_sprite(spriteid,spritelocation[0],possiblesurfaceY);
    } else{
        move_sprite(spriteid,spritelocation[0],spritelocation[1]);
    }


}