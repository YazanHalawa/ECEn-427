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

void drawTank(bool staticTank, int startRow, int startCol, unsigned int * framePointer0) {
	int row = 0;
	int col = 0;
	if (staticTank){
		for (row = startRow; row < startRow + 16; row++) {
			for (col = startCol; col < startCol + 30; col++) {
				if ((tank_15x8[(row - startRow)/2] & (1<<((col-startCol)/2))) == 0) {
					framePointer0[row*640 + col] = BLACK;
				} else {
					framePointer0[row*640 + col] = GREEN;
				}
			}
		}
	}
	else{
		int current_position = getTankPositionGlobal();

		// First we need to erase the old tank
		for (row = 410; row < 426; row++) {
			for (col = old_position; col < old_position + 30; col++) {
				framePointer0[row*640 + col] = BLACK;
			}
		}
		// Now draw the tank in its new position
		for (row = 410; row < 426; row++) {
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
}

void destroyPartOfBunker(const int array[], unsigned int * framePointer0, int BunkerNumber, int segmentNumRow, int segmentCol){
	int row = 0;
	int col = 0;
	int incrementRow = segmentNumRow*12;
	int incrementCol = BunkerNumber*160 + segmentCol*12;
	// Now draw the tank in its new position
	for (row = 359 + incrementRow; row < 359 + incrementRow + 12; row++) {
		for (col = 56 + incrementCol; col < 56 + incrementCol + 12; col++) {
			if ((array[(row - 359 - incrementRow)/2] & (1<<((col-56 - incrementCol)/2))) == 0) {
				framePointer0[(row-12)*640 + col] = BLACK;
			} else {
				framePointer0[(row-12)*640 + col] = GREEN;
			}
		}
	}
}
void erodeBunker(int erosionState, unsigned int * framePointer0, int BunkerNumber, int segmentNumRow, int segmentCol){
	if (erosionState == -1){
		setErosionDegree(3);
		destroyPartOfBunker(bunkerDamage3_6x6, framePointer0, BunkerNumber, segmentNumRow, segmentCol);
	}
	else if (erosionState == 3){
		setErosionDegree(2);
		destroyPartOfBunker(bunkerDamage2_6x6, framePointer0, BunkerNumber, segmentNumRow, segmentCol);
	}
	else if (erosionState == 2){
		setErosionDegree(1);
		destroyPartOfBunker(bunkerDamage1_6x6, framePointer0, BunkerNumber, segmentNumRow, segmentCol);
	}

	else if (erosionState == 1){
		setErosionDegree(0);
		destroyPartOfBunker(bunkerDamage0_6x6, framePointer0, BunkerNumber, segmentNumRow, segmentCol);
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

void drawTopAlien(unsigned int * framePointer0, unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+16; row++) {
		for (col = start_x; col < start_x+24; col++) {
			if ((alien_top_out_12x8[(row - start_y)/2] & (1<<((col-start_x)/2))) == 0){
				framePointer0[row*640 + col] = BLACK;
			} else {
				framePointer0[row*640 + col] = WHITE;
			}
		}
	}
}

void drawMiddleAlien(unsigned int * framePointer0, unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+16; row++) {
		for (col = start_x; col < start_x+24; col++) {
			if ((alien_middle_out_12x8[(row - start_y)/2] & (1<<((col-start_x)/2))) == 0){
				framePointer0[row*640 + col] = BLACK;
			} else {
				framePointer0[row*640 + col] = WHITE;
			}
		}
	}
}

void drawBottomAlien(unsigned int * framePointer0, unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+16; row++) {
		for (col = start_x; col < start_x+24; col++) {
			if ((alien_bottom_out_12x8[(row - start_y)/2] & (1<<((col-start_x)/2))) == 0){
				framePointer0[row*640 + col] = BLACK;
			} else {
				framePointer0[row*640 + col] = WHITE;
			}
		}
	}
}

void drawTopAliens(unsigned int * framePointer0){
	int alienNumber = 0;
	for (alienNumber=0; alienNumber<11; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + (alienNumber*36);
		int alien_start_y = getAlienBlockPosition().y;
		drawTopAlien(framePointer0, alien_start_x, alien_start_y);
	}
}

void drawMiddleAliens(unsigned int * framePointer0) {
	int alienNumber = 0;
	for (alienNumber=11; alienNumber<22; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-11)*36);
		int alien_start_y = getAlienBlockPosition().y + 24;
		drawMiddleAlien(framePointer0, alien_start_x, alien_start_y);
	}

	for (alienNumber=22; alienNumber<33; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-22)*36);
		int alien_start_y = getAlienBlockPosition().y + 48;
		drawMiddleAlien(framePointer0, alien_start_x, alien_start_y);
	}
}

