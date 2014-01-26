#include "gsGGJSlaien.h"
#include "gsGGJBullet.h"
#include "gsSystem.h"
#include "gsGGJPlayer.h"


gsGGJSlaien::gsGGJSlaien(gsGGJGame *game) : gsGGJEnemy(game){
	
	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = ENEMY_SLAIEN_HEALTH;
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

	if (phase == gsGGJPhase::RedPhase) transform.tint = PHASE_RED_COLOR;
	else if (phase == gsGGJPhase::GreenPhase) transform.tint = PHASE_GREEN_COLOR;
	else if (phase == gsGGJPhase::BluePhase) transform.tint = PHASE_BLUE_COLOR;
	else if (phase == gsGGJPhase::YellowPhase) transform.tint = PHASE_YELLOW_COLOR;
	else if (phase == gsGGJPhase::MagentaPhase) transform.tint = PHASE_MAGENTA_COLOR;

	solid = false;

}

gsGGJSlaien::~gsGGJSlaien(){}

//void gsGGJSlaien::update()
//{
//
//}

void gsGGJSlaien::draw()
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJSlaien::onCollision(gsGameObject *_other, const gsCollisionInfo& info)
{
	gsGGJObject *otherCastedToGGJObject = static_cast<gsGGJObject*>(_other);

	if (otherCastedToGGJObject->tag == gsGGJTag::PlayerBullet) {
		gsGGJBullet *other = static_cast<gsGGJBullet*>(_other);
		if (phase != other->phase) {
			hp -= other->damage;

			if (hp <= 0) {
				game->removeObjectFromObjectsList(this);
				gsGGJGlobal_Points += POINTS_WHEN_ENEMY_DIES;
				return;
			}
			gsGGJGlobal_Points += POINTS_WHEN_BULLET_STRIKES;
		}
	}
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

void gsGGJSlaien::move()
{
	transform.applySpeed();
}

void gsGGJSlaien::shoot()
{
	gsGGJBullet *bullet = new gsGGJBullet(false, gsGGJBulletType::Spread, &this->transform, game, phase);
	game->addObjetToObjectsList(bullet);
}

