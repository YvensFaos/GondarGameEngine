#include "gsGGJDrop.h"

#include "gsSystem.h"
#include "gsGGJGlobals.h"

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