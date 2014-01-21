#ifndef __GS_SPRITE_SHEET__
#define __GS_SPRITE_SHEET__

#include "gsTexture.h"

class gsVector2;

class gsSpriteSheet
{
private:
	gsTexture texture;
	int width;
	int height;

	int vertical;
	int horizontal;

	int counter;

	gsVector2* positions;
public:
	gsSpriteSheet(void);
	gsSpriteSheet(const char* file, int vertical, int horizontal);
	~gsSpriteSheet(void);

	gsVector2* getSpritePos(int pos);

	int count(void);
	void sendToOpenGL(void);
};

#endif