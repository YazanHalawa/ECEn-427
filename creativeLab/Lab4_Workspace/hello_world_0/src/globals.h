#ifndef globals_h
#define globals_h
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define BLACK 0x00000000;
#define GREEN 0x0000FF00;
#define WHITE 0xFFFFFFFF;
#define RED 0x00FF0000;
#define BULLET_WHITE 0xFFFFFFFE;

#define ALIEN_COLUMNS 11;
#define ALIEN_ROWS 5;
#define ALIEN_BLOCK_POSITION_INIT_X 40;
#define ALIEN_BLOCK_POSITION_INIT_Y 60;
#define ALIEN_PIXEL_WIDTH 32;
#define ALIEN_PIXEL_HEIGHT 24;
#define ALIEN_BLOCK_INCREMENT 4
#define ALIEN_BLOCK_RIGHT_BORDER 620
#define ALIEN_BLOCK_LEFT_BORDER 20

#define SAUCER_INIT_X 40
#define SAUCER_LEFT_INIT_Y -32
#define SAUCER_RIGHT_INIT_Y 640
#define SAUCER_INCREMENT 2
#define SAUCER_PIXEL_WIDTH 32;
#define SAUCER_PIXEL_HEIGHT 14;
#define SACUER_DIRECTION_RIGHT 1
#define SAUCER_DIRECTION_LEFT -1
#define SAUCER_INACTIVE 0
#define SAUCER_POINTS_VALUE_COUNT 6
#define SAUCER_POINTS_MULTIPLIER 50

#define HORIZONTAL_DISTANCE_BETWEEN_ALIENS 12;
#define VERTICAL_DISTANCE_BETWEEN_ALIENS 8;
#define TOTAL_HORIZONTAL_DISTANCE_BETWEEN_ALIENS 36
#define TOTAL_VERTICAL_DISTANCE_BETWEEN_ALIENS 24
#define FIT_TICKS_BETWEEN_ALIEN_BLOCK_MOVEMENT_INIT 70;


#define NUMBER_OF_ALIENS 55;
#define COLUMN_DEAD -1;
#define DEAD -1
#define BULLET_STAGE_0 0
#define BULLET_STAGE_1 1
#define BULLET_STAGE_2 2
#define BULLET_STAGE_3 3
#define BULLET_STAGE_4 4
#define BULLET_COUNT 4
#define BULLET_PIXEL_WIDTH 6
#define BULLET_PIXEL_HEIGHT 10
#define BULLET_INCREMENT 3

#define PIXEL_WIDTH 640;
#define PIXEL_HEIGHT 480;

#define TANK_HEIGHT 16
#define TANK_WIDTH 30
#define TANK_ROW_START 410
#define TANK_ROW_STOP 426
#define TANK_INCREMENT 5
#define TANK_BULLET_MIN 40
#define TANK_BULLET_MAX 480

#define BUNKER_ROW_START 359
#define BUNKER_ROW_STOP 395
#define BUNKER_COL_START 56
#define BUNKER_COL_STOP 104
#define BUNKER_SQUARE_LENGTH 12
#define BUNKER_QUADRANT_WIDTH 160
#define BUNKER_0 0
#define BUNKER_1 1
#define BUNKER_2 2
#define BUNKER_3 3
#define BUNKER_COUNT 4

#define SCALING_FACTOR 2



enum bullet_type {
	T_type,
	S_type,
	tank_type
};

enum bullet_stage {
	stage_0,
	stage_1,
	stage_2,
	stage_3
};

typedef struct {
	short x;
	short y;
} point_t;

typedef struct {
	point_t point;
	bool is_in_flight;
	enum bullet_type type;
	int bullet_stage;
} bullet;

bool canSwitchContext();
void setSwitchContext(bool newVal);

int getVolLevel();
void setVolLevel(int newVal);

////// Sound Flags //////////
int getMarchingStage();
bool getMarchingFlag();
void setMarchingFlag(bool newVal);
bool getMarchingFlag2();
void setMarchingFlag2(bool newVal);
bool getMarchingFlag3();
void setMarchingFlag3(bool newVal);
bool getMarchingFlag4();
void setMarchingFlag4(bool newVal);
bool getSaucerFlag();
void setSaucerFlag(bool newVal);
bool getSaucerHighFlag();
void setSaucerHighFlag(bool newVal);
bool getExplosionFlag();
void setExplosionFlag(bool newVal);
bool getPingFlag();
void setPingFlag(bool newVal);
bool getInvaderKilledFlag();
void setInvaderKilledFlag(bool newVal);
/////////////////////////////

int getBottomRow();

int getScore();
void setScore(unsigned int newVal);

int getSaucerBonus();
void setSaucerBonus(int newVal);

int getDeadAlien();
void setDeadAlien(int newVal);

void setOldAlienPos(point_t newVal);
point_t getOldAlienPos();

bool isTankHit();
void setTankHit(bool newVal);

bool isEndOfGame();
void setEndOfGame(bool newVal);

int getAlienTicks();

void checkHits();
void setTankPositionGlobal(unsigned short val);
unsigned short getTankPositionGlobal();

void setTankBulletPosition(point_t val);
point_t getTankBulletPosition();

void switchAliensDirection();
bool getAliensDirection();

int getFarthestRightAlienColumn();

int getFarthestLeftAlienColumn();

int getErosionDegree(int index);
void setErosionDegree(int index, int newDegree);

int getLives();
void setLives(int newVal);

bool isInit();
void setInit(bool newVal);

void addAlienBullet();
int getAlienBulletsNum();
bullet getAlienBullet(int index);
void shiftAlienBullet(int index);
void incrementBulletStage(int index);

bool getCurrentBulletA();

void switchCurrentBulletA();

int getSaucerDirection();
void setSaucerDirection(int newVal);
point_t getSaucerPos();
void setSaucerPos(point_t newVal);

void initAliveAliens();
point_t getAlienBlockPosition();
bool getAliveAlien(unsigned int i);
void killAlien(unsigned int i);
bool getBulletStatus();
void setBulletStatus(bool newStatus);
void disableBullet(int i);


void switchLegsOut();
bool getLegsOut();

void setAlienBlockPosition(unsigned int x, unsigned int y);

unsigned short getTankBulletPositionX();
unsigned short getTankBulletPositionY();

#endif