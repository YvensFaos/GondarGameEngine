#include "gsGGJDrop.h"

#include "gsSystem.h"
#include "gsGGJGlobals.h"
#include "gsGGJPlayer.h"

gsGGJDrop::gsGGJDrop(gsGGJGame *game, gsTransform* transform) : gsGGJObject(game)
{
	this->transform = *transform;

	int keyCount = 3;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++) {
		keyframes[i] = i;
	}

	sprite = new gsSpriteSheet("GGJ/drop.png", "drop", 1, 3);

	gsAnimationClip *clip = new gsAnimationClip("dropClip", keyframes, keyCount, 0.2f);
	sprite->addAnimation(clip);
	sprite->setAnimation("dropClip");

	this->transform.size = gsVector3(40, 40, 0);
	this->transform.speed.x = 0;
	this->transform.speed.y = 60;
	this->transform.tint = gsColor::white(0.8f);

	solid = false;
}

gsGGJDrop::~gsGGJDrop(void) {
	delete sprite;
}

void gsGGJDrop::update(void)
{
	if (transform.leftTheSceen()) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
	transform.applySpeed();
}

void gsGGJDrop::draw(void)
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJDrop::onCollision(gsGameObject *other, const gsCollisionInfo& info)
{
	gsGGJObject *otherObject = static_cast<gsGGJObject*>(other);

	if (otherObject->tag == gsGGJTag::Player) {
		gsGGJPlayer *player = game->player;

		int pick = gsRandom::nextInt(0, 100);
		if(pick < 20) {
			//Adiciona pontos
			gsGGJGlobal_Points += gsRandom::nextInt(1, 100);
		} else if(pick < 40) {
			player->hp += gsRandom::nextInt(1, 4);
		} else  if(pick < 60) {
			player->bulletType = gsGGJBulletType::Spiral;
			player->cooldown = BULLET_SPIRAL_COOLDOWN;
		} else if (pick < 80) {
			player->bulletType = gsGGJBulletType::Spread;
			player->cooldown = BULLET_SPREAD_COOLDOWN;
		} else {
			player->bulletType = gsGGJBulletType::Normal;
			player->cooldown = BULLET_NORMAL_COOLDOWN;
		}

		gsAudio::play("GGJ\\UpgradeSound.ogg", false, 0.6, 0);
		game->removeObjectFromObjectsList(this);
		return;
	}
}