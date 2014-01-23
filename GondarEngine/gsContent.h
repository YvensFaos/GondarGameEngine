#ifndef __GS_CONTENT__
#define __GS_CONTENT__


#include "gsTexture.h"
#include "gsSpriteSheet.h"

class gsContent {
public:
	static void init();
	static void dispose();

	static gsTexture* getTexture(const char* name);
	static gsSpriteSheet* getSpriteSheet(const char* name);
};

#endif