#include "gsSpriteSheet.h"

#include "gsVector2.h"
#include "gsMacros.h"
#include "gsLogger.h"
#include "gsClock.h"
#include <ctime>

gsSpriteSheet::gsSpriteSheet(void)
	: gsTexture()
{
	rows = 0;
	column = 0;
	currentAnimation = 0;
	currentKeyframe = 0;
	elapsedTime = 0;
}

gsSpriteSheet::gsSpriteSheet(const char* file, const char* name, int _rows, int _columns)
	: gsTexture(file, name)
{
	rows = _rows;
	column = _columns;
	currentAnimation = 0;
	currentKeyframe = 0;
	elapsedTime = 0;

	genCoordinates();
}

gsSpriteSheet::~gsSpriteSheet(void)
{
	if(positions)
	{
		delete[] positions;
	}
	for (int i = 0; i < animations.getSize(); i++)
	{
		delete animations.get(i);
	}
}

void gsSpriteSheet::genCoordinates() {
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

void gsSpriteSheet::updateAnimation() {
	elapsedTime += gsClock::getDeltaTime();
	if (elapsedTime > currentAnimation->refreshInterval) {
		currentKeyframe++;
		currentKeyframe %= currentAnimation->keyFrameCount;

		elapsedTime -= currentAnimation->refreshInterval;
	}
}

void gsSpriteSheet::addAnimation(gsAnimationClip *clip) {
	animations.add(clip);
}
void gsSpriteSheet::setAnimation(const char* animationName) {
	for (int i = 0; i < animations.getSize(); i++)
	{
		if (!strcmp(animations.get(i)->name, animationName)) {
			currentAnimation = animations.get(i);
			break;
		}
	}
	currentKeyframe = 0;
}

gsVector2* gsSpriteSheet::getSprite(int i) {
	return &positions[i * 4];
}
gsVector2* gsSpriteSheet::getCurrentSprite() {
	return &positions[currentAnimation->keyFrames[currentKeyframe] * 4];
}