//Standaard C stdio!
#include <stdio.h>

//gameboy libraries
#include <gb/gb.h>
#include <gb/font.h>

//Physics and input
#include "engine/physics/physics.c"
#include "engine/input/input.c"

// Tiles & stuff
#include "tiles/env/simplebackground.c"
#include "tiles/env/simplebackgroundmap.c"
#include "tiles/sprites/plenemy.c"
#include "tiles/hud/hud.c"
#include "tiles/titlescreen/snek_data.c"
#include "tiles/titlescreen/snek_map.c"

//Sound
#include "engine/sound/sound.c"

void startscreen();
void gameinit();
void checkInput();
void updateSwitches();
font_t min_font;


//Not sure about this one tho
void performantdelay(UINT8 numloops){
    UINT8 i;
    for (i =0; i < numloops;i++){
        wait_vbl_done();
    }
}

int main() {
    startscreen();
    gameinit();
    while (1){

        checkInput();
        updateSwitches();
        performantdelay(5);


    }
}

//Splashscreen werkt, omg!
//TODO flashend press start toevoegen oid
void startscreen(){
    set_bkg_data(0,92,snek_data);
    set_bkg_tiles(0,0,20,18,snek_map);
    //TODO iets keks met scrollen/wobbly ofzo?
    SHOW_BKG;
    DISPLAY_ON;
    waitpad(J_START);
}
//daadwerkelijk spel starten
void gameinit(){

    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;
    //set headsupdisplay
    font_init();
    min_font = font_load(font_min); //36 tiles
    font_set(min_font);

    //set sprites
    set_sprite_data(0x1A,3,plenemy);
    set_sprite_tile(0,0x1A);
    playerlocation[0] = 88; //x
    playerlocation[1] = floorYPosition; //y
    move_sprite(0,playerlocation[0],playerlocation[1]);

    //set background
    set_bkg_data(37,11,backgroundtiles);
    set_bkg_tiles(0,0,40,18,backgroundmap);

    //set window layer
    set_win_tiles(0,0,5,1,hud);
    move_win(7,130);

    //set diplay ON
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;
}

void updateSwitches(){
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;

}


