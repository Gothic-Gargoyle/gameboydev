cmake_minimum_required(VERSION 3.15)
project(helloworldgameboy)

set(CMAKE_C_STANDARD 99)

add_executable(helloworldgameboy src/main.c src/tiles/hud/hud.c src/tiles/hud/hud.h src/engine/sound/sound.c src/engine/sound/sound.h)

include_directories(src/gbdk/include)