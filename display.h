#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#define BUFFER_W 400
#define BUFFER_H 300
#include "allegro5/allegro5.h"

extern ALLEGRO_DISPLAY* disp;
extern ALLEGRO_BITMAP* buffer;

void disp_init();
void disp_deinit();
void disp_pre_draw();
void disp_post_draw();
#endif // !DISPLAY_H
