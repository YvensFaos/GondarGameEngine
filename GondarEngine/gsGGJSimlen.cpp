#include "gsGGJSimlen.h"

#include "gsGGJBullet.h"
#include "gsSystem.h"
#include "gsGGJPlayer.h"
#include "gsRandom.h"
#include "gsGGJHealth.h"

gsGGJSimlen::gsGGJSimlen(gsGGJGame *game) : gsGGJEnemy(game){
	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = ENEMY_SIMLEN_HEALTH;
	maxHp = hp;
	burstWaitCooldown = ENEMY_SIMLEN_BURSTWAITCOOLDOWN;
	burstWaitTime = ENEMY_SIMLEN_BURSTWAITTIME;
	cooldown = ENEMY_SIMLEN_COOLDOWN;
	cooldownTime = ENEMY_SIMLEN_COOLDOWNTIME;
	waiting = ENEMY_SIMLEN_WAITING;

	//Alterar valores do transform
	gsVector3 size = gsVector3(32, 31, 0);
	gsVector3 speed;

	if (gsRandom::chance(70))
	{
		speed = gsVector3(gsRandom::nextInt(-50, 50), gsRandom::nextInt(30, 50), 0);
	}
	else
	{
		speed = gsVector3(0, 40, 0);
	}

	gsColor color = gsColor::white(1.f);

	transform = gsTransform(transform.position, size, gsVector3::zero(), speed, color);

	collisionMask = 0x01;

	modifyShot = false;

	if (gsGGJGlobal_PhasesAvaiable != 1) {
		gsGGJPhase playerPhase = game->player->phase;
		int phaseId = gsRandom::nextInt(1, gsGGJGlobal_PhasesAvaiable);
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

	if (phase == gsGGJPhase::RedPhase) transform.tint = PHASE_RED_COLOR;
	else if (phase == gsGGJPhase::GreenPhase) transform.tint = PHASE_GREEN_COLOR;
	else if (phase == gsGGJPhase::BluePhase) transform.tint = PHASE_BLUE_COLOR;
	else if (phase == gsGGJPhase::YellowPhase) transform.tint = PHASE_YELLOW_COLOR;
	else if (phase == gsGGJPhase::MagentaPhase) transform.tint = PHASE_MAGENTA_COLOR;

	solid = false;

	transform.size *= sizeFactor;
	transform.speed *= speedFactor;

	acelerate = 0.f;
	acelerated = false;
	
	healthBar = new gsGGJHealth(game, this);
	game->addObjetToObjectsList(healthBar);
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

void gsGGJSimlen::shoot()
{
	if(modifyShot == false){

		gsGGJBullet *bullet = new gsGGJBullet(false, gsGGJBulletType::Normal, &this->transform, game, phase);
		game->addObjetToObjectsList(bullet);

	}else{
		gsGGJBullet *bulletLeft = new gsGGJBullet(false, gsGGJBulletType::Normal, &this->transform, game, phase);
		bulletLeft->transform.speed.x = -ENEMY_SIMLEN_CONE;

		gsGGJBullet *bulletRight = new gsGGJBullet(false, gsGGJBulletType::Normal, &this->transform, game, phase);
		bulletRight->transform.speed.x = ENEMY_SIMLEN_CONE;

		game->addObjetToObjectsList(bulletLeft);
		game->addObjetToObjectsList(bulletRight);		
	}
	
	modifyShot = !modifyShot;
}

void gsGGJSimlen::update()
{
	gsGGJEnemy::update();

	acelerate += gsClock::getDeltaTime()*0.2;

	if (acelerate > 1.3f && !acelerated)
	{
		transform.speed.y += 100;
		acelerated = true;
	}
}
