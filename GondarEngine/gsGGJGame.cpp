#include "gsGGJGame.h"

#include "gsSystem.h"
#include "gsGGJPlayer.h"
#include "gsGGJShop.h"
#include "gsGGJPanorama.h"
#include "gsGGJEnemySpawner.h"
#include "gsGGJScore.h"
#include "gsGGJLifes.h"
#include "gsGGJTutorial.h"
#include "gsGGJGlobals.h"
#include "gsGGJGameOver.h"

void gsGGJGame::start()
{
	GS_LOG("GS Shoot 'em Up Game Initialized\n");
	gsGGJGlobal_PowerFactor = INITIAL_POWER_FACTOR;
	gsGGJGlobal_SizeFactor = INITIAL_SIZE_FACTOR;
	gsGGJGlobal_SpeedFactor = INITIAL_SPEED_FACTOR;
	gsGGJGlobal_AvoidChance = INITIAL_AVOID_CHANCE;
	gsGGJGlobal_Cannons = INITIAL_CANNONS;
	gsGGJGlobal_PhasesAvaiable = INITIAL_PHASES_AVAIABLE;
	gsGGJGlobal_BulletType = INITIAL_BULLET_TYPE;
	gsGGJGlobal_Lifes = INITIAL_LIVES;
	gsGGJGlobal_Points = 0;
	gsGGJGlobal_TotalPoints = 0;
	startGame = false;
	restartGame = false;

	gsAudio::play("GGJ\\ShipSong Final Ogg.ogg", true, 1.0f, 0);

	addObjetToObjectsList(new gsGGJPanorama(this));
	this->player = new gsGGJPlayer(this);
	addObjetToObjectsList(player);
	this->scoreDisplay = new gsGGJScore(this);
	addObjetToObjectsList(scoreDisplay);
	this->lifesDisplay = new gsGGJLifes(this);
	addObjetToObjectsList(lifesDisplay);
	addObjetToObjectsList(new gsGGJEnemySpawner(this));
	addObjetToObjectsList(new gsGGJShop(this));
	addObjetToObjectsList(new gsGGJTutorial(this));
	scoreDisplay->setScore(gsGGJGlobal_Points);

	scoreDisplay->transform.position = POINTS_POSITION;
	lifesDisplay->transform.position = LIFES_POSITION;
}

bool gsGGJGame::isRunning()
{
	if(restartGame)
	{
		end();
		start();
	}
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

	if (gsInput::queryKey(GLFW_KEY_V) == gsKeyState::JustPressed)
	{
		GS_LOG("Objects: " << objects.getCapacity() << "Remove" << objectsToBeRemoved.getCapacity());
	}

	if(gsGGJGlobal_Lifes >= 0)
	{
		scoreDisplay->setScore(gsGGJGlobal_Points);
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
	objects.clear();
}

void gsGGJGame::addObjetToObjectsList(gsGameObject* object) {
	objects.add(object);
}

void gsGGJGame::removeObjectFromObjectsList(gsGameObject *object) {
	objectsToBeRemoved.add(object);
}