void drawBottomAliens(unsigned int * framePointer0) {
	int alienNumber = 0;
	for (alienNumber=33; alienNumber<44; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-33)*36);
		int alien_start_y = getAlienBlockPosition().y + 72;
		drawBottomAlien(framePointer0, alien_start_x, alien_start_y);
	}
	for (alienNumber=44; alienNumber<55; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-44)*36);
		int alien_start_y = getAlienBlockPosition().y + 96;
		drawBottomAlien(framePointer0, alien_start_x, alien_start_y);
	}
}


/////////////////////////////////////////////////////////////////////////////////
void drawTopAlien_in(unsigned int * framePointer0, unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+16; row++) {
		for (col = start_x; col < start_x+24; col++) {
			if ((alien_top_in_12x8[(row - start_y)/2] & (1<<((col-start_x)/2))) == 0){
				framePointer0[row*640 + col] = BLACK;
			} else {
				framePointer0[row*640 + col] = WHITE;
			}
		}
	}
}

void drawMiddleAlien_in(unsigned int * framePointer0, unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+16; row++) {
		for (col = start_x; col < start_x+24; col++) {
			if ((alien_middle_in_12x8[(row - start_y)/2] & (1<<((col-start_x)/2))) == 0){
				framePointer0[row*640 + col] = BLACK;
			} else {
				framePointer0[row*640 + col] = WHITE;
			}
		}
	}
}

void drawBottomAlien_in(unsigned int * framePointer0, unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+16; row++) {
		for (col = start_x; col < start_x+24; col++) {
			if ((alien_bottom_in_12x8[(row - start_y)/2] & (1<<((col-start_x)/2))) == 0){
				framePointer0[row*640 + col] = BLACK;
			} else {
				framePointer0[row*640 + col] = WHITE;
			}
		}
	}
}

void drawTopAliens_in(unsigned int * framePointer0){
	int alienNumber = 0;
	for (alienNumber=0; alienNumber<11; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + (alienNumber*36);
		int alien_start_y = getAlienBlockPosition().y;
		drawTopAlien_in(framePointer0, alien_start_x, alien_start_y);
	}
}

void drawMiddleAliens_in(unsigned int * framePointer0) {
	int alienNumber = 0;
	for (alienNumber=11; alienNumber<22; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-11)*36);
		int alien_start_y = getAlienBlockPosition().y + 24;
		drawMiddleAlien_in(framePointer0, alien_start_x, alien_start_y);
	}

	for (alienNumber=22; alienNumber<33; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-22)*36);
		int alien_start_y = getAlienBlockPosition().y + 48;
		drawMiddleAlien_in(framePointer0, alien_start_x, alien_start_y);
	}
}

void drawBottomAliens_in(unsigned int * framePointer0) {
	int alienNumber = 0;
	for (alienNumber=33; alienNumber<44; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-33)*36);
		int alien_start_y = getAlienBlockPosition().y + 72;
		drawBottomAlien_in(framePointer0, alien_start_x, alien_start_y);
	}
	for (alienNumber=44; alienNumber<55; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-44)*36);
		int alien_start_y = getAlienBlockPosition().y + 96;
		drawBottomAlien_in(framePointer0, alien_start_x, alien_start_y);
	}
}

void resetAliens(unsigned int * framePointer0) {
	int alien_start_x = 0;
	int alien_start_y = 0;
	for (alien_start_x = getAlienBlockPosition().x; alien_start_x < getAlienBlockPosition().x + (11*36) + 24; alien_start_x++) {
		for (alien_start_y = getAlienBlockPosition().y; alien_start_y < getAlienBlockPosition().y + 96 + 16; alien_start_y++) {
			framePointer0[alien_start_y*640 + alien_start_x] = BLACK;
		}
	}
}

