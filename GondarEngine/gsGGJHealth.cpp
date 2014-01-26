#include "gsGGJHealth.h"

#include "gsSystem.h"
#include "gsGGJShip.h"
#include "gsGGJGlobals.h"

gsGGJHealth::gsGGJHealth(gsGGJGame *game, gsGGJShip *target) : gsGGJObject(game)
{
	this->target = target;
	gsVector3 pos = target->transform.position;
	pos.z = 0.0f;
	pos.x += target->transform.size.x / 2.f;
	pos.y += target->transform.size.y;
	float size = target->hp;

	sprite = new gsSpriteSheet("GGJ\\bar.png", "health", 1, 1);
	transform = gsTransform(pos, gsVector3(size*10, 10, 0), gsColor::white(1.0f));

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

	if(gsInput::queryKey(GLFW_KEY_V) == gsKeyState::JustPressed)
	{
		GS_LOG(target->transform.position.x);
		GS_LOG(target->transform.position.y);
		GS_LOG(transform.position.x);
		GS_LOG(transform.position.y);
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
	pos.x = target->transform.position.x + target->transform.size.x / 2.f;
	pos.y = target->transform.position.y + target->transform.size.y;
}