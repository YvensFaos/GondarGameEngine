#include "gsShootEmUp_Bullet.h"

#include "gsConfig.h"
#include "gsGraphics.h"
#include "gsShootEmUpObjectTag.h"

gsShootEmUp_Bullet::gsShootEmUp_Bullet(bool isPlayerBullet, gsShootEmUpObject* shooter, gsShootEmUpGame *game, gsVector3 speed) : gsShootEmUpObject(game) {
	gsVector3 pos = shooter->transform.position;
	gsVector3 spd = speed;
	gsVector3 size = gsVector3(10,10,0);

	pos.x += shooter->transform.size.x / 2;

	int keyCount = 3;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++)
	{
		keyframes[i] = i;
	}
	if(isPlayerBullet)
	{
		tag = gsShootEmUpObjectTag::PlayerBullet;
		sprite = new gsSpriteSheet("Shoot/player_bullet.png", "bullet", 1, 3);
		collisionMask = 0x01;
	}
	else
	{
		tag = gsShootEmUpObjectTag::EnemyBullet;
		sprite = new gsSpriteSheet("Shoot/enemy_bullet.png", "bullet", 1, 3);
		collisionMask = 0x02;
		pos.y += shooter->transform.size.y;
	}

	gsAnimationClip *clip = new gsAnimationClip("bulletClip", keyframes, keyCount, 0.2f);
	sprite->addAnimation(clip);
	sprite->setAnimation("bulletClip");

	transform = gsTransform(pos, size, gsVector3::zero(), spd, gsColor::white(1.0f));
}

gsShootEmUp_Bullet::~gsShootEmUp_Bullet() {
	delete sprite;
}

void gsShootEmUp_Bullet::update() {
	transform.applySpeed();

	if (transform.position.x + transform.size.x < 0 || transform.position.x > GS_RESOLUTION_X) {
		game->removeObjectFromObjectsList(this);
	}

	if (transform.position.y + transform.size.y < 0 || transform.position.y > GS_RESOLUTION_Y) {
		game->removeObjectFromObjectsList(this);
	}
}

void gsShootEmUp_Bullet::draw() {
	// ativar sprite no openGL
	// chamar rotina de desenho
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsShootEmUp_Bullet::setDamage(float damage)
{
	this->damage = damage;
}

void gsShootEmUp_Bullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *other = static_cast<gsShootEmUpObject*>(_other);

	if(tag == gsShootEmUpObjectTag::EnemyBullet)
	{
		if(other->tag == gsShootEmUpObjectTag::Player)
		{
			game->removeObjectFromObjectsList(this);
			return;
		}
	}
	
	if(tag == gsShootEmUpObjectTag::PlayerBullet)
	{
		if(other->tag == gsShootEmUpObjectTag::Enemy)
		{
			game->removeObjectFromObjectsList(this);
			return;
		}
	}
}