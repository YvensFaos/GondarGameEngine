#include "gsSpriteSheet.h"

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

int gsSpriteSheet::getWidth(void)
{
	return width;
}

int gsSpriteSheet::setHeight(void)
{
	return height;
}