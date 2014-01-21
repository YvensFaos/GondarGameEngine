#include "gsSpriteSheet.h"

#include "gsVector2.h"
#include "gsMacros.h"
#include "gsLogger.h"

gsSpriteSheet::gsSpriteSheet(void)
{
	width = 0;
	height = 0;
	rows = 0;
	column = 0;
}

gsSpriteSheet::gsSpriteSheet(const char* file, int _rows, int _columns)
	: gsTexture(file)
{
	rows = _rows;
	column = _columns;

	float stepU = (width/column) / (float)width;
	float stepV = (height/rows) / (float)height;

	cellCount = rows * column;

	positions = new gsVector2[cellCount * 4];

	float u = 0;
	float v = 1;

	int counter = cellCount*4;
	int k = 0;

	for(int i = 0; i < column; i++)
	{
		for(int j = rows - 1; j > -1; j--)
		{
			positions[k]     = gsVector2(u, v);							//0, 1 -> 0, máx
			positions[k + 1] = gsVector2(u + stepU, v);					//1, 1 -> 0 + step, máx
			positions[k + 2] = gsVector2(u + stepU, v - stepV);         //1, 0 -> 0 + step, máx - step
			positions[k + 3] = gsVector2(u, v - stepV);                 //0, 0 -> 0, máx - step

			u += stepU;
			k += 4;
		}
		v -= stepV;
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