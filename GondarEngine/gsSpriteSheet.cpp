#include "gsSpriteSheet.h"

#include "gsVector2.h"
#include "gsMacros.h"
#include "gsLogger.h"

gsSpriteSheet::gsSpriteSheet(void)
{
	width = 0;
	height = 0;
	rows = 0;
	collums = 0;
}

gsSpriteSheet::gsSpriteSheet(const char* file, int _rows, int _collums)
	: gsTexture(file)
{
	rows = _rows;
	collums = _collums;

	float stepU = (width/collums) / (float)width;
	float stepV = (height/rows) / (float)height;

	cellCount = rows * collums;

	positions = new gsVector2[cellCount * 4];

	float u = 0;
	float v = 0;
	for(int i = 0; i < cellCount * 4; i += 4)
	{
		positions[i]     = gsVector2(u, v + stepV);
		positions[i + 1] = gsVector2(u + stepU, v + stepV);
		positions[i + 2] = gsVector2(u + stepU, v);
		positions[i + 3] = gsVector2(u, v);

		u += stepU;
		v += stepV;
	}
}

int gsSpriteSheet::getCellCount(void)
{
	return cellCount;
}

gsVector2* gsSpriteSheet::getSpritePos(int pos)
{
	gsAssert(pos >= 0);
	gsAssert(pos < cellCount);
	pos *= 4;

	return &positions[pos];
}

gsSpriteSheet::~gsSpriteSheet(void)
{
	if(positions)
	{
		delete[] positions;
	}
}