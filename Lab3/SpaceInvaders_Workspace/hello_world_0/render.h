/*
 * render.h
 *
 *  Created on: Sep 26, 2015
 *      Author: superman
 */

#ifndef RENDER_H_
#define RENDER_H_
#include <stdbool.h>

void drawTank(bool staticTank, int startRow, int startCol, unsigned int * framePointer0);

void erodeBunker(int erosionState, unsigned int * framePointer0, int BunkerNumber, int segmentNumX, int segmentY);
void destroyPartOfBunker(const int array[], unsigned int * framePointer0, int BunkerNumber, int segmentNumRow, int segmentCol);

void drawAliens(unsigned int * framePointer0);

void drawTankBullet(bool reset, unsigned int * framePointer0);

void render(unsigned int * framePointer0);

#endif /* RENDER_H_ */
