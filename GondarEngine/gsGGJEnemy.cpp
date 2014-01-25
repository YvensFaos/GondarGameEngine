#include "gsGGJEnemy.h"


#include "gsSystem.h"
#include "gsGGJBullet.h"


gsGGJEnemy::gsGGJEnemy(gsGGJGame *game) : gsGGJShip(game) {
	tag = gsGGJTag::Enemy;

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

	weaponBurstCooldown = 0.4f;
	weaponBurstTimer = 0;

	gsVector3 size = gsVector3(
		51,
		51,
		0);
	gsVector3 speed = gsVector3(
		gsRandom::nextInt(-50, 50),
		gsRandom::nextInt(30, 50),
		0);
	gsColor color = gsColor::white(1.f);

	transform = gsTransform(transform.position, size, gsVector3::zero(), speed, color);

	collisionMask = 0x01;

	hp = INITIAL_ENEMY_HEALTH;

}
gsGGJEnemy::~gsGGJEnemy() {
	//delete sprite;
}

void gsGGJEnemy::update() {
	transform.applySpeed();
	sprite->updateAnimation();

	transform.setTextureCoordinates(sprite->getCurrentSprite());

	if (hp == INITIAL_ENEMY_HEALTH / 2.f)
	{
		sprite = new gsSpriteSheet("Shoot/enemy_walking_broken.png", "enemy", 1, 4);
		int keyCount = 4;
		int *keyframes = new int[keyCount];
		for (int i = 0; i < keyCount; i++)
		{
			keyframes[i] = i;
		}
		gsAnimationClip *clip = new gsAnimationClip("damagedEnemyClip", keyframes, keyCount, 0.4f);
		sprite->addAnimation(clip);
		sprite->setAnimation("damagedEnemyClip");
	}
	else
	{
		if (hp <= 0)
		{
			game->removeObjectFromObjectsList(this);
			return;
		}
	}

	if (transform.leftTheSceen()) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	// Logica de atualização do inimigo
}
void gsGGJEnemy::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJEnemy::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsGGJObject *otherCastedToGGJObject = static_cast<gsGGJObject*>(_other);

	if (otherCastedToGGJObject->tag == gsGGJTag::PlayerBullet)
	{
		gsGGJBullet *other = static_cast<gsGGJBullet*>(_other);
		hp -= other->damage;
	}
}