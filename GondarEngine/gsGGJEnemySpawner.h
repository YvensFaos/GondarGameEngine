#ifndef __GS_GGJ_ENEMY_SPAWNER__
#define __GS_GGJ_ENEMY_SPAWNER__


#include "gsGGJObject.h"


// Objeto invisível que deve de tempos em tempos criar um novo inimigo no topo da tela
class gsGGJEnemySpawner : public gsGGJObject {
private:
	float spawnCooldown;
	float spawnTimer;

	float simlienFleetTimer;

	int maxSimlien;
	int maxSlaien;
	int maxFractalis;

	float slaienTimer;
	float fractalisTimer;

	float stateTimer;
	bool stateMachine;
	int state;

public:
	gsGGJEnemySpawner() {}
	gsGGJEnemySpawner(gsGGJGame *game);
	virtual ~gsGGJEnemySpawner(){}

	void update();
	void draw();

	void summonSimlienFleet(bool left);

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif