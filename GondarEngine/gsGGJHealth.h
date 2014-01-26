#ifndef __GS_HEALTH_PANORAMA__
#define __GS_HEALTH_PANORAMA__

#include "gsGGJObject.h"

class gsGGJShip;
class gsSpriteSheet;

class gsGGJHealth : public gsGGJObject {
public:
	gsGGJShip* target;
	gsSpriteSheet *sprite;
	float acelerateCounter;

	gsGGJHealth(void) {}
	gsGGJHealth(gsGGJGame *game, gsGGJShip *target);
	virtual ~gsGGJHealth(void);

	virtual void update();
	virtual void draw();
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {};
	void resize(void);
	void move(void);
};

#endif