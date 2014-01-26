#include "gsGGJPanorama.h"

#include "gsGGJGlobals.h"

gsGGJPanorama::gsGGJPanorama(gsGGJGame *game) : gsGGJObject(game)
{
	tag = gsGGJTag::Player;

	//setUpSpritesheet();

	speedFactor = PANORAMA_INITIAL_SPEEP;

	transform = gsTransform(gsVector3(400, 300, 0), gsVector3(66, 60, 0), gsColor::white(1.0f));

	solid = false;
	collident = false;
}

void gsGGJPanorama::update(void)
{
}

void gsGGJPanorama::draw(void)
{
}

gsGGJPanorama::~gsGGJPanorama(void)
{

}