#include "gsGGJEnemy.h"


#include "gsSystem.h"
#include "gsGGJBullet.h"
#include "gsGGJPlayer.h"


gsGGJEnemy::gsGGJEnemy(gsGGJGame *game) : gsGGJShip(game) {
	tag = gsGGJTag::Enemy;

	setupSpritesheet();

	hp = INITIAL_ENEMY_HEALTH;
	burstWaitCooldown = ENEMY_INITIAL_WAITING_TIME;
	burstWaitTime = 0;
	cooldown = ENEMY_COOLDOWN_TIME;
	cooldownTime = 0;
	waiting = true;

	gsVector3 size = gsVector3(51, 51, 0);
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
}
gsGGJEnemy::~gsGGJEnemy() {
	delete sprite;
}

void gsGGJEnemy::update() {
	if (transform.leftTheSceen()) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	
	move();
	burstWaitTime += gsClock::getDeltaTime();
	cooldownTime += gsClock::getDeltaTime();

	if (waiting) {
		if (burstWaitTime > burstWaitCooldown) {
			burstWaitCooldown = ENEMY_BURST_TIME;
			burstWaitTime = 0;
			cooldownTime = 0;
			waiting = false;
		}
	} else {
		if (cooldownTime > cooldown) {
			cooldownTime -= cooldown;
			shoot();
		}
		if (burstWaitTime > burstWaitCooldown) {
			burstWaitCooldown = ENEMY_WAITING_TIME;
			waiting = true;
		}
	}

	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
}
void gsGGJEnemy::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJEnemy::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
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

void gsGGJEnemy::setupSpritesheet() {
	sprite = new gsSpriteSheet("Shoot/enemy_walking.png", "enemy", 1, 4);
	int keyCount = 4;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++)
	{
		keyframes[i] = i;
	}
	gsAnimationClip *clip = new gsAnimationClip("enemyClip", keyframes, keyCount, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("enemyClip");
}
void gsGGJEnemy::move() {
	transform.applySpeed();
}
void gsGGJEnemy::shoot() {
    gsGGJBullet *bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
	game->addObjetToObjectsList(bullet);
}