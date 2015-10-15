/*
 * bitmaps.h
 *
 *  Created on: Sep 26, 2015
 *      Author: superman
 */

#ifndef BITMAPS_H_
#define BITMAPS_H_

/*
 * bitmaps.c
 *
 *  Created on: Sep 26, 2015
 *      Author: superman
 */

#define ALIEN_HEIGHT 16

// Packs each horizontal line of the figures into a single 32 bit word.
#define packWord32(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) \
		((b31 << 31) | (b30 << 30) | (b29 << 29) | (b28 << 28) | (b27 << 27) | (b26 << 26) | (b25 << 25) | (b24 << 24) |						  \
				(b23 << 23) | (b22 << 22) | (b21 << 21) | (b20 << 20) | (b19 << 19) | (b18 << 18) | (b17 << 17) | (b16 << 16) |						  \
				(b15 << 15) | (b14 << 14) | (b13 << 13) | (b12 << 12) | (b11 << 11) | (b10 << 10) | (b9  << 9 ) | (b8  << 8 ) |						  \
				(b7  << 7 ) | (b6  << 6 ) | (b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )

#define packWord24(b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) \
		((b23 << 23) | (b22 << 22) | (b21 << 21) | (b20 << 20) | (b19 << 19) | (b18 << 18) | (b17 << 17) | (b16 << 16) |						  \
				(b15 << 15) | (b14 << 14) | (b13 << 13) | (b12 << 12) | (b11 << 11) | (b10 << 10) | (b9  << 9 ) | (b8  << 8 ) |						  \
				(b7  << 7 ) | (b6  << 6 ) | (b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )

#define packWord16(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) \
		((b15 << 15) | (b14 << 14) | (b13 << 13) | (b12 << 12) | (b11 << 11) | (b10 << 10) | (b9  << 9 ) | (b8  << 8 ) |						  \
				(b7  << 7 ) | (b6  << 6 ) | (b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )

#define packWord15(b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) \
		((b14 << 14) | (b13 << 13) | (b12 << 12) | (b11 << 11) | (b10 << 10) | (b9  << 9 ) | (b8  << 8 ) |						  \
				(b7  << 7 ) | (b6  << 6 ) | (b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )

#define packWord12(b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) \
		((b11 << 11) | (b10 << 10) | (b9  << 9 ) | (b8  << 8 ) |						  \
				(b7  << 7 ) | (b6  << 6 ) | (b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )

#define packWord6(b5,b4,b3,b2,b1,b0) \
		((b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )

#define packWord3(b2,b1,b0) \
		((b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ))

int topOutAlienSymbol[ALIEN_HEIGHT] =
{
		packWord32(0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
		packWord32(0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
};

// Must define packWord for each of the different bit-widths.
static const int saucer_16x7[] =
{
		packWord16(0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0),
		packWord16(0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0),
		packWord16(0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0),
		packWord16(0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0),
		packWord16(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord16(0,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0),
		packWord16(0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0)
};

static const int alien_explosion_12x10[] =
{
		packWord12(0,0,0,0,0,0,1,0,0,0,0,0),
		packWord12(0,0,0,1,0,0,1,0,0,0,1,0),
		packWord12(1,0,0,1,0,0,0,0,0,1,0,0),
		packWord12(0,1,0,0,1,0,0,0,1,0,0,0),
		packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
		packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
		packWord12(0,0,0,1,0,0,0,1,0,0,1,0),
		packWord12(0,0,1,0,0,0,0,0,1,0,0,1),
		packWord12(0,1,0,0,0,1,0,0,1,0,0,0),
		packWord12(0,0,0,0,0,1,0,0,0,0,0,0)
};

static const int alien_top_in_12x8[] =
{
		packWord12(0,0,0,0,0,1,1,0,0,0,0,0),
		packWord12(0,0,0,0,1,1,1,1,0,0,0,0),
		packWord12(0,0,0,1,1,1,1,1,1,0,0,0),
		packWord12(0,0,1,1,0,1,1,0,1,1,0,0),
		packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
		packWord12(0,0,0,1,0,1,1,0,1,0,0,0),
		packWord12(0,0,1,0,0,0,0,0,0,1,0,0),
		packWord12(0,0,0,1,0,0,0,0,1,0,0,0)
};

static const int alien_top_out_12x8[] =
{
		packWord12(0,0,0,0,0,1,1,0,0,0,0,0),
		packWord12(0,0,0,0,1,1,1,1,0,0,0,0),
		packWord12(0,0,0,1,1,1,1,1,1,0,0,0),
		packWord12(0,0,1,1,0,1,1,0,1,1,0,0),
		packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
		packWord12(0,0,0,0,1,0,0,1,0,0,0,0),
		packWord12(0,0,0,1,0,1,1,0,1,0,0,0),
		packWord12(0,0,1,0,1,0,0,1,0,1,0,0)
};

static const int alien_middle_in_12x8[] =
{
		packWord12(0,0,0,1,0,0,0,0,0,1,0,0),
		packWord12(0,0,0,0,1,0,0,0,1,0,0,0),
		packWord12(0,0,0,1,1,1,1,1,1,1,0,0),
		packWord12(0,0,1,1,0,1,1,1,0,1,1,0),
		packWord12(0,1,1,1,1,1,1,1,1,1,1,1),
		packWord12(0,1,1,1,1,1,1,1,1,1,1,1),
		packWord12(0,1,0,1,0,0,0,0,0,1,0,1),
		packWord12(0,0,0,0,1,1,0,1,1,0,0,0)
};

static const int alien_middle_out_12x8[] =
{
		packWord12(0,0,0,1,0,0,0,0,0,1,0,0),
		packWord12(0,1,0,0,1,0,0,0,1,0,0,1),
		packWord12(0,1,0,1,1,1,1,1,1,1,0,1),
		packWord12(0,1,1,1,0,1,1,1,0,1,1,1),
		packWord12(0,1,1,1,1,1,1,1,1,1,1,1),
		packWord12(0,0,1,1,1,1,1,1,1,1,1,0),
		packWord12(0,0,0,1,0,0,0,0,0,1,0,0),
		packWord12(0,0,1,0,0,0,0,0,0,0,1,0)
};

static const int alien_bottom_in_12x8[] =
{
		packWord12(0,0,0,0,1,1,1,1,0,0,0,0),
		packWord12(0,1,1,1,1,1,1,1,1,1,1,0),
		packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
		packWord12(1,1,1,0,0,1,1,0,0,1,1,1),
		packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
		packWord12(0,0,1,1,1,0,0,1,1,1,0,0),
		packWord12(0,1,1,0,0,1,1,0,0,1,1,0),
		packWord12(0,0,1,1,0,0,0,0,1,1,0,0)
};

static const int alien_bottom_out_12x8[] =
{
		packWord12(0,0,0,0,1,1,1,1,0,0,0,0),
		packWord12(0,1,1,1,1,1,1,1,1,1,1,0),
		packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
		packWord12(1,1,1,0,0,1,1,0,0,1,1,1),
		packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
		packWord12(0,0,0,1,1,0,0,1,1,0,0,0),
		packWord12(0,0,1,1,0,1,1,0,1,1,0,0),
		packWord12(1,1,0,0,0,0,0,0,0,0,1,1)
};

static const int tank_15x8[] =
{
		packWord15(0,0,0,0,0,0,0,1,0,0,0,0,0,0,0),
		packWord15(0,0,0,0,0,0,1,1,1,0,0,0,0,0,0),
		packWord15(0,0,0,0,0,0,1,1,1,0,0,0,0,0,0),
		packWord15(0,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
		packWord15(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord15(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord15(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord15(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
};


// Shape of the entire bunker.
static const int bunker_24x18[] =
{
		packWord24(0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0),
		packWord24(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0),
		packWord24(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
		packWord24(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),
		packWord24(1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1)
};

// These are the blocks that comprise the bunker and each time a bullet
// strikes one of these blocks, you erod the block as you sequence through
// these patterns.
static const int bunkerDamage1_6x6[] = {
		packWord6(0,1,1,0,0,0),
		packWord6(0,0,0,0,0,1),
		packWord6(1,1,0,1,0,0),
		packWord6(1,0,0,0,0,0),
		packWord6(0,0,1,1,0,0),
		packWord6(0,0,0,0,1,0)
};

static const int bunkerDamage2_6x6[] = {
		packWord6(1,1,1,0,1,0),
		packWord6(1,0,1,0,0,1),
		packWord6(1,1,0,1,1,1),
		packWord6(1,0,0,0,0,0),
		packWord6(0,1,1,1,0,1),
		packWord6(0,1,1,0,1,0)
};

static const int bunkerDamage3_6x6[] = {
		packWord6(1,1,1,1,1,1),
		packWord6(1,0,1,1,0,1),
		packWord6(1,1,0,1,1,1),
		packWord6(1,1,0,1,1,0),
		packWord6(0,1,1,1,0,1),
		packWord6(1,1,1,1,1,1)
};

static const int bunkerDamage0_6x6[] = {
		packWord6(0,0,0,0,0,0),
		packWord6(0,0,0,0,0,0),
		packWord6(0,0,0,0,0,0),
		packWord6(0,0,0,0,0,0),
		packWord6(0,0,0,0,0,0),
		packWord6(0,0,0,0,0,0)
};

static const int S_6x5[] = {
		packWord6(1,1,1,1,1,0),
		packWord6(0,0,0,0,0,1),
		packWord6(0,1,1,1,1,0),
		packWord6(1,0,0,0,0,0),
		packWord6(0,1,1,1,1,1)
};

static const int C_6x5[] = {
		packWord6(1,1,1,1,1,0),
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(1,1,1,1,1,0)
};

static const int O_6x5[] = {
		packWord6(0,1,1,1,1,0),
		packWord6(1,0,0,0,0,1),
		packWord6(1,0,0,0,0,1),
		packWord6(1,0,0,0,0,1),
		packWord6(0,1,1,1,1,0)
};

static const int R_6x5[] = {
		packWord6(0,1,1,1,1,1),
		packWord6(1,0,0,0,0,1),
		packWord6(0,1,1,1,1,1),
		packWord6(1,0,0,0,0,1),
		packWord6(1,0,0,0,0,1)
};

static const int E_6x5[] = {
		packWord6(1,1,1,1,1,1),
		packWord6(0,0,0,0,0,1),
		packWord6(0,1,1,1,1,1),
		packWord6(0,0,0,0,0,1),
		packWord6(1,1,1,1,1,1)
};

static const int L_6x5[] = {
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(1,1,1,1,1,1)
};

static const int I_6x5[] = {
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1),
		packWord6(0,0,0,0,0,1)
};

static const int Zero_6x5[] = {
		packWord6(0,0,1,1,0,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,0,1,1,0,0)
};

static const int One_6x5[] = {
		packWord6(0,0,0,1,1,0),
		packWord6(0,0,0,1,0,0),
		packWord6(0,0,0,1,0,0),
		packWord6(0,0,0,1,0,0),
		packWord6(0,0,1,1,1,0)
};

static const int Two_6x5[] = {
		packWord6(0,0,1,1,0,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,0,1,0,0,0),
		packWord6(0,0,0,1,0,0),
		packWord6(1,1,1,1,1,0)
};

static const int Three_6x5[] = {
		packWord6(0,0,1,1,0,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,0,1,0,0,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,0,1,1,0,0)
};

static const int Four_6x5[] = {
		packWord6(0,0,1,0,1,0),
		packWord6(0,0,1,0,1,0),
		packWord6(0,1,1,1,1,0),
		packWord6(0,0,1,0,0,0),
		packWord6(0,0,1,0,0,0)
};

static const int Five_6x5[] = {
		packWord6(0,1,1,1,1,0),
		packWord6(0,0,0,0,1,0),
		packWord6(0,0,1,1,1,0),
		packWord6(0,1,0,0,0,0),
		packWord6(0,0,1,1,1,0)
};

static const int Six_6x5[] = {
		packWord6(0,1,1,1,1,0),
		packWord6(0,0,0,0,1,0),
		packWord6(0,1,1,1,1,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,1,1,1,1,0)
};

static const int Seven_6x5[] = {
		packWord6(0,1,1,1,1,0),
		packWord6(0,1,0,0,0,0),
		packWord6(0,0,1,0,0,0),
		packWord6(0,0,0,1,0,0),
		packWord6(0,0,0,0,1,0)
};
static const int Eight_6x5[] = {
		packWord6(0,1,1,1,1,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,1,1,1,1,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,1,1,1,1,0)
};
static const int Nine_6x5[] = {
		packWord6(0,1,1,1,1,0),
		packWord6(0,1,0,0,1,0),
		packWord6(0,1,1,1,1,0),
		packWord6(0,1,0,0,0,0),
		packWord6(0,1,0,0,0,0)
};

static const int* NumArray[] = {Zero_6x5, One_6x5, Two_6x5, Three_6x5, Four_6x5, Five_6x5, Six_6x5, Seven_6x5, Eight_6x5, Nine_6x5};

static const int V_6x5[] = {
		packWord6(1,0,0,0,0,1),
		packWord6(1,0,0,0,0,1),
		packWord6(1,0,0,0,0,1),
		packWord6(0,1,0,0,1,0),
		packWord6(0,0,1,1,0,0)
};

static const int t_bullet_3x5_2 [] = {
		packWord3(0,1,0),
		packWord3(1,1,1),
		packWord3(0,1,0),
		packWord3(0,1,0),
		packWord3(0,1,0)
};

static const int t_bullet_3x5_1 [] = {
		packWord3(0,1,0),
		packWord3(0,1,0),
		packWord3(1,1,1),
		packWord3(0,1,0),
		packWord3(0,1,0)
};

static const int t_bullet_3x5_0 [] = {
		packWord3(0,1,0),
		packWord3(0,1,0),
		packWord3(0,1,0),
		packWord3(1,1,1),
		packWord3(0,1,0)
};


static const int s_bullet_3x5_0 [] = {
		packWord3(1,0,0),
		packWord3(0,1,0),
		packWord3(0,0,1),
		packWord3(0,1,0),
		packWord3(1,0,0)
};

static const int s_bullet_3x5_1 [] = {
		packWord3(0,1,0),
		packWord3(0,0,1),
		packWord3(0,1,0),
		packWord3(1,0,0),
		packWord3(0,1,0)
};

static const int s_bullet_3x5_2 [] = {
		packWord3(0,0,1),
		packWord3(0,1,0),
		packWord3(1,0,0),
		packWord3(0,1,0),
		packWord3(0,0,1)
};

static const int s_bullet_3x5_3 [] = {
		packWord3(0,1,0),
		packWord3(1,0,0),
		packWord3(0,1,0),
		packWord3(0,0,1),
		packWord3(0,1,0)
};

#endif /* BITMAPS_H_ */
