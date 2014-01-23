#include "gsDebugGame_TextureLoading.h"

#include "gsLogger.h"
#include "gsClock.h"
#include "gsRandom.h"
#include "gsGraphics.h"
#include "gsOpenGL.h"
#include "gsSpriteSheet.h"

class gsDebugTextureObject : public gsGameObject {
public:
	gsTexture texture;

	gsDebugTextureObject(gsTexture texture) {
		gsVector3 position = gsVector3(
			gsRandom::nextInt(50, 750), 
			gsRandom::nextInt(50, 550), 0);
		gsVector3 size = gsVector3(
			500,
			500, 0);
		gsVector3 speed = gsVector3(
			gsRandom::nextInt(-50, 50), 
			gsRandom::nextInt(-50, 50), 0);
		gsColor color = gsColor::white(0.7f);

		transform = gsTransform(position, size, gsVector3::zero(), speed, color);
		this->texture = texture;
	}

	void update() {
		transform.applySpeed();
		transform.bounceAtScreenEdges();
	}
	
	void draw() {
		texture.sendToOpenGL_Texture();
		gsGraphics::drawQuad(transform);
	}

	void onCollision(gsGameObject *other, const gsCollisionInfo& info) { }
};

class gsDebugSpritesheetObject : public gsGameObject {
public:
	gsSpriteSheet* sprite;
	gsVector3 speed;

	gsDebugSpritesheetObject(const char* spriteFile, const char* spriteName, int vertical, int horizontal) {
		gsVector3 position = gsVector3(
			gsRandom::nextInt(50, 750), 
			gsRandom::nextInt(50, 550),
			0);
		gsVector3 size = gsVector3(
			51,
			51,
			0);
		gsVector3 speed = gsVector3(
			gsRandom::nextInt(-200, 200), 
			gsRandom::nextInt(-200, 200),
			0);
		gsColor color = gsColor::white(1.0f);

		sprite = new gsSpriteSheet(spriteFile, spriteName, vertical, horizontal);
		int keyCount = 4;
		int *keyframes = new int[keyCount];
		for (int i = 0; i < keyCount; i++)
		{
			keyframes[i] = i;
		}
		gsAnimationClip *clip = new gsAnimationClip(spriteName, keyframes, keyCount, 0.4f);
		sprite->addAnimation(clip);
		sprite->setAnimation(spriteName);

		transform = gsTransform(position, size, gsVector3::zero(), speed, color, sprite->getCurrentSprite());
	}

	void update() {
		transform.applySpeed();
		transform.bounceAtScreenEdges();
		sprite->updateAnimation();

		transform.setTextureCoordinates(sprite->getCurrentSprite());
	}
	
	void draw() {
		sprite->sendToOpenGL_Texture();

		gsGraphics::drawQuad(transform);
	}
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) { }
};

void gsDebugGame_TextureLoading::start() {
	GS_LOG("Teste Inicializado\n");

	texture = gsTexture("gondar_texture.jpg", "Gondar");

	objects.add(new gsDebugTextureObject(texture));
	//objects.add(new gsDebugSpritesheetObject("explosion_spritesheet.png", "Explosion", 5, 5));
	//objects.add(new gsDebugSpritesheetObject("scarlet_walk.png", "Scarlett", 2, 10));
	objects.add(new gsDebugSpritesheetObject("Shoot/player_walking.png", "Player", 1, 4));
}

void gsDebugGame_TextureLoading::end() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}

	GS_LOG("Teste Finalizado");
}

bool gsDebugGame_TextureLoading::isRunning() {
	return true;
}

void gsDebugGame_TextureLoading::update() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->update();
	}
}
void gsDebugGame_TextureLoading::draw() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->draw();
	}
}