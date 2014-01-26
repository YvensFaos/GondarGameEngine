#include "gsGGJNumber.h"

#include "gsGraphics.h"
#include "gsGGJGame.h"
#include "gsSpriteSheet.h"
#include "gsAnimationClip.h"

gsGGJNumber::gsGGJNumber(gsGGJGame* game) : gsGGJObject(game)
{
	sprite = new gsSpriteSheet("GGJ\\numbers.png", "numbersspritesheet", 1, 10);
	
	int* frames = new int(10);
	frames[0] = 0;
	frames[1] = 1;
	frames[2] = 2;
	frames[3] = 3;
	frames[4] = 4;
	frames[5] = 5;
	frames[6] = 6;
	frames[7] = 7;
	frames[8] = 8;
	frames[9] = 9;

	transform = gsTransform(gsVector3(400, 300, 0), gsVector3(50, 50, 0), gsColor::white(1.0f));
}

void gsGGJNumber::draw(int number, int x, int y)
{
	transform.setTextureCoordinates(sprite->getSprite(0));

	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJNumber::draw()
{ }

void gsGGJNumber::update()
{ }

gsGGJNumber::~gsGGJNumber(void)
{ }

