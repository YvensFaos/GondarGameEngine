#include "gsGGJEnemySpawner.h"
#include "gsGGJGlobals.h"
#include "gsClock.h"
#include "gsGGJEnemy.h"
#include "gsRandom.h"

#include "gsGGJSimlen.h"
#include "gsGGJSlaien.h"
#include "gsGGJFractalis.h"

gsGGJEnemySpawner::gsGGJEnemySpawner(gsGGJGame *game) : gsGGJObject(game)
{
	spawnCooldown = ENEMY_SPAWNER_COOLDOWN;
	spawnTimer = ENEMY_SPAWNER_TIMER;
	slaienTimer = 20.f;
	fractalisTimer = 50.f;

	stateMachine = false;
	state = 0;
}

void gsGGJEnemySpawner::update()
{
	spawnTimer += gsClock::getDeltaTime();
	if(stateMachine)
	{
		switch(state)
		{
		case 0: //Jogo começou agora
			//int generated = gsRandom::nextInt(1,3);

			break;

		default:
			break;
		}
	}
	else
	{
		if (spawnTimer >= spawnCooldown)
		{
			gsGGJSimlen *enemySimlen = new gsGGJSimlen(game);
			gsGGJSlaien *enemySlaien = new gsGGJSlaien(game);
			gsGGJFractalis *enemyFractalis = new gsGGJFractalis(game);

			enemySimlen->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0,0);
			enemySlaien->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0,0);
			enemyFractalis->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0,0);
		

			game->addObjetToObjectsList(enemySimlen);
			game->addObjetToObjectsList(enemySlaien);
			game->addObjetToObjectsList(enemyFractalis);

			spawnTimer -= spawnCooldown;
		}
	}
}

void gsGGJEnemySpawner::draw(){}

void gsGGJEnemySpawner::onCollision(gsGameObject *_other, const gsCollisionInfo& info){}