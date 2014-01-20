#ifndef __GS_GRAPHICS__
#define __GS_GRAPHICS__


#include "gsTransform.h"

class gsGraphics {
public:
	static void init(int resX, int resY);
	static void dispose();

	static void beginDraw();
	static void drawQuad(const gsTransform& transform);
	static void endDraw();
};

#endif