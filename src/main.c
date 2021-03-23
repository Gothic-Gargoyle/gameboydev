#include <stdio.h>

#include <gb/gb.h>

#include <gb/font.h>

// Tiles & stuff
#include "tiles/env/simplebackground.c"
#include "tiles/env/simplebackgroundmap.c"
#include "tiles/sprites/plenemy.c"
#include "physics/physics.c"
#include "input/input.c"


void init();
void checkInput();
void updateSwitches();
font_t min_font;


//Not sure sabout this one tho
void performantdelay(UINT8 numloops){
    UINT8 i;
    for (i =0; i < numloops;i++){
        wait_vbl_done();
    }
}

int main() {
    init();

    while (1){

        checkInput();
        updateSwitches();
        performantdelay(5);


    }
}

void init(){

    font_init();
    min_font = font_load(font_min); //36 tiles
    font_set(min_font);

    //set headsupdisplay


    //set sprites
    set_sprite_data(0,3,plenemy);
    set_sprite_tile(0,0);
    playerlocation[0] = 88;
    playerlocation[1] = floorYposition;
    move_sprite(0,playerlocation[0],playerlocation[1]);
    jumping = 0;
    running = 0;
    currentSpeedX = 2;

    //set background
    set_bkg_data(37,11,backgroundtiles);
    set_bkg_tiles(0,0,40,18,backgroundmap);
    DISPLAY_ON;
}

void updateSwitches(){
    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;
}


