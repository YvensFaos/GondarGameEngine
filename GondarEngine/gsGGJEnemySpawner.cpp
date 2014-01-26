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

	stateMachine = true;
	state = 0;
}

void gsGGJEnemySpawner::update()
{
	spawnTimer += gsClock::getDeltaTime();
	stateTimer += gsClock::getDeltaTime();
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
						  gsGGJFractalis * enemyFractalis = new gsGGJFractalis(game);
						  enemyFractalis->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0, 0);

						  game->addObjetToObjectsList(enemyFractalis);
					  }
			}
			case 1:
			{
					  int generated = gsRandom::nextInt(1, 4);
					  for (int i = 0; i < generated; i++)
					  {
						  gsGGJSlaien * enemySlaien = new gsGGJSlaien(game);
						  enemySlaien->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0, 0);

						  game->addObjetToObjectsList(enemySlaien);
					  }
			}
			case 0: //Jogo começou agora
			{
						int generated = gsRandom::nextInt(1, 3);
						for (int i = 0; i < generated; i++)
						{
							gsGGJSimlen *enemySimlen = new gsGGJSimlen(game);
							enemySimlen->transform.position = gsVector3(gsRandom::nextInt(0, 800), 0, 0);

							game->addObjetToObjectsList(enemySimlen);
						}
						spawnTimer -= spawnCooldown;

						if (stateTimer >= 3.f && state == 0)
						{
							state = 1; 
							stateTimer = 0.f;
						}
						if (stateTimer >= 15.f && state == 1)
						{
							state = 2;
							stateTimer = 0.f;
						}
			}
				break;

			default:
				break;
			}
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