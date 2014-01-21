#ifndef __GS_SPRITE_SHEET__
#define __GS_SPRITE_SHEET__

#include "gsTexture.h"

class gsSpriteSheet
{
private:
	gsTexture texture;
	int width;
	int height;

	int vertical;
	int horizontal;
public:
	gsSpriteSheet(void);
	gsSpriteSheet(const char* file, int vertical, int horizontal);

	int getWidth(void);
	int setHeight(void);
};

#endif