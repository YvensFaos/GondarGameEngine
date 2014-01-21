#ifndef __GS_SPRITE_SHEET__
#define __GS_SPRITE_SHEET__

#include "gsTexture.h"

class gsVector2;

class gsSpriteSheet : public gsTexture{
private:
	int column;
	int rows;

	int cellCount;

	gsVector2* positions;
public:
	gsSpriteSheet(void);
	gsSpriteSheet(const char* file, int _rows, int _column);
	~gsSpriteSheet(void);

	gsVector2* getSpritePos(int pos);

	int getCellCount(void);
};

#endif