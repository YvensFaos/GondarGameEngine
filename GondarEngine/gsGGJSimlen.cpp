#include "gsGGJSimlen.h"
#include "gsGGJBullet.h"
#include "gsSystem.h"
#include "gsGGJPlayer.h"

gsGGJSimlen::gsGGJSimlen(gsGGJGame *game) : gsGGJEnemy(game){
	
	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = ENEMY_SIMLEN_HEALTH;
	burstWaitCooldown = ENEMY_SIMLEN_BURSTWAITCOOLDOWN;
	burstWaitTime = ENEMY_SIMLEN_BURSTWAITTIME;
	cooldown = ENEMY_SIMLEN_COOLDOWN;
	cooldownTime = ENEMY_SIMLEN_COOLDOWNTIME;
	waiting = ENEMY_SIMLEN_WAITING;

	//Alterar valores do transform
	gsVector3 size = gsVector3(51, 51, 0);
	gsVector3 speed = gsVector3(gsRandom::nextInt(-50, 50), gsRandom::nextInt(30, 50), 0);
	gsColor color = gsColor::white(1.f);

	transform = gsTransform(transform.position, size, gsVector3::zero(), speed, color);

	collisionMask = 0x01;

	modifyShot = false;

		if (INITIAL_PHASES_AVAIABLE != 1) {
		gsGGJPhase playerPhase = game->player->phase;
		int phaseId = gsRandom::nextInt(1, INITIAL_PHASES_AVAIABLE);
		switch (phaseId) {
			case 1: phase = gsGGJPhase::RedPhase; break;
			case 2: phase = gsGGJPhase::GreenPhase; break;
			case 3: phase = gsGGJPhase::BluePhase; break;
			case 4: phase = gsGGJPhase::YellowPhase; break;
			case 5: phase = gsGGJPhase::MagentaPhase; break;
		}
	} else {
		phase = gsGGJPhase::RedPhase;
	}

	if (phase == gsGGJPhase::RedPhase) transform.tint = gsColor::red();
	else if (phase == gsGGJPhase::GreenPhase) transform.tint = gsColor::green();
	else if (phase == gsGGJPhase::BluePhase) transform.tint = gsColor::blue();
	else if (phase == gsGGJPhase::YellowPhase) transform.tint = gsColor::yellow();
	else if (phase == gsGGJPhase::MagentaPhase) transform.tint = gsColor::magenta();

	solid = false;
}

gsGGJSimlen::~gsGGJSimlen(){}

//void gsGGJSimlen::update() 
//{
//
//}

void gsGGJSimlen::draw()
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJSimlen::onCollision(gsGameObject *_other, const gsCollisionInfo& info)
{
	gsGGJObject *otherCastedToGGJObject = static_cast<gsGGJObject*>(_other);

	if (otherCastedToGGJObject->tag == gsGGJTag::PlayerBullet) {
		gsGGJBullet *other = static_cast<gsGGJBullet*>(_other);
		hp -= other->damage;

		if (hp <= 0) {
			game->removeObjectFromObjectsList(this);
			gsGGJGlobal_Points += POINTS_WHEN_ENEMY_DIES;
			return;
		}
		gsGGJGlobal_Points += POINTS_WHEN_BULLET_STRIKES;
	}
}

void gsGGJSimlen::setupSpritesheet()
{
	sprite = new gsSpriteSheet("GGJ/simlien.png", "enemy", 1, 1);
	int keyCount = 1;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++)
	{
		keyframes[i] = i;
	}
	gsAnimationClip *clip = new gsAnimationClip("SimlenClip", keyframes, keyCount, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("SimlenClip");
}

void gsGGJSimlen::move()
{
	transform.applySpeed();
}

void gsGGJSimlen::shoot()
{
	if(modifyShot == false){

		gsGGJBullet *bullet = new gsGGJBullet(false, gsGGJBulletType::Normal, &this->transform, game, phase);
		game->addObjetToObjectsList(bullet);

	}else{

		gsGGJBullet *bulletLeft = new gsGGJBullet(false, gsGGJBulletType::Normal, &this->transform, game, phase);
		bulletLeft->transform.speed.x = -10;

		gsGGJBullet *bulletRight = new gsGGJBullet(false, gsGGJBulletType::Normal, &this->transform, game, phase);
		bulletRight->transform.speed.x = 10;

		game->addObjetToObjectsList(bulletLeft);
		game->addObjetToObjectsList(bulletRight);
		
	}
	
	modifyShot = !modifyShot;

}

