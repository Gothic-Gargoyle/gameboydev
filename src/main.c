#include <stdio.h>
#include "D:\programmeren\cenasm\Gameboy\gbdk\include\gb\gb.h"
#include "simplebackground.c"
#include "simplebackgroundmap.c"
#include "plenemy.c"

void init();
void checkInput();
void updateSwitches();

int main() {

    init();

    while (1){

        checkInput();
        updateSwitches();
        wait_vbl_done();


    }
}

void init(){
    DISPLAY_ON;
    //set background
    set_bkg_data(0,11,backgroundtiles);
    set_bkg_tiles(0,0,40,18,backgroundmap);
    SHOW_BKG;

    //set sprites
    set_sprite_data(0,2,plenemy);
    set_sprite_tile(0,0);
    move_sprite(0,88,87);



}

void updateSwitches(){
    HIDE_WIN;
    SHOW_SPRITES;

}


void checkInput() {

    switch (joypad()){
        case J_LEFT:
            scroll_sprite(0,-1,0); // ?, X, Y
            break;

        case J_RIGHT:
            scroll_sprite(0,1,0);
            break;

        case J_UP:
            scroll_sprite(0,0,-1);
            break;

        case J_DOWN:
            scroll_sprite(0,0,1);
            break;
    }
}