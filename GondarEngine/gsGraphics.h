#ifndef __GS_GRAPHICS__
#define __GS_GRAPHICS__


class gsGraphics {
public:
	static void init(int resX, int resY);
	static void dispose();

	static void beginDraw();
	static void endDraw();
};

#endif