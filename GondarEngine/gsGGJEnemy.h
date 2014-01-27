#ifndef __GS_GGJ_ENEMY__
#define __GS_GGJ_ENEMY__


#include "gsGGJShip.h"
#include "gsSpriteSheet.h"

class gsGGJEnemy : public gsGGJShip {

public:
	float alpha;
	float burstWaitCooldown;
	float burstWaitTime;
	bool waiting;
	bool acelerated;
	float acelerate;

	gsGGJEnemy() {}
	gsGGJEnemy(gsGGJGame *game);
	virtual ~gsGGJEnemy();

	virtual void update();
	virtual void draw();

	virtual void onCollision(gsGameObject *_other, const gsCollisionInfo& info);

	virtual void setupSpritesheet();
	void setUpPhase();
	
	virtual void move();
	virtual void shoot(float offsetX, float offsetY, bool lastShoot);
};

#endif