#include "gsGGJBullet.h"


#include <math.h>
#include "gsSystem.h"
#include "gsGGJGlobals.h"
#include "gsGGJShip.h"
#include "gsGGJExplosion.h"

gsGGJBullet::gsGGJBullet(bool isPlayerBullet, gsGGJBulletType bulletType, gsTransform* shooterTransform, gsGGJGame *game, gsGGJPhase phase) : gsGGJObject(game) {
	gsVector3 pos = shooterTransform->position;
	gsVector3 size = INITIAL_BULLET_SIZE;
	//size.x += shooterTransform->size.x / 2;
	gsVector3 speed = INITIAL_BULLET_SPEED;

	this->bulletType = bulletType;
	switch (bulletType) {
		case gsGGJBulletType::Normal: damage = BULLET_DAMAGE_NORMAL;
			break;
		case gsGGJBulletType::Spiral: damage = BULLET_DAMAGE_SPIRAL;
			offset = gsVector3::zero();
			angle = 0;
			break;
		case gsGGJBulletType::Spread: damage = BULLET_DAMAGE_SPREAD;
			speed.x = gsRandom::nextDouble() * BULLET_SPREAD_CONE;
			speed.y += gsRandom::nextInt(-8, 8);
			size *= (gsRandom::nextDouble() / 2.5f) + 0.6;
			break;
	}

	pos.x += shooterTransform->size.x / 2.0f;
	pos.x -= size.x / 2.0f;
	if (isPlayerBullet) {
		tag = gsGGJTag::PlayerBullet;
		pos.y -= size.y;
		speed *= -1;
		collisionMask = 0x101;
	} else {
		tag = gsGGJTag::EnemyBullet;
		pos.y += shooterTransform->size.y;
		collisionMask = 0x102;
	}
	setUpSprite(isPlayerBullet);

	transform = gsTransform(pos, size, gsVector3::zero(), speed, gsColor::white());

	this->phase = phase;
	setPhaseColor(phase);

	gsVector3 powerFeedback = transform.size * gsGGJGlobal_PowerFactor - transform.size;
	transform.position -= powerFeedback / 2;
	transform.size += powerFeedback;

	solid = false;
	damage *= gsGGJGlobal_PowerFactor;
}
gsGGJBullet::~gsGGJBullet() {
	delete sprite;
}

void gsGGJBullet::update() {
	if (transform.leftTheSceen()) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
	if (bulletType == gsGGJBulletType::Spiral) {
		doSpiral();
	}

	transform.applySpeed();
}
void gsGGJBullet::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJBullet::doSpiral() {
	int raio = BULLET_SPIRAL_RADIUS;
	transform.position -= offset;
	angle += gsClock::getDeltaTime() * BULLET_SPIRAL_FREQUENCY;
	offset.x = sin(angle) * raio;
	offset.y = cos(angle) * raio * 2 ;
	transform.position += offset;
}

void gsGGJBullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsGGJObject *otherObject = static_cast<gsGGJObject*>(_other);

	if (tag == gsGGJTag::EnemyBullet) {
		if (otherObject->tag == gsGGJTag::PlayerBullet) {
			gsGGJBullet *other = static_cast<gsGGJBullet*>(otherObject);
			if (phase != other->phase) {
				if (bulletType == gsGGJBulletType::Spiral) {
					if (gsRandom::chance(35)) { return; } // chance de não ser destruída
				}
				game->removeObjectFromObjectsList(this);
				game->addObjetToObjectsList(new gsGGJExplosion(info, transform.tint, game));
				return;
			}
		}
	} 
	if (tag == gsGGJTag::PlayerBullet) {
		if (otherObject->tag == gsGGJTag::EnemyBullet) {
			gsGGJBullet *other = static_cast<gsGGJBullet*>(otherObject);
			if (phase != other->phase) {
				if (bulletType == gsGGJBulletType::Spiral) {
					if (gsRandom::chance(35)) { return; } // chance de não ser destruída
				}
				game->removeObjectFromObjectsList(this);
				game->addObjetToObjectsList(new gsGGJExplosion(info, transform.tint, game));
				return;
			}
		}
	}
	

	
}

void gsGGJBullet::setUpSprite(bool isPlayerBullet) {
	int keyCount = 3;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++) {
		keyframes[i] = i;
	}

	sprite = new gsSpriteSheet("GGJ/bullet_simple.png", "bullet", 1, 3);

	gsAnimationClip *clip = new gsAnimationClip("bulletClip", keyframes, keyCount, 0.2f);
	sprite->addAnimation(clip);
	sprite->setAnimation("bulletClip");
}