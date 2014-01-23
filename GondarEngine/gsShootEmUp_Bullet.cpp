#include "gsShootEmUp_Bullet.h"

#include "gsGraphics.h"
#include "gsShootEmUpObjectTag.h"

gsShootEmUp_Bullet::gsShootEmUp_Bullet(bool isPlayerBullet, gsShootEmUpObject* shooter, gsShootEmUpGame *game, gsVector3 speed) : gsShootEmUpObject(game) {
	// Carregar sprite da bullet
	gsVector3 pos = shooter->transform.position;
	gsVector3 spd = speed;
	gsVector3 size = gsVector3(10,10,0);

	transform = gsTransform(pos, size, gsVector3::zero(), spd, gsColor::white(1.0f));

	if(isPlayerBullet)
	{
		tag = gsShootEmUpObjectTag::PlayerBullet;

		sprite = new gsSpriteSheet("Shoot/player_bullet.png", "bullet", 1, 3);
		int keyCount = 3;
		int *keyframes = new int[keyCount];
		for (int i = 0; i < keyCount; i++)
		{
			keyframes[i] = i;
		}
		gsAnimationClip *clip = new gsAnimationClip("bulletClip", keyframes, keyCount, 0.2f);
		sprite->addAnimation(clip);
		sprite->setAnimation("bulletClip");
	}
	else
	{
		tag = gsShootEmUpObjectTag::EnemyBullet;

		sprite = new gsSpriteSheet("Shoot/enemy_bullet.png", "bullet", 1, 3);
		int keyCount = 3;
		int *keyframes = new int[keyCount];
		for (int i = 0; i < keyCount; i++)
		{
			keyframes[i] = i;
		}
		gsAnimationClip *clip = new gsAnimationClip("bulletClip", keyframes, keyCount, 0.2f);
		sprite->addAnimation(clip);
		sprite->setAnimation("bulletClip");
	}

	damage = 0;
}

gsShootEmUp_Bullet::~gsShootEmUp_Bullet() {
	delete sprite;
}

void gsShootEmUp_Bullet::update() {
	transform.applySpeed();
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