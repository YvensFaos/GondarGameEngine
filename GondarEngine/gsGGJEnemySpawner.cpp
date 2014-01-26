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
}

void gsGGJEnemySpawner::update()
{
	spawnTimer += gsClock::getDeltaTime();
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

void gsGGJEnemySpawner::draw(){}

void gsGGJEnemySpawner::onCollision(gsGameObject *_other, const gsCollisionInfo& info){}