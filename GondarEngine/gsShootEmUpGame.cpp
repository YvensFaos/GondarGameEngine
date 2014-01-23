#include "gsShootEmUpGame.h"

#include "gsCollision.h"
#include "gsLogger.h"
#include "gsInput.h"
#include "gsGraphics.h"
#include "gsOpenGL.h"

#include "gsShootEmUp_Player.h"


void gsShootEmUpGame::start() {
	GS_LOG("Shoot 'em Up Game Initialized\n");
	
	gsShootEmUp_Player* player = new gsShootEmUp_Player(this);
	objects.add(player);

	// Criar um player

	// Criar um enemy spawner
}
void gsShootEmUpGame::end() {
	GS_LOG("Shoot 'em Up Game Ended\n");
	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}
}

bool gsShootEmUpGame::isRunning() {
	return true;
}

void gsShootEmUpGame::update() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->update();
	}

	gsCollision::detectCollisions(&objects);

	if (objectsToBeRemoved.getSize() != 0) {
		for (int i = 0; i < objectsToBeRemoved.getSize(); i++)
		{
			objects.remove(objectsToBeRemoved.get(i));
		}
		objectsToBeRemoved.clear();
	}
}
void gsShootEmUpGame::draw() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->draw();
	}
}

void gsShootEmUpGame::addObjetToObjectsList(gsGameObject* object) {
	objects.add(object);
}
void gsShootEmUpGame::removeObjectFromObjectsList(gsGameObject *object) {
	objectsToBeRemoved.add(object);
}