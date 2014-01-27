#include "gsGGJSlaien.h"

#include "gsGGJBullet.h"
#include "gsSystem.h"
#include "gsGGJPlayer.h"
#include "gsGGJHealth.h"

gsGGJSlaien::gsGGJSlaien(gsGGJGame *game) : gsGGJEnemy(game){
	multishot = 0.f;
	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = ENEMY_SLAIEN_HEALTH;
	maxHp = hp;
	burstWaitCooldown = ENEMY_SLAIEN_BURSTWAITCOOLDOWN;
	burstWaitTime = ENEMY_SLAIEN_BURSTWAITTIME;
	cooldown = ENEMY_SLAIEN_COOLDOWN;
	cooldownTime = ENEMY_SLAIEN_COOLDOWNTIME;
	waiting = ENEMY_SLAIEN_WAITING;

	//Alterar valores do transform
	gsVector3 size = gsVector3(42, 43, 0);
	gsVector3 speed = gsVector3(gsRandom::nextInt(-50, 50), gsRandom::nextInt(30, 50), 0);
	gsColor color = gsColor::white(1.f);

	transform = gsTransform(transform.position, size, gsVector3::zero(), speed, color);

	collisionMask = 0x01;

	setUpPhase();

	solid = false;
	if (gsRandom::chance(50))
	{
		this->bulletType = gsGGJBulletType::Spread;
		burstWaitCooldown = 0.5;
		cooldown = BULLET_SPREAD_COOLDOWN;
	}
	else
	{
		this->bulletType = gsGGJBulletType::Normal;
	}

	transform.size *= sizeFactor;
	transform.speed *= speedFactor;

	healthBar = new gsGGJHealth(game, this);
	game->addObjetToObjectsList(healthBar);
}

void gsGGJSlaien::setupSpritesheet()
{
	sprite = new gsSpriteSheet("GGJ/slaien.png", "enemy", 1, 1);
	int keyCount = 1;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++)
	{
		keyframes[i] = i;
	}
	gsAnimationClip *clip = new gsAnimationClip("SlaienClip", keyframes, keyCount, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("SlaienClip");
}

void gsGGJSlaien::update()
{
	gsGGJEnemy::update();

	multishot += gsClock::getDeltaTime()*0.2f;
	if (multishot >= 0.8f) {
		int spd = 100;

		gsGGJBullet *bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.x = -1 * spd;
		bullet->transform.speed.y = 0;
		game->addObjetToObjectsList(bullet);

		bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.x = spd;
		bullet->transform.speed.y = 0;
		game->addObjetToObjectsList(bullet);
		
		bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.y = -1 * spd;
		bullet->transform.speed.x = 0;
		game->addObjetToObjectsList(bullet);

		bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
		bullet->transform.speed.y = spd;
		bullet->transform.speed.x = 0;
		game->addObjetToObjectsList(bullet);
		
		multishot -= multishot;
	}
}