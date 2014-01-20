#include "gsDebugGame_TextureLoading.h"

#include "gsLogger.h"
#include "gsClock.h"
#include "gsRandom.h"
#include "gsCollision.h"
#include "gsCollisionInfo.h"
#include "gsGraphics.h"
#include "gsOpenGL.h"

class gsDebugObjecty : public gsGameObject {
public:
	gsVector3 speed;
	bool hasContatcs;
	gsTransform contacts[8];
	gsTexture texture;

	gsDebugObjecty(gsTexture texture) {
		gsVector3 position = gsVector3(
			gsRandom::nextInt(50, 750), 
			gsRandom::nextInt(50, 550),
			0);
		gsVector3 size = gsVector3(
			gsRandom::nextInt(30, 80), 
			gsRandom::nextInt(30, 80),
			0);
		speed = gsVector3(
			gsRandom::nextInt(-200, 200), 
			gsRandom::nextInt(-200, 200),
			0);
		gsColor color = gsColor::white();
		color.a = 0.7f;

		transform = gsTransform(position, size, gsVector3::zero(), color);
		this->texture = texture;

		//GS_LOG("entrando no construtor certo!");
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

		//GS_LOG("entrando no draw certo!\n");
	}
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) { }
};

void gsDebugGame_TextureLoading::start() {
	texture = *new gsTexture("gondar_texture.jpg");

	GS_LOG("Teste Inicializado\n");

	objects.add(new gsDebugObjecty(texture));
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
	//GS_LOG("q");
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->update();
	}
}
void gsDebugGame_TextureLoading::draw() {
	//GS_LOG("q");
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->draw();
	}
}