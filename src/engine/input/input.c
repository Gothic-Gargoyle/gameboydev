//
// Created by hylbr on 22-3-2021.
//

#include "input.h"
void checkInput() {

    //TODO: fix this to be more concisive.
    if (joypad() & J_A || jumping == 1){
        jump();
    }

    //TODO Running
    //Ooit.

    switch (joypad()){
        case J_LEFT:
            playerlocation[0] = playerlocation[0] - currentSpeedX;
            move_sprite(0,playerlocation[0],playerlocation[1]); // spriteid, X, Y
            break;

        case J_RIGHT:
            playerlocation[0] = playerlocation[0] + currentSpeedX;
            move_sprite(0,playerlocation[0],playerlocation[1]);
            break;

     /*   case J_UP:
            playerlocation[1] = playerlocation[1] - currentSpeedX;
            move_sprite(0,playerlocation[0],playerlocation[1]);
            break;

        case J_DOWN:
            playerlocation[1] = playerlocation[1] + currentSpeedX;
            move_sprite(0,playerlocation[0],playerlocation[1]);
            break;
*/
    }

}