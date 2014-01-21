#include "gsSpriteSheet.h"

#include "gsTexture.h"

/*
gsSpriteSheet(void);
gsSpriteSheet(const char* file, int vertical, int horizontal);

char* getFile(void);
int getWidth(void);
int setHeight(void);
*/

gsSpriteSheet::gsSpriteSheet(void)
{
	width = 0;
	height = 0;
	vertical = 0;
	horizontal = 0;
}

gsSpriteSheet::gsSpriteSheet(const char* file, int vertical, int horizontal)
{
	texture = gsTexture(file);
	width = texture.width;
	height = texture.height;

}