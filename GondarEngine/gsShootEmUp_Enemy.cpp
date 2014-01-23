#include "gsShootEmUp_Enemy.h"


#include "gsSystem.h"

#include "gsShootEmUp_Bullet.h"
#include "gsShootEmUpObjectTag.h"

#define default_hp 10
#define default_damage 1
#define default_cooldown 0.4f

gsShootEmUp_Enemy::gsShootEmUp_Enemy(gsShootEmUpGame *game) : gsShootEmUpObject(game) {
	tag = gsShootEmUpObjectTag::Enemy;

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

	hp = default_hp;
	damage = default_damage;
	swapowCooldown = default_cooldown;
	weapowCooldownTime = 0;

	gsVector3 position = gsVector3(
		gsRandom::nextInt(60, 740), 
		-51, 
		0);
	gsVector3 size = gsVector3(
		51,
		51, 
		0);
	gsVector3 speed = gsVector3(
		gsRandom::nextInt(-50, 50), 
		gsRandom::nextInt(30, 50), 
		0);
	gsColor color = gsColor::white(1.f);

	transform = gsTransform(position, size, gsVector3::zero(), speed, color);

	collisionMask = 0x01;
}
gsShootEmUp_Enemy::~gsShootEmUp_Enemy() {
	delete sprite;
}

void gsShootEmUp_Enemy::update() {
	transform.applySpeed();
	sprite->updateAnimation();

	transform.setTextureCoordinates(sprite->getCurrentSprite());

	if(hp == default_hp / 2.f)
	{
		sprite = new gsSpriteSheet("Shoot/enemy_walking_broken.png", "enemy", 1, 4);
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
	else
	{
		if(hp <= 0)
		{
			game->removeObjectFromObjectsList(this);
			return;
		}
	}

	if (transform.position.y > GS_RESOLUTION_Y) {
		game->removeObjectFromObjectsList(this);
	}

	weapowCooldownTime += gsClock::getDeltaTime();
	if(weapowCooldownTime >= swapowCooldown)
	{
		weapowCooldownTime -= swapowCooldown;

		gsShootEmUp_Bullet* bullet = new gsShootEmUp_Bullet(false, this, game, gsVector3(gsRandom::nextInt(-20, 20), 200, 0));
		bullet->setDamage(damage);
		game->addObjetToObjectsList(bullet);
	}
}

void gsShootEmUp_Enemy::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsShootEmUp_Enemy::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *otherAsSEUObject = static_cast<gsShootEmUpObject*>(_other);

	if(otherAsSEUObject->tag == gsShootEmUpObjectTag::PlayerBullet)
	{
		gsShootEmUp_Bullet *other = static_cast<gsShootEmUp_Bullet*>(_other);
		hp -= other->damage;
	}
}

#undef default_hp
#undef default_damage
#undef default_cooldown