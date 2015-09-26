/*
 * render.h
 *
 *  Created on: Sep 26, 2015
 *      Author: superman
 */

#ifndef RENDER_H_
#define RENDER_H_

void drawTank(unsigned int * framePointer0);

void erodeBunker(unsigned int * framePointer0, int BunkerNumber, int segmentNumX, int segmentY);

void render(unsigned int * framePointer0);

#endif /* RENDER_H_ */
