#include "gsDebugGame_Collisions.h"

#include "gsLogger.h"
#include "gsClock.h"
#include "gsRandom.h"
#include "gsCollision.h"
#include "gsCollisionInfo.h"
#include "gsGraphics.h"
#include "gsOpenGL.h"


class gsDebugObject : public gsGameObject {
public:
	gsVector3 speed;
	bool hasContatcs;
	gsTransform contacts[8];

	gsDebugObject() {
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
		gsColor color = gsColor::cyan();
		color.a = 0.7f;

		transform = gsTransform(position, size, gsVector3::zero(), color);
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
		gsGraphics::drawQuad(transform);

		if (hasContatcs) {
			for (int i = 0; i < 8; i++)
			{
				gsGraphics::drawQuad(contacts[i]);
			}
		}
		hasContatcs = false;
	}

	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {
		hasContatcs = true;

		gsVector3 pointSize = gsVector3(8, 8, 0);
		gsVector3 position;
		for (int i = 0; i < 8; i++)
		{
			position = info.contactPoints[i] - pointSize/2;
			gsTransform pointTransform = gsTransform(position, pointSize, gsVector3::zero(), gsColor::red());
			contacts[i] = pointTransform;
		}
	}
};

void gsDebugGame_Collisions::start() {
	GS_LOG("Teste Inicializado\n");
	for (int i = 0; i < 30; i++)
	{
		objects.add(new gsDebugObject());
	}
	gsDebugObject *bigGreen = new gsDebugObject();
	bigGreen->transform.size = gsVector3(300, 300, 0);
	bigGreen->transform.tint = gsColor::green();
	bigGreen->transform.tint.a = 0.5f;
	bigGreen->solid = false;
	bigGreen->speed = gsVector3(50, 300, 0);

	objects.add(bigGreen);
	
}
void gsDebugGame_Collisions::end() {
	GS_LOG("Teste Finalizado");
	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}
}

bool gsDebugGame_Collisions::isRunning() {
	return true;
}

void gsDebugGame_Collisions::update() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->update();
	}
	gsCollision::detectCollisions(&objects);
}
void gsDebugGame_Collisions::draw() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->draw();
	}
}