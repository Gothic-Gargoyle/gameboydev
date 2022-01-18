//
// Created by hylbr on 17-1-2022.
//

#include <gb/hardware.h>
#include "sound.h"

void jumpsound(){
    NR10_REG = 0x16;
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = 0x00;
    NR14_REG = 0xC3;
}


