#include "gsGGJDropMessage.h"

#include "gsSystem.h"

gsGGJDropMessage::gsGGJDropMessage(const gsCollisionInfo& collision, gsColor color, gsGGJGame *game, char* texture) : gsGGJObject(game) {
	gsVector3 position = gsVector3::zero();
	for (int i = 0; i < 8; i++)
	{
		position += collision.contactPoints[i];
	}
	position /= 8.0f;
	position += gsVector3(gsRandom::nextDouble() * 8 - 4, gsRandom::nextDouble() * 8 - 4, 0);
	fadeOut = 1.0f;

	gsVector3 size = gsVector3(105, 21, 0);
	gsVector3 growth = size * gsGGJGlobal_PowerFactor - size;
	position -= growth / 2.0f;
	size += growth;

	transform = gsTransform(position, size, gsVector3::zero(), color);

	setupSpritesheet(texture);
}

gsGGJDropMessage::~gsGGJDropMessage(void) {
	delete messageSprite;
}

void gsGGJDropMessage::update() {
	fadeOut -= gsClock::getDeltaTime();
	if (fadeOut <= 0) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	transform.tint.a = fadeOut;

	transform.setTextureCoordinates(messageSprite->getCurrentSprite());
}

void gsGGJDropMessage::draw() {
	messageSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}
	
void gsGGJDropMessage::setupSpritesheet(char* texture) {
	messageSprite = new gsSpriteSheet(texture, "message", 1, 1);

	int keyCount = 1;
	int *keyframes = new int[keyCount];
	for (int i = 0; i < keyCount; i++)
	{
		keyframes[i] = i;
	}
	gsAnimationClip *clip = new gsAnimationClip("message", keyframes, keyCount, 0.4f);
	messageSprite->addAnimation(clip);
	messageSprite->setAnimation("message");
}