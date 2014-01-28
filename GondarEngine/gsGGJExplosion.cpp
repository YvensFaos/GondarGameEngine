#include "gsGGJExplosion.h"


#include "gsSystem.h"

gsGGJExplosion::gsGGJExplosion(const gsCollisionInfo& collision, gsColor color, gsGGJGame *game) : gsGGJObject(game) {
	gsVector3 position = gsVector3::zero();
	for (int i = 0; i < 8; i++)
	{
		position += collision.contactPoints[i];
	}
	position /= 8.0f;
	position += collision.penetration * 10;
	position += gsVector3(
		gsRandom::nextDouble() * 8 - 4,  
		gsRandom::nextDouble() * 8 - 4, 0);
	fadeOut = 1.0f;

	transform = gsTransform(position, gsVector3(30, 30, 0), gsVector3::zero(), color);
	setupSpritesheet();
}
gsGGJExplosion::~gsGGJExplosion(void) {
	delete explosionSprite;
}

void gsGGJExplosion::update() {
	fadeOut -= gsClock::getDeltaTime();
	if (fadeOut <= 0) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	transform.tint.a = fadeOut;

	explosionSprite->updateAnimation();
	transform.setTextureCoordinates(explosionSprite->getCurrentSprite());
}
void gsGGJExplosion::draw() {
	explosionSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}
	
void gsGGJExplosion::setupSpritesheet() {
	int keyCount = 5;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++) {
		keyframes[i] = i;
	}

	explosionSprite = new gsSpriteSheet("GGJ/explosion.png", "explosion", 1, keyCount);

	gsAnimationClip *clip = new gsAnimationClip("explosion", keyframes, keyCount, 0.2f);
	explosionSprite->addAnimation(clip);
	explosionSprite->setAnimation("explosion");
}