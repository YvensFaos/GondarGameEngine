#include "gsGGJHealth.h"

#include "gsSystem.h"
#include "gsGGJShip.h"
#include "gsGGJGlobals.h"

gsGGJHealth::gsGGJHealth(gsGGJGame *game, gsGGJShip *target) : gsGGJObject(game)
{
	this->target = target;
	size = target->hp;

	sprite = new gsSpriteSheet("GGJ\\bar.png", "health", 1, 1);
	transform = gsTransform(target->transform.position, gsVector3(size, 3, 0), PHASE_RED_COLOR);
	move();

	solid = false;
	collident = false;
}
gsGGJHealth::~gsGGJHealth(void) {
	delete sprite;
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

void gsGGJHealth::resize(void)
{
	transform.size.x = target->transform.size.x * (target->hp / target->maxHp);
}

void gsGGJHealth::move(void)
{
	gsVector3 pos = target->transform.position;
	pos.y += target->transform.size.y + 5;
	pos.x += (target->transform.size.x - transform.size.x) /2.f;
	transform.position = pos;
}