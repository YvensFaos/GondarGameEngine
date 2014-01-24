#ifndef __GS_SHOOT_EM_UP__ENEMY_SPAWNER__
#define __GS_SHOOT_EM_UP__ENEMY_SPAWNER__


#include "gsShootEmUpObject.h"

// Objeto invisível que deve de tempos em tempos criar um novo inimigo no topo da tela
class gsShootEmUp_EnemySpawner : public gsShootEmUpObject {
private:
	float spawnCooldownTime;
	float spawnCooldown;

public:
	gsShootEmUp_EnemySpawner() {}
	gsShootEmUp_EnemySpawner(gsShootEmUpGame *game);
	virtual ~gsShootEmUp_EnemySpawner();

	void update();
	void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif