#include "gsShootEmUp_EnemySpawner.h"


#include "gsSystem.h"
#include "gsShootEmUp_Enemy.h"

#define default_time 1.6f

gsShootEmUp_EnemySpawner::gsShootEmUp_EnemySpawner(gsShootEmUpGame *game) : gsShootEmUpObject(game)
{
	// Atribuir valores iniciais para as variáveis
	spawnCooldown = default_time;
	spawnCooldownTime = 0.6f;

	collident = false;
}

gsShootEmUp_EnemySpawner::~gsShootEmUp_EnemySpawner() {}

void gsShootEmUp_EnemySpawner::update() {
	spawnCooldownTime += gsClock::getDeltaTime();
	if(spawnCooldownTime >= spawnCooldown)
	{
		gsShootEmUp_Enemy* enemy = new gsShootEmUp_Enemy(game);
		game->addObjetToObjectsList(enemy);

		spawnCooldownTime -= spawnCooldown;
	}
}

void gsShootEmUp_EnemySpawner::draw() { }

void gsShootEmUp_EnemySpawner::onCollision(gsGameObject *_other, const gsCollisionInfo& info) { }

#undef default_time
#undef maximum_enemies