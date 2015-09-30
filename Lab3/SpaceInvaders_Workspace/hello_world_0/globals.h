#ifndef globals_h
#define globals_h
#include <stdbool.h>
#include <stdint.h>
#define BLACK 0x00000000;
#define GREEN 0x0000FF00;
#define WHITE 0xFFFFFFFF;
typedef struct {
	unsigned short x;
	unsigned short y;
} point_t;

void setTankPositionGlobal(unsigned short val);
unsigned short getTankPositionGlobal();

void setTankBulletPosition(point_t val);
point_t getTankBulletPosition();

int getErosionDegree();
void setErosionDegree(int newDegree);

void initAliveAliens();
point_t getAlienBlockPosition();
bool getAliveAlien(unsigned int i);
void killAlien(unsigned int i);
bool getBulletStatus();
void setBulletStatus(bool newStatus);

void switchLegsOut();
bool getLegsOut();

void setAlienBlockPosition(unsigned int x, unsigned int y);

unsigned short getTankBulletPositionX();
unsigned short getTankBulletPositionY();

#endif
