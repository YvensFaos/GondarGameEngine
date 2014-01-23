#include "gsShootEmUp_Enemy.h"

#include "gsClock.h"
#include "gsRandom.h"
#include "gsGraphics.h"
#include "gsShootEmUpObject.h"
#include "gsShootEmUp_Bullet.h"
#include "gsShootEmUpObjectTag.h"

#define default_hp 10
#define default_damage 1
#define default_cooldown 0.4f

gsShootEmUp_Enemy::gsShootEmUp_Enemy(gsShootEmUpGame *game) {
	// Carregar sprite do inimigo
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
		gsRandom::nextInt(60, 700), 
		gsRandom::nextInt(400, 550), 
		0);
	gsVector3 size = gsVector3(
		51,
		51, 
		0);
	gsVector3 speed = gsVector3(
		gsRandom::nextInt(-50, 50), 
		gsRandom::nextInt(-50, 50), 
		0);
	gsColor color = gsColor::white(1.f);

	transform = gsTransform(position, size, gsVector3::zero(), speed, color);

	tag = gsShootEmUpObjectTag::Enemy;
}

gsShootEmUp_Enemy::~gsShootEmUp_Enemy() {
	delete sprite;
}

void gsShootEmUp_Enemy::update() {
	transform.applySpeed();
	transform.bounceAtScreenEdges();
	sprite->updateAnimation();

	transform.setTextureCoordinates(sprite->getCurrentSprite());

	if(hp = default_hp / 2.f)
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

	weapowCooldownTime += gsClock::getDeltaTime();
	if(weapowCooldownTime >= swapowCooldown)
	{
		weapowCooldownTime -= swapowCooldown;

		gsShootEmUp_Bullet* bullet = new gsShootEmUp_Bullet(false, this, game, gsVector3(0, -10, 0));
		//adicionar o damage do enemy na bullet
		//game->addObjetToObjectsList(bullet);
	}
}

void gsShootEmUp_Enemy::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsShootEmUp_Enemy::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *other = static_cast<gsShootEmUpObject*>(_other);

	// utilizar a tag para descobrir com que tipo de objeto colidiu.
	// fazer outro cast
	// deduzir do HP o damage recebido
	if(other->tag == gsShootEmUpObjectTag::PlayerBullet)
	{
		hp -= 2;
	}
}

#undef default_hp
#undef default_damage
#undef default_cooldown