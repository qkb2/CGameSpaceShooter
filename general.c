#include <stdio.h>
#include <stdlib.h>
#include "general.h"

long frames;
long score;

void must_init(int test, const char* description) {
	// throws error if sth didn't load properly
	if (test) return;
	printf("Couldn't initialize %s\n", description);
	exit(1);
}

int between(int low, int high) {
	return low + (rand() % (high - low));
}

bool collide(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
	// basic way to detect collision with hitbox-square
	if (ax1 > bx2) return false;
	if (ax2 < bx1) return false;
	if (ay1 > by2) return false;
	if (ay2 < by1) return false;
	return true;
}

