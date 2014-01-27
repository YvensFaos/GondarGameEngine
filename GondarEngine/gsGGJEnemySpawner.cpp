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
	stateTimer = 0;
	simlienFleetTimer = 0;

	stateMachine = true;
	state = 0;

	maxSimlien = 1;
}

void gsGGJEnemySpawner::update()
{
	spawnTimer += gsClock::getDeltaTime();
	stateTimer += gsClock::getDeltaTime();
	simlienFleetTimer += gsClock::getDeltaTime();

	if(stateMachine)
	{
		if (spawnTimer >= spawnCooldown)
		{
			switch (state)
			{
			case 2:
			{
				int generated = gsRandom::nextInt(1, 6);
				for (int i = 0; i < generated; i++)
				{
					gsGGJFractalis *enemyFractalis = new gsGGJFractalis(game);
					enemyFractalis->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0, 0);

					game->addObjetToObjectsList(enemyFractalis);
				}
			}
			case 1:
			{
				int generated = gsRandom::nextInt(1, 4);
				for (int i = 0; i < generated; i++)
				{
					gsGGJSlaien *enemySlaien = new gsGGJSlaien(game);
					enemySlaien->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0, 0);

					game->addObjetToObjectsList(enemySlaien);
				}
			}
			case 0: //Jogo começou agora
			{
				int generated = gsRandom::nextInt(1, maxSimlien);
				for (int i = 0; i < generated; i++)
				{
					gsGGJSimlen *enemySimlen = new gsGGJSimlen(game);
					enemySimlen->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0, 0);

					game->addObjetToObjectsList(enemySimlen);
				}
				spawnTimer -= spawnCooldown;

				if (stateTimer >= (8.f + (maxSimlien - 1)) && maxSimlien < 5)
				{
					maxSimlien++;
				}
				if (stateTimer >= 30.f && state == 0)
				{
					state = 1; 
					stateTimer = 0.f;
				}
				if (stateTimer >= 65.f && state == 1)
				{
					state = 2;
					stateTimer = 0.f;
				}

				
			} break;
			default:
				break;
			}
		}

		if (simlienFleetTimer >= 18.f && maxSimlien > 3)
		{
			GS_LOG(simlienFleetTimer);
			simlienFleetTimer = 0;
			summonSimlienFleet(gsRandom::chance(50));
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

void gsGGJEnemySpawner::summonSimlienFleet(bool left)
{
	float mainAxis = 0.f;
	if(left)
	{
		mainAxis = gsRandom::nextInt(20, 200);
	}
	else
	{
		mainAxis = gsRandom::nextInt(60, 780);
	}

	float factor = (left)? 1 : -1;

	//GS_LOG("FLEET!");

	for(int i = 0; i < 3; i++)
	{
		gsGGJSimlen *enemySimlen = new gsGGJSimlen(game);
		enemySimlen->transform.position = gsVector3((mainAxis + (i*50)*factor), 10,0);
		enemySimlen->transform.speed = gsVector3(60, 0, 0);

		game->addObjetToObjectsList(enemySimlen);
	}
}

void gsGGJEnemySpawner::draw(){}

void gsGGJEnemySpawner::onCollision(gsGameObject *_other, const gsCollisionInfo& info){}