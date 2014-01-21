#include "gsDebugGame_TextureLoading.h"

#include "gsLogger.h"
#include "gsClock.h"
#include "gsRandom.h"
#include "gsGraphics.h"
#include "gsOpenGL.h"
#include "gsSpriteSheet.h"

class gsDebugTexture : public gsGameObject {
public:
	gsVector3 speed;
	bool hasContatcs;
	gsTexture texture;

	gsDebugTexture(gsTexture texture) {
		gsVector3 position = gsVector3(
			gsRandom::nextInt(50, 750), 
			gsRandom::nextInt(50, 550),
			0);
		gsVector3 size = gsVector3(
			620,
			620,
			0);
		speed = gsVector3(
			gsRandom::nextInt(-200, 200), 
			gsRandom::nextInt(-200, 200),
			0);
		gsColor color = gsColor::white();
		color.a = 0.7f;

		transform = gsTransform(position, size, gsVector3::zero(), color);
		this->texture = texture;
	}

	void update() {
		transform.position += speed * gsClock::getDeltaTime();

		if (transform.position.x < 0) {
			transform.position.x = 1;
			speed.x *= -1;
		} else if (transform.position.x + transform.size.x > 800) {
			transform.position.x = 799 - transform.size.x;
			speed.x *= -1;
		}

		if (transform.position.y < 0) {
			transform.position.y = 1;
			speed.y *= -1;
		} else if (transform.position.y + transform.size.y > 600) {
			transform.position.y = 599 - transform.size.y;
			speed.y *= -1;
		}
	}
	
	void draw() {
		texture.sendToOpenGL();
		gsGraphics::drawQuad(transform);
	}
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) { }
};

class gsDebugSpritesheet : public gsGameObject 
{
public:
	int spritePos;

	gsVector3 speed;
	gsSpriteSheet sprite;

	gsDebugSpritesheet(const char* spriteFile, int vertical, int horizontal) {
		gsVector3 position = gsVector3(
			gsRandom::nextInt(50, 750), 
			gsRandom::nextInt(50, 550),
			0);
		gsVector3 size = gsVector3(
			64,
			64,
			0);
		speed = gsVector3(
			gsRandom::nextInt(-200, 200), 
			gsRandom::nextInt(-200, 200),
			0);
		gsColor color = gsColor::white();
		color.a = 0.4f;

		spritePos = 0;

		sprite = gsSpriteSheet(spriteFile, vertical, horizontal);

		transform = gsTransform(position, size, gsVector3::zero(), color, sprite.getSpritePos(spritePos));
	}

	void update() {
		transform.position += speed * gsClock::getDeltaTime();

		if (transform.position.x < 0) {
			transform.position.x = 1;
			speed.x *= -1;
		} else if (transform.position.x + transform.size.x > 800) {
			transform.position.x = 799 - transform.size.x;
			speed.x *= -1;
		}

		if (transform.position.y < 0) {
			transform.position.y = 1;
			speed.y *= -1;
		} else if (transform.position.y + transform.size.y > 600) {
			transform.position.y = 599 - transform.size.y;
			speed.y *= -1;
		}

		spritePos += 4;
		if(spritePos >= sprite.count())
		{
			spritePos = 0;
		}
		//GS_LOG(spritePos);
		transform.setTextureCoordinates(sprite.getSpritePos(spritePos));
	}
	
	void draw() {
		sprite.sendToOpenGL();

		gsGraphics::drawQuad(transform);
	}
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) { }
};

void gsDebugGame_TextureLoading::start() {
	texture = *new gsTexture("gondar_texture.jpg");

	GS_LOG("Teste Inicializado\n");

	objects.add(new gsDebugTexture(texture));

	objects.add(new gsDebugSpritesheet("explosion_spritesheet.png", 5, 5));
}

void gsDebugGame_TextureLoading::end() {
	GS_LOG("Teste Finalizado");

	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}
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