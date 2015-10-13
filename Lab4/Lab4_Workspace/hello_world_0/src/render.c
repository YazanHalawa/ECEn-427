/*
 * render.c
 *
 *  Created on: Sep 26, 2015
 *      Author: superman
 */
#include "render.h"
#include "globals.h"
#include "bitmaps.h"

#define INITIAL_TANK_POSITION 20;

static unsigned int old_position = INITIAL_TANK_POSITION;
static const int pixelWidth = PIXEL_WIDTH;
static const int pixelHeight = PIXEL_HEIGHT;
static const int scalingFactor = SCALING_FACTOR;
static const int alienWidth = ALIEN_PIXEL_WIDTH;
static const int alienHeight = ALIEN_PIXEL_HEIGHT;
static const int totalAlienWidth = TOTAL_HORIZONTAL_DISTANCE_BETWEEN_ALIENS;
static const int totalAlienHeight = TOTAL_VERTICAL_DISTANCE_BETWEEN_ALIENS;
static const int bulletWidth = BULLET_PIXEL_WIDTH;
static const int bulletHeight = BULLET_PIXEL_HEIGHT;
static bool aliensStillMovingHorizontally = true;
static unsigned int * framePointer0;


// Draws the tank on the screen.
void drawTank(bool staticTank, int startRow, int startCol) {
	int row = 0;
	int col = 0;
	int tankHeight = TANK_HEIGHT;
	int tankWidth = TANK_WIDTH;
	int tankStart = TANK_ROW_START;
	int tankStop = TANK_ROW_STOP;

	if (staticTank){
		for (row = startRow; row < startRow + tankHeight; row++) {
			for (col = startCol; col < startCol + tankWidth; col++) {
				if ((tank_15x8[(row - startRow)/scalingFactor] & (1<<((col-startCol)/scalingFactor))) == 0) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = GREEN;
				}
			}
		}
	}
	else{
		int current_position = getTankPositionGlobal();

		// First we need to erase the old tank
		for (row = tankStart; row < tankStop; row++) {
			for (col = old_position; col < old_position + tankWidth; col++) {
				framePointer0[row*pixelWidth + col] = BLACK;
			}
		}
		// Now draw the tank in its new position
		for (row = tankStart; row < tankStop; row++) {
			for (col = current_position; col < current_position + tankWidth; col++) {
				if ((tank_15x8[(row - tankStart)/scalingFactor] & (1<<((col-current_position)/scalingFactor))) == 0) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = GREEN;
				}
			}
		}
		// Update the position of the tank in memory
		old_position = current_position;
	}
}

// Erodes part of a given bunker in a given location.
void destroyPartOfBunker(const int array[], int BunkerNumber, int segmentNumRow, int segmentCol){
	int row = 0;
	int col = 0;
	int incrementRow = segmentNumRow*12;
	int incrementCol = BunkerNumber*160 + segmentCol*12;
	// Now draw the tank in its new position
	for (row = 359 + incrementRow; row < 359 + incrementRow + 12; row++) {
		for (col = 56 + incrementCol; col < 56 + incrementCol + 12; col++) {
			if ((array[(row - 359 - incrementRow)/scalingFactor] & (1<<((col-56 - incrementCol)/scalingFactor))) == 0) {
				framePointer0[(row-12)*pixelWidth + col] = BLACK;
			} else {
				framePointer0[(row-12)*pixelWidth + col] = GREEN;
			}
		}
	}
}

// Called when eroding a bunker by a given degree
void erodeBunker(int erosionState, int BunkerNumber, int segmentNumRow, int segmentCol){
	if (erosionState == -1){
		setErosionDegree(3);
		destroyPartOfBunker(bunkerDamage3_6x6, BunkerNumber, segmentNumRow, segmentCol);
	}
	else if (erosionState == 3){
		setErosionDegree(2);
		destroyPartOfBunker(bunkerDamage2_6x6, BunkerNumber, segmentNumRow, segmentCol);
	}
	else if (erosionState == 2){
		setErosionDegree(1);
		destroyPartOfBunker(bunkerDamage1_6x6, BunkerNumber, segmentNumRow, segmentCol);
	}

	else if (erosionState == 1){
		setErosionDegree(0);
		destroyPartOfBunker(bunkerDamage0_6x6, BunkerNumber, segmentNumRow, segmentCol);
	}

}

