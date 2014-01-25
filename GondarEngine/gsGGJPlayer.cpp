#include "gsGGJPlayer.h"


#include "gsSystem.h"


gsGGJPlayer::gsGGJPlayer(gsGame *game)
{
	//tag = gsShootEmUpObjectTag::Player;

	sprite = new gsSpriteSheet("Shoot\\player_walking.png", "player", 1, 4);

	hp = 20;
	damage = 3;
	//weaponCooldownTime = 0;
	//weaponCooldown = 0.5;

	//Animação walking
	int* frames = new int(4);
	frames[0] = 0;
	frames[1] = 1;
	frames[2] = 2;
	frames[3] = 3;

	gsAnimationClip* clip = new gsAnimationClip("walking", frames, 4, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("walking");

	// tetenta pelo construtor
	transform = gsTransform(gsVector3(400, 300, 0), gsVector3(50, 50, 0), gsColor::white(1.0f));
	collisionMask = 0x02;
}

void gsGGJPlayer::draw()
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

gsGGJPlayer::~gsGGJPlayer(void)
{

}

void gsGGJPlayer::move()
{

}

void gsGGJPlayer::update()
{
	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
}

void gsGGJPlayer::onCollision(gsGameObject *other, const gsCollisionInfo& info)
{

}