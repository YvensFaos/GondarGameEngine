#include "gsGGJBullet.h"


#include <math.h>
#include "gsSystem.h"
#include "gsGGJGlobals.h"

gsGGJBullet::gsGGJBullet(bool isPlayerBullet, gsGGJBulletType bulletType, gsTransform* shooterTransform, gsGGJGame *game) : gsGGJObject(game) {
	gsVector3 pos = shooterTransform->position;
	gsVector3 size = INITIAL_BULLET_SIZE;
	size.x += shooterTransform->size.x / 2;
	gsVector3 speed = INITIAL_BULLET_SPEED;

	if (isPlayerBullet) {
		tag = gsGGJTag::PlayerBullet;
		speed *= -1;
	} else {
		tag = gsGGJTag::EnemyBullet;
		pos.y += shooterTransform->size.y;
	}
	setUpSprite(isPlayerBullet);

	this->bulletType = bulletType;
	offset = gsVector3::zero();
	angle = 0;

	transform = gsTransform(pos, size, gsVector3::zero(), speed, gsColor::white());

	collisionMask = 0x01;
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
	angle += gsClock::getDeltaTime();
	offset.x = sin(angle * raio);
	offset.y = cos(angle * raio);
	transform.position += offset;
}

void gsGGJBullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {

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