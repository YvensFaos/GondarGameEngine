#include "gsShootEmUp_EnemySpawner.h"

#include "gsClock.h"
#include "gsShootEmUp_Enemy.h"

#define default_time 0.6f
#define maximum_enemies 5

gsShootEmUp_EnemySpawner::gsShootEmUp_EnemySpawner(gsShootEmUpGame *game) : gsShootEmUpObject(game)
{
	// Atribuir valores iniciais para as variáveis
	spawnCooldown = default_time;
	spawnCooldownTime = 0.6f;
	enemyCount = 0;

	collident = false;
}

gsShootEmUp_EnemySpawner::~gsShootEmUp_EnemySpawner() {}

void gsShootEmUp_EnemySpawner::update() {
	// Se estiver fora do cooldown, crie um inimigo
	if(enemyCount < maximum_enemies)
	{
		if(spawnCooldownTime >= spawnCooldown)
		{
			spawnCooldownTime = 0;

			GS_LOG("Incluir inimigo");
			gsShootEmUp_Enemy* enemy = new gsShootEmUp_Enemy(game);
			game->addObjetToObjectsList(enemy);

			enemyCount++;
			spawnCooldown += 0.5f;
		}

		spawnCooldownTime += gsClock::getDeltaTime();
	}
}

void gsShootEmUp_EnemySpawner::draw() { }

void gsShootEmUp_EnemySpawner::onCollision(gsGameObject *_other, const gsCollisionInfo& info) { }

#undef default_time
#undef maximum_enemies