#ifndef __GS_SPRITE_SHEET__
#define __GS_SPRITE_SHEET__

class gsTexture;

class gsSpriteSheet
{
private:
	gsTexture texture;

	const char* file;
	int width;
	int height;

	int vertical;
	int horizontal;
public:
	gsSpriteSheet(void);
	gsSpriteSheet(const char* file, int vertical, int horizontal);

	char* getFile(void);
	int getWidth(void);
	int setHeight(void);
}

#endif