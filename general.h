#pragma once
#ifndef GENERAL_H
#define GENERAL_H
#include <stdbool.h>
extern long frames;
extern long score;
void must_init(int test, const char* description);
int between(int low, int high);
bool collide(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
#endif // !GENERAL_H
