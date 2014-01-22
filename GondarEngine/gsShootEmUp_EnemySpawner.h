#ifndef __GS_SHOOT_EM_UP__ENEMY_SPAWNER__
#define __GS_SHOOT_EM_UP__ENEMY_SPAWNER__


#include "gsShootEmUpObject.h"

class gsShootEmUp_EnemySpawner : public gsShootEmUpObject {
private:
	float spawnCooldownTime;
	float spawnCooldown;
	
public:
	gsShootEmUp_EnemySpawner() {}
	gsShootEmUp_EnemySpawner(gsShootEmUpGame *game);

	void update();
	void draw();

	void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif