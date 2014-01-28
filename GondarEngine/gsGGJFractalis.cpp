#include "gsGGJFractalis.h"

#include "gsGGJBullet.h"
#include "gsSystem.h"
#include "gsGGJPlayer.h"
#include "gsGGJHealth.h"

gsGGJFractalis::gsGGJFractalis(gsGGJGame *game) : gsGGJEnemy(game){

	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = ENEMY_FRACTALIS_HEALTH;
	maxHp = hp;
	burstWaitCooldown = ENEMY_FRACTALIS_BURSTWAITCOOLDOWN;
	burstWaitTime = ENEMY_FRACTALIS_BURSTWAITTIME;
	cooldown = ENEMY_FRACTALIS_COOLDOWN;
	cooldownTime = ENEMY_FRACTALIS_COOLDOWNTIME;
	waiting = ENEMY_FRACTALIS_WAITING;
	multishot = 0;
	multishotState = 0;
	//Alterar valores do transform
	gsVector3 size = gsVector3(61, 56, 0);
	gsVector3 speed = gsVector3(gsRandom::nextInt(-50, 50), gsRandom::nextInt(30, 50), 0);
	gsColor color = gsColor::white(1.f);

	transform = gsTransform(transform.position, size, gsVector3::zero(), speed, color);

	collisionMask = 0x01;

	setUpPhase();

	solid = false;
	this->bulletType = gsGGJBulletType::Spiral;

	transform.size *= sizeFactor;
	transform.speed *= speedFactor;

	healthBar = new gsGGJHealth(game, this);
	game->addObjetToObjectsList(healthBar);
}

void gsGGJFractalis::update(){
	gsGGJEnemy::update();

	multishot += gsClock::getDeltaTime()*0.2f;
	if (multishot >= 0.4f)
	{
		if(multishotState == 0)
		{
			int spd = 100;
		
			gsGGJBullet *bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.speed.x = -1 * spd;
			bullet->transform.speed.y = -1 * spd;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.speed.x = -1 * spd;
			bullet->transform.speed.y = 1 * spd;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.speed.x = 1 * spd;
			bullet->transform.speed.y = -1 * spd;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.speed.x = 1 * spd;
			bullet->transform.speed.y = 1 * spd;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			multishotState++;
		}
		else
		{
			int spd = 300;

			gsGGJBullet *bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.speed.x = -1 * spd;
			bullet->transform.speed.y = 0.f;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.position.x -= 20;
			bullet->transform.speed.x = -1 * spd;
			bullet->transform.speed.y = 0.f;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.position.x -= 40;
			bullet->transform.speed.x = -1 * spd;
			bullet->transform.speed.y = 0.f;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.speed.x = 1 * spd;
			bullet->transform.speed.y = 0.f;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.position.x += 20;
			bullet->transform.speed.x = 1 * spd;
			bullet->transform.speed.y = 0.f;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
			bullet->transform.position.x += 40;
			bullet->transform.speed.x = 1 * spd;
			bullet->transform.speed.y = 0.f;
			bullet->bulletType = gsGGJBulletType::Normal;
			game->addObjetToObjectsList(bullet);

			multishotState--;
		}
		multishot -= multishot;
	}

}

void gsGGJFractalis::setupSpritesheet()
{
	sprite = new gsSpriteSheet("GGJ/fractalis.png", "enemy", 1, 1);
	int keyCount = 1;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++)
	{
		keyframes[i] = i;
	}
	gsAnimationClip *clip = new gsAnimationClip("FractalisClip", keyframes, keyCount, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("FractalisClip");
}

