/*
 * render.c
 *
 *  Created on: Sep 26, 2015
 *      Author: superman
 */
#include "render.h"
#include "globals.h"
#include "bitmaps.h"

static unsigned int old_position = 20;

void drawTank(unsigned int * framePointer0) {
	int row = 0;
	int col = 0;
	int current_position = getTankPositionGlobal();

	// First we need to erase the old tank
	for (row = 410; row <= 425; row++) {
		for (col = old_position; col < old_position + 30; col++) {
			framePointer0[row*640 + col] = BLACK;
		}
	}
	// Now draw the tank in its new position
	for (row = 410; row <= 425; row++) {
		for (col = current_position; col < current_position + 30; col++) {
			if ((tank_15x8[(row - 410)/2] & (1<<((col-current_position)/2))) == 0) {
				framePointer0[row*640 + col] = BLACK;
			} else {
				framePointer0[row*640 + col] = GREEN;
			}
		}
	}
	old_position = current_position;
}

void erodeBunker(unsigned int * framePointer0, int BunkerNumber, int segmentNumRow, int segmentCol){
	int row = 0;
	int col = 0;
	int incrementRow = segmentNumRow*12;
	int incrementCol = BunkerNumber*160 + segmentCol*12;
	// Now draw the tank in its new position
			for (row = 359 + incrementRow; row < 359 + incrementRow + 12; row++) {
				for (col = 56 + incrementCol; col < 56 + incrementCol + 12; col++) {
					if ((bunkerDamage0_6x6[(row - 359 - incrementRow)/2] & (1<<((col-56 - incrementCol)/2))) == 0) {
						framePointer0[(row-12)*640 + col] = BLACK;
					} else {
						framePointer0[(row-12)*640 + col] = GREEN;
					}
				}
			}
}

void drawBunker(unsigned int * framePointer0, int BunkerNumber){
	int row = 0;
	int col = 0;
	int incrementY = BunkerNumber*160;
	// Now draw the tank in its new position
		for (row = 359; row < 395; row++) {
			for (col = 56 + incrementY; col < 104 + incrementY; col++) {
				if ((bunker_24x18[(row - 359)/2] & (1<<((col-56 + incrementY)/2))) == 0) {
					framePointer0[row*640 + col] = BLACK;
				} else {
					framePointer0[row*640 + col] = GREEN;
				}
			}
		}
}
void drawBunkers(unsigned int * framePointer0) {
	int i = 0;
	for (i = 0; i < 4; i++){
		drawBunker(framePointer0, i);
	}

}

void render(unsigned int * framePointer0) {
	drawTank(framePointer0);
	drawBunkers(framePointer0);
}