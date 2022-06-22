#include "general.h"
#include "display.h"
#include "sprites.h"
#include "player.h"
#include "hud.h"
#include "allegro5/allegro_font.h"
#include <stdio.h>
#include <stdlib.h>

ALLEGRO_FONT* font;
long score_display, best_score;
char flag = -1;

void file_score() {
    FILE* fp;
    errno_t err = fopen_s(&fp, "game.log", "r+");
    if (err && fp == NULL) {
        printf("Couldn't initialize a file\n");
        exit(1);
    }
    
    int fs = fscanf_s(fp, "%ld", &best_score);
    if (fs < 1)
        best_score = 0;
    fclose(fp);

    if (best_score >= score) {
        printf("bs %ld, sd %ld 0\n", best_score, score);
        flag = 0;
        fclose(fp);
        return;
    }

    err = fopen_s(&fp, "game.log", "w+");
    if (err && fp == NULL) {
        printf("Couldn't initialize a file\n");
        exit(1);
    }
    
    fprintf(fp, "%ld", score);
    flag = 1;
    best_score = score_display;
    fclose(fp);
    printf("bs %ld, sd %ld 1\n", best_score, score_display);
    return;
}

void hud_init() {
    font = al_create_builtin_font();
    must_init(font, "font");

    score_display = 0;
}

void hud_deinit() {
    al_destroy_font(font);
}

void hud_update() {
    if (frames % 2)
        return;

    for (long i = 5; i > 0; i--) {
        long diff = 1 << i;
        if (score_display <= (score - diff))
            score_display += diff;
    }
}

void hud_draw() {
    al_draw_textf(
        font,
        al_map_rgb_f(1, 1, 1),
        1, 1,
        0,
        "%06ld",
        score_display );

    int spacing = LIFE_W + 1;
    for (int i = 0; i < ship.lives; i++)
        al_draw_bitmap(sprites.life, 1 + (i * spacing), 10, 0);

    if (ship.lives < 0) {
        al_draw_text(
            font,
            al_map_rgb_f(1, 1, 1),
            BUFFER_W / 2, BUFFER_H / 2,
            ALLEGRO_ALIGN_CENTER,
            "G A M E  O V E R" );
        
        if (flag == -1)
            file_score();

        if (flag == 1)
            al_draw_text(
                font,
                al_map_rgb_f(204, 153, 0),
                BUFFER_W / 2, BUFFER_H / 2 + 20,
                ALLEGRO_ALIGN_CENTER,
                "NEW BEST SCORE!" );

        else
            al_draw_textf(
                font,
                al_map_rgb_f(1, 1, 1),
                BUFFER_W / 2, BUFFER_H / 2 + 20,
                ALLEGRO_ALIGN_CENTER,
                "YOU SCORED: %06ld, BEST SCORE IS: ",
                score_display );

        al_draw_textf(
            font,
            al_map_rgb_f(1, 1, 1),
            BUFFER_W / 2, BUFFER_H / 2 + 40,
            ALLEGRO_ALIGN_CENTER,
            "%06ld",
            best_score );
            
    }

}