void drawAliens(unsigned int * framePointer0) {
	resetAliens(framePointer0);
	setAlienBlockPosition(getAlienBlockPosition().x + 5, getAlienBlockPosition().y);
	if (getLegsOut()) {
		drawTopAliens(framePointer0);
		drawMiddleAliens(framePointer0);
		drawBottomAliens(framePointer0);
	} else {
		drawTopAliens_in(framePointer0);
		drawMiddleAliens_in(framePointer0);
		drawBottomAliens_in(framePointer0);
	}
	switchLegsOut();
}

void drawTankBullet(bool reset, unsigned int * framePointer0){
	int row;
	//int col;
	for (row = getTankBulletPosition().y-6; row < getTankBulletPosition().y; row++) {
		if (reset) {
			framePointer0[(row+3)*640 + getTankBulletPosition().x] = BLACK;
			framePointer0[(row+3)*640 + getTankBulletPosition().x-1] = BLACK;
			framePointer0[(row)*640 + getTankBulletPosition().x] = WHITE;
			framePointer0[(row)*640 + getTankBulletPosition().x-1] = WHITE;
		} else {
			framePointer0[row*640 + getTankBulletPosition().x] = WHITE;
			framePointer0[row*640 + getTankBulletPosition().x-1] = WHITE;

		}
	}
	if (getTankBulletPosition().y > 480){
		// Blank the bullet
		for (row = 0 ; row < 3; row++){
			framePointer0[(row)*640 + getTankBulletPosition().x] = BLACK;
			framePointer0[(row)*640 + getTankBulletPosition().x-1] = BLACK;
		}
		setBulletStatus(false);
	}
}
void drawLetter(bool isNumber, int start_row, int start_col, const int array[], unsigned int* framePointer0){
	int row;
	int col;
	for (row = start_row; row < start_row + 10; row++){
		for (col = start_col; col < start_col + 12; col++){
			if ((array[(row - start_row)/2] & (1<<((col-start_col)/2))) == 0){
				framePointer0[row*640 + col] = BLACK;
			} else {
				if (isNumber){
					framePointer0[row*640 + col] = GREEN;
				} else {
					framePointer0[row*640 + col] = WHITE;
				}
			}
		}
	}
}

void drawStats(unsigned int * framePointer0){
	int startRow = 10;
	int startCol = 20;

	// Draw the Score
	drawLetter(false, startRow, startCol, S_6x5, framePointer0); // Draw S
	startCol += 15;
	drawLetter(false, startRow, startCol, C_6x5, framePointer0); // Draw C
	startCol += 15;
	drawLetter(false, startRow, startCol, O_6x5, framePointer0); // Draw O
	startCol += 15;
	drawLetter(false, startRow, startCol, R_6x5, framePointer0); // Draw R
	startCol += 15;
	drawLetter(false, startRow, startCol, E_6x5, framePointer0); // Draw E
	startCol += 30;
	drawLetter(true, startRow, startCol, O_6x5, framePointer0); // Draw Zero
	startCol += 300;

	// Draw the Lives
	drawLetter(false, startRow, startCol, L_6x5, framePointer0); // Draw L
	startCol += 15;
	drawLetter(false, startRow, startCol, I_6x5, framePointer0); // Draw I
	startCol += 5;
	drawLetter(false, startRow, startCol, V_6x5, framePointer0); // Draw V
	startCol += 15;
	drawLetter(false, startRow, startCol, E_6x5, framePointer0); // Draw E
	startCol += 15;
	drawLetter(false, startRow, startCol, S_6x5, framePointer0); // Draw S
	startCol += 30;
	startRow -= 5;
	drawTank(true, startRow, startCol, framePointer0);
	startCol += 40;
	drawTank(true, startRow, startCol, framePointer0);
	startCol += 40;
	drawTank(true, startRow, startCol, framePointer0);



}
void render(unsigned int * framePointer0) {
	initAliveAliens();
	drawAliens(framePointer0);
	drawTank(false, 0, 0, framePointer0);
	drawBunkers(framePointer0);
	drawStats(framePointer0);
}
