#ifndef __GS_SPRITE_SHEET__
#define __GS_SPRITE_SHEET__

class gsSpriteSheet
{
private:
	const char* file;
	int width;
	int height;

public:
	gsSpriteSheet(void);
	gsSpriteSheet(const char* file, int width, int height);

	char* getFile(void);
	int getWidth(void);
	int setHeight(void);
}

#endif