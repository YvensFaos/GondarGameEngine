#include "gsGGJFractalis.h"
#include "gsGGJBullet.h"
#include "gsSystem.h"
#include "gsGGJPlayer.h"

gsGGJFractalis::gsGGJFractalis(gsGGJGame *game) : gsGGJEnemy(game){

	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = ENEMY_FRACTALIS_HEALTH;
	burstWaitCooldown = ENEMY_FRACTALIS_BURSTWAITCOOLDOWN;
	burstWaitTime = ENEMY_FRACTALIS_BURSTWAITTIME;
	cooldown = ENEMY_FRACTALIS_COOLDOWN;
	cooldownTime = ENEMY_FRACTALIS_COOLDOWNTIME;
	waiting = ENEMY_FRACTALIS_WAITING;

	//Alterar valores do transform
	gsVector3 size = gsVector3(61, 56, 0);
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

gsGGJFractalis::~gsGGJFractalis(){}

//void gsGGJFractalis::update()
//{
//
//}

void gsGGJFractalis::draw()
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJFractalis::onCollision(gsGameObject *_other, const gsCollisionInfo& info)
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

void gsGGJFractalis::move()
{
	transform.applySpeed();
}

void gsGGJFractalis::shoot()
{
	gsGGJBullet *bullet = new gsGGJBullet(false, gsGGJBulletType::Spiral, &this->transform, game, phase);
	game->addObjetToObjectsList(bullet);
}

