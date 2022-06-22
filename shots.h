#pragma once
#ifndef SHOTS_H
#define SHOTS_H
#include <stdbool.h>
void shots_init();
bool shots_add(bool ship, bool straight, int x, int y);
void shots_update();
bool shots_collide(bool ship, int x, int y, int w, int h);
void shots_draw();
#endif // !SHOTS_H
