#ifndef __GS_GGJ_ENEMY__
#define __GS_GGJ_ENEMY__


#include "gsGGJShip.h"
#include "gsSpriteSheet.h"

class gsGGJEnemy : public gsGGJShip {
private:
	float weaponBurstCooldown;
	float weaponBurstTimer;

public:
	gsGGJEnemy() {}
	gsGGJEnemy(gsGGJGame *game);
	virtual ~gsGGJEnemy();

	void update();
	void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif