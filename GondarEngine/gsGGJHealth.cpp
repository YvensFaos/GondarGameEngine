#include "gsGGJHealth.h"

#include "gsSystem.h"
#include "gsGGJShip.h"
#include "gsGGJGlobals.h"

gsGGJHealth::gsGGJHealth(gsGGJGame *game, gsGGJShip *target) : gsGGJObject(game)
{
	this->target = target;
	size = target->hp * 10;

	sprite = new gsSpriteSheet("GGJ\\bar.png", "health", 1, 1);
	transform = gsTransform(target->transform.position, gsVector3(size, 5, 0), PHASE_RED_COLOR);
	move();

	solid = false;
	collident = false;
}

void gsGGJHealth::update(void)
{
	if(target->hp <= 0)
	{
		game->removeObjectFromObjectsList(this);
	}
	else
	{
		resize();
		move();
	}
}

void gsGGJHealth::draw(void)
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

gsGGJHealth::~gsGGJHealth(void)
{ }

void gsGGJHealth::resize(void)
{
	float size = target->hp;
	transform.size.x = size * 10;
}

void gsGGJHealth::move(void)
{
	gsVector3 pos = target->transform.position;
	//pos.x -= (target->transform.size.x/2);
	pos.y += target->transform.size.y + 5;
	transform.position = pos;
}