#include "gsSpriteSheet.h"

#include "gsVector2.h"
#include "gsMacros.h"

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

	this->vertical = vertical;
	this->horizontal = horizontal;

	float stepU = (width/horizontal) / (float)width;
	float stepV = (height/vertical) / (float)height;

	counter = vertical*horizontal*4;

	positions = new gsVector2[vertical*horizontal*4];

	float u = 0;
	float v = 0;
	for(int i = 0; i < counter; i += 4)
	{
		positions[i]     = gsVector2(u, v + stepV);
		positions[i + 1] = gsVector2(u + stepU, v + stepV);
		positions[i + 2] = gsVector2(u + stepU, v);
		positions[i + 3] = gsVector2(u, v);

		u += stepU;
		v += stepV;
	}
}

int gsSpriteSheet::count(void)
{
	return counter;
}

gsVector2* gsSpriteSheet::getSpritePos(int pos)
{
	//gsAssert(pos > 0 && pos < counter);

	gsVector2* sprite = new gsVector2[4];

	int i = 0;
	sprite[i]     = positions[i];
	sprite[i + 1] = positions[i + 1];
	sprite[i + 2] = positions[i + 2];
	sprite[i + 3] = positions[i + 3];

	return sprite;
}

gsSpriteSheet::~gsSpriteSheet(void)
{
	if(positions)
	{
		delete positions;
	}
}

void gsSpriteSheet::sendToOpenGL(void)
{
	texture.sendToOpenGL();
}