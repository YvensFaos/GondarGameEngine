#include "gsGGJNumber.h"

#include "gsSystem.h"
#include "gsGGJGame.h"
#include "gsSpriteSheet.h"
#include "gsAnimationClip.h"

gsGGJNumber::gsGGJNumber(gsGGJGame* game) : gsGGJObject(game)
{
	sprite = new gsSpriteSheet("GGJ\\numbers.png", "numbersspritesheet", 1, 10);

	transform = gsTransform(gsVector3(400, 300, 0), gsVector3(50, 50, 0), gsColor::white(1.0f));
	collident = false;
	solid = false;

	digit = 0;
}

void gsGGJNumber::draw() {
	transform.setTextureCoordinates(sprite->getSprite(digit));

	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJNumber::update()
{
	//digit = (int)gsClock::getTotalTime() % 10;
}

gsGGJNumber::~gsGGJNumber(void)
{ 
	delete sprite;
}

