#include "gsGGJEnemySpawner.h"
#include "gsGGJGlobals.h"
#include "gsClock.h"
#include "gsGGJEnemy.h"
#include "gsRandom.h"

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
		gsGGJEnemy *enemy = new gsGGJEnemy(game);
		enemy->transform.position.x = gsRandom::nextInt(0, 800);
		enemy->transform.position.y = 0;
		enemy->transform.position.z = 0;

		game->addObjetToObjectsList(enemy);

		spawnTimer -= spawnCooldown;
	}
}

void gsGGJEnemySpawner::draw(){}

void gsGGJEnemySpawner::onCollision(gsGameObject *_other, const gsCollisionInfo& info){}