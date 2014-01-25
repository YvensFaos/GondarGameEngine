#include "gsSystem.h"

#include "gsGGJGame.h"

#include "gsGGJPlayer.h"

void gsGGJGame::start()
{
	GS_LOG("GS Shoot 'em Up Game Initialized\n");
	gsAudio::play("Audio\\dota2.mp3", false, 1, 0);

	gsGGJPlayer *player = new gsGGJPlayer(this);

	addObjetToObjectsList(player);
}

bool gsGGJGame::isRunning()
{
	return true;
}

void gsGGJGame::update()
{
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
				delete otbr;
			}
		}
		objectsToBeRemoved.clear();
	}
}

void gsGGJGame::draw()
{
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->draw();
	}
}

void gsGGJGame::end()
{
	GS_LOG("Shoot 'em Up Game Ended\n");
	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}
}

void gsGGJGame::addObjetToObjectsList(gsGameObject* object) {
	objects.add(object);
}

void gsGGJGame::removeObjectFromObjectsList(gsGameObject *object) {
	objectsToBeRemoved.add(object);
}