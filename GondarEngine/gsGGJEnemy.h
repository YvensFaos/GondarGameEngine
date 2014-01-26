#ifndef __GS_GGJ_ENEMY__
#define __GS_GGJ_ENEMY__


#include "gsGGJShip.h"
#include "gsSpriteSheet.h"

class gsGGJEnemy : public gsGGJShip {

public:

	float burstWaitCooldown;
	float burstWaitTime;
	bool waiting;
	float hp;

	gsGGJEnemy() {}
	gsGGJEnemy(gsGGJGame *game);
	virtual ~gsGGJEnemy();

	virtual void update();
	virtual void draw();

	virtual void onCollision(gsGameObject *_other, const gsCollisionInfo& info);

	virtual void setupSpritesheet();
	virtual void move();
	virtual void shoot();
};

#endif