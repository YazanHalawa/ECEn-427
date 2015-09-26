#ifndef globals_h
#define globals_h

#define BLACK 0x00000000;
#define GREEN 0x0000FF00;
typedef struct {unsigned short x; unsigned short y;} point_t;

void setTankPositionGlobal(unsigned short val);
unsigned short getTankPositionGlobal();

void setTankBulletPosition(point_t val);
point_t getTankBulletPosition();

//////////// Another way to do it without structs. //////////////
void setTankBulletPositionX(unsigned short val);
void setTankBulletPositionY(unsigned short val);

unsigned short getTankBulletPositionX();
unsigned short getTankBulletPositionY();

#endif