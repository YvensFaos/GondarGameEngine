#include "gsGGJBullet.h"


#include <math.h>
#include "gsSystem.h"
#include "gsGGJGlobals.h"

gsGGJBullet::gsGGJBullet(bool isPlayerBullet, gsGGJBulletType bulletType, gsTransform* shooterTransform, gsGGJGame *game, gsGGJPhase phase) : gsGGJObject(game) {
	gsVector3 pos = shooterTransform->position;
	gsVector3 size = INITIAL_BULLET_SIZE;
	size.x += shooterTransform->size.x / 2;
	gsVector3 speed = INITIAL_BULLET_SPEED;

	switch (bulletType) {
		case gsGGJBulletType::Normal: damage = BULLET_DAMAGE_NORMAL;
			break;
		case gsGGJBulletType::Spiral: damage = BULLET_DAMAGE_SPIRAL;
			break;
		case gsGGJBulletType::Spread: damage = BULLET_DAMAGE_SPREAD;
			break;
	}

	if (isPlayerBullet) {
		tag = gsGGJTag::PlayerBullet;
		pos.y -= size.y + 64;
		speed *= -1;
		collisionMask = 0x01;
	} else {
		tag = gsGGJTag::EnemyBullet;
		pos.y += shooterTransform->size.y;
		collisionMask = 0x02;
	}
	setUpSprite(isPlayerBullet);

	this->bulletType = bulletType;
	offset = gsVector3::zero();
	angle = 0;

	transform = gsTransform(pos, size, gsVector3::zero(), speed, gsColor::white());

	this->phase = phase;
	if (phase == gsGGJPhase::RedPhase) transform.tint = gsColor::red();
	else if (phase == gsGGJPhase::GreenPhase) transform.tint = gsColor::green();
	else if (phase == gsGGJPhase::BluePhase) transform.tint = gsColor::blue();
	else if (phase == gsGGJPhase::YellowPhase) transform.tint = gsColor::yellow();
	else if (phase == gsGGJPhase::MagentaPhase) transform.tint = gsColor::magenta();

	solid = false;
}
gsGGJBullet::~gsGGJBullet() {
	delete sprite;
}

void gsGGJBullet::update() {
	if (transform.position.x + transform.size.x < 0 || transform.position.x > GS_RESOLUTION_X) {
		game->removeObjectFromObjectsList(this);
		return;
	} else if (transform.position.y + transform.size.y < 0 || transform.position.y > GS_RESOLUTION_Y) {
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
	int raio = 40;
	transform.position -= offset;
	angle += gsClock::getDeltaTime() * 20;
	offset.x = sin(angle) * raio;
	offset.y = cos(angle) * raio * 2 ;
	transform.position += offset;
}

void gsGGJBullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsGGJObject *other = static_cast<gsGGJObject*>(_other);

	if (tag == gsGGJTag::EnemyBullet) {
		if (other->tag == gsGGJTag::Player) {
			game->removeObjectFromObjectsList(this);
			return;
		}
	} 
	if (tag == gsGGJTag::PlayerBullet) {
		if (other->tag == gsGGJTag::Enemy) {
			game->removeObjectFromObjectsList(this);
			return;
		}
	}
}

void gsGGJBullet::setUpSprite(bool isPlayerBullet) {
	int keyCount = 3;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++) {
		keyframes[i] = i;
	}
	if (isPlayerBullet) {
		sprite = new gsSpriteSheet("Shoot/player_bullet.png", "bullet", 1, 3);
	} else {
		sprite = new gsSpriteSheet("Shoot/enemy_bullet.png", "bullet", 1, 3);
	}

	gsAnimationClip *clip = new gsAnimationClip("bulletClip", keyframes, keyCount, 0.2f);
	sprite->addAnimation(clip);
	sprite->setAnimation("bulletClip");
}