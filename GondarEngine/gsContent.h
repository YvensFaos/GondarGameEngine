#ifndef __GS_CONTENT__
#define __GS_CONTENT__


#include "gsTexture.h"
#include "gsSpriteSheet.h"

class gsContent {
public:
	static void init();
	static void dispose();

	static int* getTexture(const char* name);
};

#endif