#include "gsDebugGame_Collisions.h"

#ifdef GS_DEBUG

#include "gsSystem.h"


class gsDebugCollisionsObject : public gsGameObject {
public:
	bool hasContatcs;
	gsTransform contacts[8];

	gsDebugCollisionsObject() {
		gsVector3 position = gsVector3(
			gsRandom::nextInt(50, 750), 
			gsRandom::nextInt(50, 550),
			0);
		gsVector3 size = gsVector3(
			gsRandom::nextInt(30, 80), 
			gsRandom::nextInt(30, 80),
			0);
		gsVector3 speed = gsVector3(
			gsRandom::nextInt(-200, 200), 
			gsRandom::nextInt(-200, 200),
			0);
		gsColor color = gsColor::cyan();
		color.a = 0.7f;

		transform = gsTransform(position, size, gsVector3::zero(), speed, color);
	}

	void update() {
		transform.applySpeed();
		transform.bounceAtScreenEdges();
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
		//if(this->isSolid() && this->collident)
			//transform.tint.randomize();



	}
};

void gsDebugGame_Collisions::start() {
	GS_LOG("Teste Inicializado\n");

	for (int i = 0; i < 30; i++)
	{
		objects.add(new gsDebugCollisionsObject());
	}
	gsDebugCollisionsObject *bigGreen = new gsDebugCollisionsObject();
	bigGreen->transform.speed = gsVector3(50, 300, 0);
	bigGreen->transform.size = gsVector3(300, 300, 0);
	bigGreen->transform.tint = gsColor::green();
	bigGreen->transform.tint.a = 0.5f;
	bigGreen->solid = false;

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

#endif