#pragma once
#ifndef PLAYER_H
#define PLAYER_H

typedef struct SHIP {
    int x, y;
    int shot_timer;
    int lives;
    int respawn_timer;
    int invincible_timer;
} SHIP;
extern SHIP ship;

void ship_init();
void ship_update();
void ship_draw();
#endif // !PLAYER_H
