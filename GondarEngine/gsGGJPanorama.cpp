#include "gsGGJPanorama.h"

#include "gsSystem.h"
#include "gsGGJGlobals.h"
#include "gsSpriteSheet.h"

gsGGJPanorama::gsGGJPanorama(gsGGJGame *game) : gsGGJObject(game)
{
	sprite = new gsSpriteSheet("GGJ\\panorama_double.png", "panorama", 1, 1);
	speedFactor = PANORAMA_INITIAL_SPEED;

	transform = gsTransform(gsVector3(0, -1200, 0), gsVector3(800, 2400, 0), gsColor::white(1.0f));
	transform.speed = gsVector3(0, speedFactor, 0);

	solid = false;
	collident = false;

	acelerateCounter = 0.0f;

	colorSprite = new gsSpriteSheet("GGJ\\bar.png", "color", 1, 1);
	colorTransform = gsTransform(gsVector3::zero(), gsVector3(800.f, 600.f, 0.f), gsColor::black(0.2f));
}

gsGGJPanorama::~gsGGJPanorama(void) {
	delete sprite;
}

void gsGGJPanorama::update(void)
{
	transform.applySpeed();

	if(transform.position.y >= 0)
	{
		transform.position.y = -1200;
	}
	
	if(colorTransform.tint.r < abs((gsGGJGlobal_Lifes - 3)) * 0.2f)
	{
		colorTransform.tint.r += gsClock::getDeltaTime()*0.05;
	}
	
	acelerate();
}

void gsGGJPanorama::draw(void)
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);

	colorSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(colorTransform);
}

void gsGGJPanorama::acelerate(void)
{
	acelerateCounter += gsClock::getDeltaTime();

	if(acelerateCounter >= 4.5)
	{
		transform.speed.y *= 1.05f;
		acelerateCounter = 0;
	}
}