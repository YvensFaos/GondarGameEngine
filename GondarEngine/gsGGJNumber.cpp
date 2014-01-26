#include "gsGGJNumber.h"

#include "gsSystem.h"
#include "gsGGJGame.h"
#include "gsSpriteSheet.h"
#include "gsAnimationClip.h"

gsGGJNumber::gsGGJNumber(int number,int digit,gsGGJGame* game) : gsGGJObject(game)
{
	sprite = new gsSpriteSheet("GGJ\\numbers.png", "numbersspritesheet", 1, 10);
	this->digit = digit;
	this->number = number;

	transform = gsTransform(gsVector3(20 * digit, 0, 0), gsVector3(25, 25, 0), gsColor::white(1.0f));

	collident = false;
	solid = false;

}

void gsGGJNumber::draw() {
	transform.setTextureCoordinates(sprite->getSprite(number));

	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}


void gsGGJNumber::changeDigit(int i)
{
	this->digit = i;
}

void gsGGJNumber::update()
{

}

gsGGJNumber::~gsGGJNumber(void)
{ 
	delete sprite;
}