// Draw a bunker on the screen.
void drawBunker(int BunkerNumber){
	int row = 0;
	int col = 0;
	int incrementY = BunkerNumber*160;
	// Now draw the tank in its new position
	for (row = 359; row < 395; row++) {
		for (col = 56 + incrementY; col < 104 + incrementY; col++) {
			if ((bunker_24x18[(row - 359)/scalingFactor] & (1<<((col-56 + incrementY)/scalingFactor))) == 0) {
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				framePointer0[row*pixelWidth + col] = GREEN;
			}
		}
	}
}

// Draw all four bunkers on the screen.
void drawBunkers() {
	int i = 0;
	for (i = 0; i < 4; i++){
		drawBunker(i);
	}

}

// Draw a top row alien
void drawTopAlien(unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+alienHeight; row++) {
		for (col = start_x; col < start_x+alienWidth; col++) {
			if ((alien_top_out_12x8[(row - start_y)/scalingFactor] & (1<<((col-start_x)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				framePointer0[row*pixelWidth + col] = WHITE;
			}
		}
	}
}

// Draw a middle row alien
void drawMiddleAlien(unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+alienHeight; row++) {
		for (col = start_x; col < start_x+alienWidth; col++) {
			if ((alien_middle_out_12x8[(row - start_y)/scalingFactor] & (1<<((col-start_x)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				framePointer0[row*pixelWidth + col] = WHITE;
			}
		}
	}
}

// Draw a bottom row alien
void drawBottomAlien(unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+alienHeight; row++) {
		for (col = start_x; col < start_x+alienWidth; col++) {
			if ((alien_bottom_out_12x8[(row - start_y)/scalingFactor] & (1<<((col-start_x)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				framePointer0[row*pixelWidth + col] = WHITE;
			}
		}
	}
}

// Draw all the top row aliens
void drawTopAliens(){
	int alienNumber = 0;
	for (alienNumber=0; alienNumber<11; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + (alienNumber*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y;
		drawTopAlien(alien_start_x, alien_start_y);
	}
}

// Draw all the middle row aliens
void drawMiddleAliens() {
	int alienNumber = 0;
	for (alienNumber=11; alienNumber<22; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-11)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + totalAlienHeight;
		drawMiddleAlien(alien_start_x, alien_start_y);
	}

	for (alienNumber=22; alienNumber<33; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-22)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + 48;
		drawMiddleAlien(alien_start_x, alien_start_y);
	}
}

// Draw all the bottom row aliens
void drawBottomAliens() {
	int alienNumber = 0;
	for (alienNumber=33; alienNumber<44; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-33)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + 72;
		drawBottomAlien(alien_start_x, alien_start_y);
	}
	for (alienNumber=44; alienNumber<55; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-44)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + 96;
		drawBottomAlien(alien_start_x, alien_start_y);
	}
}


// Draw a top row alien with legs in
void drawTopAlien_in(unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+alienHeight; row++) {
		for (col = start_x; col < start_x+alienWidth; col++) {
			if ((alien_top_in_12x8[(row - start_y)/scalingFactor] & (1<<((col-start_x)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				framePointer0[row*pixelWidth + col] = WHITE;
			}
		}
	}
}

// Draw a middle row alien with legs in
void drawMiddleAlien_in(unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+alienHeight; row++) {
		for (col = start_x; col < start_x+alienWidth; col++) {
			if ((alien_middle_in_12x8[(row - start_y)/scalingFactor] & (1<<((col-start_x)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				framePointer0[row*pixelWidth + col] = WHITE;
			}
		}
	}
}

// Draw a bottom row alien with legs in
void drawBottomAlien_in(unsigned int start_x, unsigned int start_y) {
	int row = 0;
	int col = 0;
	for (row = start_y; row < start_y+alienHeight; row++) {
		for (col = start_x; col < start_x+alienWidth; col++) {
			if ((alien_bottom_in_12x8[(row - start_y)/scalingFactor] & (1<<((col-start_x)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				framePointer0[row*pixelWidth + col] = WHITE;
			}
		}
	}
}

// Draw all top row aliens with legs in
void drawTopAliens_in(){
	int alienNumber = 0;
	for (alienNumber=0; alienNumber<11; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + (alienNumber*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y;
		drawTopAlien_in(alien_start_x, alien_start_y);
	}
}

// Draw all middle row aliens with legs in
void drawMiddleAliens_in() {
	int alienNumber = 0;
	for (alienNumber=11; alienNumber<22; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-11)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + totalAlienHeight;
		drawMiddleAlien_in(alien_start_x, alien_start_y);
	}

	for (alienNumber=22; alienNumber<33; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-22)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + 48;
		drawMiddleAlien_in(alien_start_x, alien_start_y);
	}
}

// Draw all bottom row aliens with legs in
void drawBottomAliens_in() {
	int alienNumber = 0;
	for (alienNumber=33; alienNumber<44; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-33)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + 72;
		drawBottomAlien_in(alien_start_x, alien_start_y);
	}
	for (alienNumber=44; alienNumber<55; alienNumber++) {
		if (!getAliveAlien(alienNumber)) {
			continue;
		}
		int alien_start_x = getAlienBlockPosition().x + ((alienNumber-44)*totalAlienWidth);
		int alien_start_y = getAlienBlockPosition().y + 96;
		drawBottomAlien_in(alien_start_x, alien_start_y);
	}
}

// Clear all aliens from the screen.
void resetAliens() {
	int alien_start_x = 0;
	int alien_start_y = 0;
	for (alien_start_x = getAlienBlockPosition().x; alien_start_x < getAlienBlockPosition().x + (11*totalAlienWidth) + alienWidth; alien_start_x++) {
		for (alien_start_y = getAlienBlockPosition().y; alien_start_y < getAlienBlockPosition().y + 96 + alienHeight; alien_start_y++) {
			framePointer0[alien_start_y*pixelWidth + alien_start_x] = BLACK;
		}
	}
}

// Draw all living aliens on the screen.
void drawAliens() {
	resetAliens(framePointer0);
	int farthestLeftAlienPosition = getAlienBlockPosition().x + ((getFarthestLeftAlienColumn()) * totalAlienWidth);
	int farthestRightAlienPosition = getAlienBlockPosition().x + ((getFarthestRightAlienColumn() + 1) * totalAlienWidth);
	if ((farthestLeftAlienPosition < 20 || farthestRightAlienPosition > 620) && aliensStillMovingHorizontally) {
		setAlienBlockPosition(getAlienBlockPosition().x, getAlienBlockPosition().y + 5);
		switchAliensDirection();
		aliensStillMovingHorizontally = false;
	} else {
		if (getAliensDirection()) {
			setAlienBlockPosition(getAlienBlockPosition().x + 5, getAlienBlockPosition().y);
		} else {
			setAlienBlockPosition(getAlienBlockPosition().x - 5, getAlienBlockPosition().y);
		}
		aliensStillMovingHorizontally = true;
	}
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

// Draw a T_type bullet at stage 0
void drawTBullet0(bullet b, bool reset) {
	int rowStart = b.point.y;
	int colStart = b.point.x;
	int row, col;
	for (row = rowStart; row < rowStart + bulletHeight; row++){
		for (col = colStart; col < colStart + bulletWidth; col++){
			if ((t_bullet_3x5_0[(row - rowStart)/scalingFactor] & (1<<((col-colStart)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			}
			else{
				if (reset) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw a T_type bullet at stage 1
void drawTBullet1(bullet b, bool reset) {
	int rowStart = b.point.y;
	int colStart = b.point.x;
	int row, col;
	for (row = rowStart; row < rowStart + bulletHeight; row++){
		for (col = colStart; col < colStart + bulletWidth; col++){
			if ((t_bullet_3x5_1[(row - rowStart)/scalingFactor] & (1<<((col-colStart)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			}
			else{
				if (reset) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw a T_type bullet at stage 2
void drawTBullet2(bullet b, bool reset) {
	int rowStart = b.point.y;
	int colStart = b.point.x;
	int row, col;
	for (row = rowStart; row < rowStart + bulletHeight; row++){
		for (col = colStart; col < colStart + bulletWidth; col++){
			if ((t_bullet_3x5_2[(row - rowStart)/scalingFactor] & (1<<((col-colStart)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			}
			else{
				if (reset) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw a S_type bullet at stage 0
void drawSBullet0(bullet b, bool reset) {
	int rowStart = b.point.y;
	int colStart = b.point.x;
	int row, col;
	for (row = rowStart; row < rowStart + bulletHeight; row++){
		for (col = colStart; col < colStart + bulletWidth; col++){
			if ((s_bullet_3x5_0[(row - rowStart)/scalingFactor] & (1<<((col-colStart)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			}
			else{
				if (reset) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw a S_type bullet at stage 1
void drawSBullet1(bullet b, bool reset) {
	int rowStart = b.point.y;
	int colStart = b.point.x;
	int row, col;
	for (row = rowStart; row < rowStart + bulletHeight; row++){
		for (col = colStart; col < colStart + bulletWidth; col++){
			if ((s_bullet_3x5_1[(row - rowStart)/scalingFactor] & (1<<((col-colStart)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			}
			else{
				if (reset) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw a S_type bullet at stage 2
void drawSBullet2(bullet b, bool reset) {
	int rowStart = b.point.y;
	int colStart = b.point.x;
	int row, col;
	for (row = rowStart; row < rowStart + bulletHeight; row++){
		for (col = colStart; col < colStart + bulletWidth; col++){
			if ((s_bullet_3x5_2[(row - rowStart)/scalingFactor] & (1<<((col-colStart)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			}
			else{
				if (reset) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw a S_type bullet at stage 3
void drawSBullet3(bullet b, bool reset) {
	int rowStart = b.point.y;
	int colStart = b.point.x;
	int row, col;
	for (row = rowStart; row < rowStart + bulletHeight; row++){
		for (col = colStart; col < colStart + bulletWidth; col++){
			if ((s_bullet_3x5_3[(row - rowStart)/scalingFactor] & (1<<((col-colStart)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			}
			else{
				if (reset) {
					framePointer0[row*pixelWidth + col] = BLACK;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw all alien bullets
void drawBullets() {
	int i;
	for (i=0; i<4; i++) {
		if (getAlienBullet(i).is_in_flight) {
			if (getAlienBullet(i).type == T_type) {
				switch(getAlienBullet(i).bullet_stage) {
				case (0):
					drawTBullet0(getAlienBullet(i), false);
					break;
				case (1):
					drawTBullet1(getAlienBullet(i), false);
					break;
				case (2):
					drawTBullet2(getAlienBullet(i), false);
					break;
				default:
					break;
				}
			} else {
				switch(getAlienBullet(i).bullet_stage) {
				case (0):
					drawSBullet0(getAlienBullet(i), false);
					break;
				case (1):
					drawSBullet1(getAlienBullet(i), false);
					break;
				case (2):
					drawSBullet2(getAlienBullet(i), false);
					break;
				case (3):
					drawSBullet3(getAlienBullet(i), false);
					break;
				default:
					break;
				}
			}
		}
	}
}

// Create a new bullet if there are less than 4 alien bullets on the screen,
// then display the new array of bullets on the screen.
void alienFire() {
	addAlienBullet();
	drawBullets(framePointer0);
}

// Update the locations of all alien bullets.
// This generally means moving the bullets down by two pixels.
// However, it also erases the bullets when they reach the bottom line.
void updateBullets() {
	int i;
	for (i=0; i<4; i++) {
		if (getAlienBullet(i).is_in_flight) {
			drawTBullet0(getAlienBullet(i), true);
			shiftAlienBullet(i);
			incrementBulletStage(i);
			if (getAlienBullet(i).point.y < 430) {
				if (getAlienBullet(i).type == T_type) {
					switch(getAlienBullet(i).bullet_stage) {
					case (0):
						drawTBullet0(getAlienBullet(i), false);
						break;
					case (1):
						drawTBullet1(getAlienBullet(i), false);
						break;
					case (2):
						drawTBullet2(getAlienBullet(i), false);
						break;
					default:
						break;
					}
				} else {
					switch(getAlienBullet(i).bullet_stage) {
					case (0):
						drawSBullet0(getAlienBullet(i), false);
						break;
					case (1):
						drawSBullet1(getAlienBullet(i), false);
						break;
					case (2):
						drawSBullet2(getAlienBullet(i), false);
						break;
					case (3):
						drawSBullet3(getAlienBullet(i), false);
						break;
					default:
						break;
					}
				}
			} else {
				disableBullet(i);
			}
		}
	}

}

// Draw the tank bullet on the screen.
void drawTankBullet(bool reset){
	int row;
	for (row = getTankBulletPosition().y-6; row < getTankBulletPosition().y; row++) {
		if (reset) {
			framePointer0[(row+3)*pixelWidth + getTankBulletPosition().x] = BLACK;
			framePointer0[(row+3)*pixelWidth + getTankBulletPosition().x-1] = BLACK;
			framePointer0[(row)*pixelWidth + getTankBulletPosition().x] = WHITE;
			framePointer0[(row)*pixelWidth + getTankBulletPosition().x-1] = WHITE;
		} else {
			framePointer0[row*pixelWidth + getTankBulletPosition().x] = WHITE;
			framePointer0[row*pixelWidth + getTankBulletPosition().x-1] = WHITE;

		}
	}
	if (getTankBulletPosition().y < 30 || getTankBulletPosition().y > 480){
		// Blank the bullet
		for (row = getTankBulletPosition().y-6 ; row < getTankBulletPosition().y; row++){
			framePointer0[(row)*pixelWidth + getTankBulletPosition().x] = BLACK;
			framePointer0[(row)*pixelWidth + getTankBulletPosition().x-1] = BLACK;
		}
		setBulletStatus(false);
	}
}

// Draw a letter. This is used to display the Score and Lives
void drawLetter(bool isNumber, int start_row, int start_col, const int array[]){
	int row;
	int col;
	for (row = start_row; row < start_row + 10; row++){
		for (col = start_col; col < start_col + 12; col++){
			if ((array[(row - start_row)/scalingFactor] & (1<<((col-start_col)/scalingFactor))) == 0){
				framePointer0[row*pixelWidth + col] = BLACK;
			} else {
				if (isNumber){
					framePointer0[row*pixelWidth + col] = GREEN;
				} else {
					framePointer0[row*pixelWidth + col] = WHITE;
				}
			}
		}
	}
}

// Draw the stats (score and lives) on the screen.
void drawStats(){
	int startRow = 10;
	int startCol = 20;

	// Draw the Score
	drawLetter(false, startRow, startCol, S_6x5); // Draw S
	startCol += 15;
	drawLetter(false, startRow, startCol, C_6x5); // Draw C
	startCol += 15;
	drawLetter(false, startRow, startCol, O_6x5); // Draw O
	startCol += 15;
	drawLetter(false, startRow, startCol, R_6x5); // Draw R
	startCol += 15;
	drawLetter(false, startRow, startCol, E_6x5); // Draw E
	startCol += 30;
	drawLetter(true, startRow, startCol, O_6x5); // Draw Zero
	startCol += 300;

	// Draw the Lives
	drawLetter(false, startRow, startCol, L_6x5); // Draw L
	startCol += 15;
	drawLetter(false, startRow, startCol, I_6x5); // Draw I
	startCol += 5;
	drawLetter(false, startRow, startCol, V_6x5); // Draw V
	startCol += 15;
	drawLetter(false, startRow, startCol, E_6x5); // Draw E
	startCol += 15;
	drawLetter(false, startRow, startCol, S_6x5); // Draw S
	startCol += 30;
	startRow -= 5;
	drawTank(true, startRow, startCol);
	startCol += 40;
	drawTank(true, startRow, startCol);
	startCol += 40;
	drawTank(true, startRow, startCol);



}

// Render the screen.
void render() {
	initAliveAliens();
	drawAliens(framePointer0);
	drawTank(false, 0, 0);
	drawBunkers(framePointer0);
	drawStats(framePointer0);
}

void render_init(unsigned int * fp) {
	framePointer0 = fp;
}
