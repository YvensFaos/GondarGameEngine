#include "gsGGJEnemy.h"

#include "gsSystem.h"
#include "gsGGJBullet.h"
#include "gsGGJPlayer.h"
#include "gsGGJDrop.h"
#include "gsGGJExplosion.h"

gsGGJEnemy::gsGGJEnemy(gsGGJGame *game) : gsGGJShip(game) {
	tag = gsGGJTag::Enemy;
	alpha = 0.3;
	setupSpritesheet();

	hp = INITIAL_ENEMY_HEALTH;
	burstWaitCooldown = ENEMY_INITIAL_WAITING_TIME;
	burstWaitTime = 0;
	cooldown = ENEMY_COOLDOWN_TIME;
	cooldownTime = 0;
	waiting = true;

	gsVector3 size = gsVector3(51, 51, 0);
	gsVector3 speed = gsVector3(gsRandom::nextInt(-50, 50), gsRandom::nextInt(30, 50), 0);
	gsColor color = gsColor::white(alpha);

	transform = gsTransform(transform.position, size, gsVector3::zero(), speed, color);
	collisionMask = 0x01;

	transform.size *= gsGGJGlobal_SizeFactor;
	transform.speed *= gsGGJGlobal_SizeFactor;

	shakeOffset = ENEMY_SHAKE_AMOUNT;
	shaking = false;

	setUpPhase();
}

gsGGJEnemy::~gsGGJEnemy() {
	delete sprite;
	game->removeObjectFromObjectsList(healthBar);
}

void gsGGJEnemy::update() {
	if (alpha < (1.0f - gsGGJGlobal_AvoidChance/100.f)) {
		alpha += gsClock::getDeltaTime()*0.5f;
		transform.tint.a = alpha;
	}
	if (transform.leftTheSceen()) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	if (transform.position.y > GS_RESOLUTION_Y * 0.9f) {
		transform.tint.a = 1.0f - ((transform.position.y - GS_RESOLUTION_Y * 0.9f) / (GS_RESOLUTION_Y * 0.1f));
	}
	
	move();
	burstWaitTime += gsClock::getDeltaTime();
	cooldownTime += gsClock::getDeltaTime();

	if (shaking) {
		shakingTime += gsClock::getDeltaTime();
		shakeOffset *= -1;

		if (shakingTime > ENEMY_SHAKING_TIME) {
			shaking = false;
		}
	}
	
	shootingInteligence();
	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
}
void gsGGJEnemy::draw() {
	sprite->sendToOpenGL_Texture();
	if (shaking) {
		transform.position += shakeOffset;
		gsGraphics::drawQuad(transform);
		transform.position -= shakeOffset;
	} else {
		gsGraphics::drawQuad(transform);
	}
}

void gsGGJEnemy::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsGGJObject *otherCastedToGGJObject = static_cast<gsGGJObject*>(_other);

	if (otherCastedToGGJObject->tag == gsGGJTag::PlayerBullet) {
		gsGGJBullet *other = static_cast<gsGGJBullet*>(_other);
		if (phase != other->phase) {
 			if (!gsRandom::chance(gsGGJGlobal_AvoidChance)) {
				hp -= other->damage;

				if (hp <= 0) {
					game->removeObjectFromObjectsList(this);
					game->addObjetToObjectsList(new gsGGJExplosion(info, transform.tint, game));
					gsGGJGlobal_Points += POINTS_WHEN_ENEMY_DIES + 6 * gsGGJGlobal_UpgradesPurchased;
					gsGGJGlobal_TotalPoints += POINTS_WHEN_ENEMY_DIES + 6 * gsGGJGlobal_UpgradesPurchased;

					//Dropar 
					if(gsRandom::chance(15))
					{
						gsGGJDrop* drop = new gsGGJDrop(game, &transform);
						game->addObjetToObjectsList(drop);
					}
					return;
				}
				shaking = true;
				shakingTime = 0;
				gsGGJGlobal_Points += POINTS_WHEN_BULLET_STRIKES + gsGGJGlobal_UpgradesPurchased;
				gsGGJGlobal_TotalPoints += POINTS_WHEN_BULLET_STRIKES + gsGGJGlobal_UpgradesPurchased;
				game->removeObjectFromObjectsList(other);
				game->addObjetToObjectsList(new gsGGJExplosion(info, transform.tint, game));
			} else {
				other->collident = false;
				other->transform.tint = gsColor(0.3, 0.3, 0.3, 0.5);
			}
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
void gsGGJEnemy::setUpPhase() {
	if (gsGGJGlobal_PhasesAvaiable != 1) {
		gsGGJPhase playerPhase = game->player->phase;
		phase = (gsGGJPhase)gsRandom::nextInt(1, gsGGJGlobal_PhasesAvaiable);
	} else {
		phase = gsGGJPhase::RedPhase;
	}
	setPhaseColor(phase);
}
void gsGGJEnemy::move() {
	transform.applySpeed();
}
void gsGGJEnemy::shootingInteligence() {
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
			if (gsGGJGlobal_Cannons == 1) {
				shoot(0, 0, true);
			} else {
				int count = 0;
				switch (gsGGJGlobal_Cannons) {
					case 2: count = 2; break;
					case 3: count = 3; break;
					case 4: count = 5; break;
					case 5: count = 8; break;
					default: break;
				}

				float margin = CANNONS_INTERBULLET_MARGIN;
				float offset = (margin * (count-1)) / 2.0f;
				for (int i = 0; i < count; i++) {
					shoot(margin * i - offset, -abs(((i - (count-1) / 2.0f) * 8)), (i+1) >= count);
				}
			}
		}
		if (burstWaitTime > burstWaitCooldown) {
			burstWaitCooldown = ENEMY_WAITING_TIME;
			waiting = true;
		}
	}
}
void gsGGJEnemy::shoot(float offsetX, float offsetY, bool lastShoot) {
    gsGGJBullet *bullet = new gsGGJBullet(false, bulletType, &this->transform, game, phase);
	bullet->transform.position.x += offsetX;
	bullet->transform.position.y += offsetY;
	game->addObjetToObjectsList(bullet);
}