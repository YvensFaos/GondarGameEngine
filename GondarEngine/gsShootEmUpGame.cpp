#include "gsShootEmUpGame.h"


#include "gsSystem.h"

#include "gsShootEmUp_Player.h"
#include "gsShootEmUp_EnemySpawner.h"

void gsShootEmUpGame::start() {
	GS_LOG("Shoot 'em Up Game Initialized\n");
	
	player = new gsShootEmUp_Player(this);
	spawner = new gsShootEmUp_EnemySpawner(this);

	addObjetToObjectsList(player);
	addObjetToObjectsList(spawner);
}

void gsShootEmUpGame::end() {
	GS_LOG("Shoot 'em Up Game Ended\n");
	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}
}

bool gsShootEmUpGame::isRunning() {
	//return player->health != 0;
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
			gsGameObject *otbr = objectsToBeRemoved.get(i);
			if (objects.contains(otbr)) { // Evita que o mesmo objeto seja enviado para a remoção duas vezes
				objects.remove(otbr);
			}
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