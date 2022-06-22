#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <allegro5/allegro5.h>
extern unsigned char key[ALLEGRO_KEY_MAX];
void keyboard_init();
void keyboard_update(ALLEGRO_EVENT* event);
#endif // !KEYBOARD_H