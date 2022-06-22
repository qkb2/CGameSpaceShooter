#include <allegro5/allegro5.h>
#include "sprites.h"
#include "effects.h"

typedef struct FX
{
    int x, y;
    int frame;
    bool spark;
    bool used;
} FX;

#define FX_N 128
FX fx[FX_N];

void fx_init() {
    for (int i = 0; i < FX_N; i++)
        fx[i].used = false;
}

void fx_add(bool spark, int x, int y) {
    for (int i = 0; i < FX_N; i++) {
        if (fx[i].used)
            continue;

        fx[i].x = x;
        fx[i].y = y;
        fx[i].frame = 0;
        fx[i].spark = spark;
        fx[i].used = true;
        return;
    }
}

void fx_update() {
    for (int i = 0; i < FX_N; i++) {
        if (!fx[i].used)
            continue;

        fx[i].frame++;

        if ((!fx[i].spark && (fx[i].frame == (EXPLOSION_FRAMES * 2)))
            || (fx[i].spark && (fx[i].frame == (SPARKS_FRAMES * 2)))
            )
            fx[i].used = false;
    }
}

void fx_draw() {
    for (int i = 0; i < FX_N; i++) {
        if (!fx[i].used)
            continue;

        int frame_display = fx[i].frame / 2;
        ALLEGRO_BITMAP* bmp =
            fx[i].spark
            ? sprites.sparks[frame_display]
            : sprites.explosion[frame_display];

        int x = fx[i].x - (al_get_bitmap_width(bmp) / 2);
        int y = fx[i].y - (al_get_bitmap_height(bmp) / 2);
        al_draw_bitmap(bmp, x, y, 0);
    }
}