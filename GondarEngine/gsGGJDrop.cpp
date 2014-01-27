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

	transform->speed.x = 0;
	transform->speed.y = -10;
	transform->tint = gsColor::white(0.8f);

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

		if(gsRandom::chance(50))
		{
			//Adiciona pontos
			gsGGJGlobal_Points += gsRandom::nextInt(1, 100);
		}
		else
		{
			if(gsRandom::chance(50))
			{
				//Ganha vida
				player->hp += gsRandom::nextInt(1, 4);
			}
			else
			{
				if(gsRandom::chance(70))
				{
					player->bulletType = gsGGJBulletType::Spiral;
				}
				else
				{
					player->bulletType = gsGGJBulletType::Spread;
				}
			}
		}

		gsAudio::play("GGJ\\UpgradeSound.ogg", false, 100, 0);
		game->removeObjectFromObjectsList(this);
		return;
	}
}