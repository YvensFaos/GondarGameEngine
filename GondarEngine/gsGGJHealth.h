#ifndef __GS_GGJ_HEALTH__
#define __GS_GGJ_HEALTH__

#include "gsGGJObject.h"

class gsGGJShip;
class gsSpriteSheet;

class gsGGJHealth : public gsGGJObject {
public:
	gsGGJShip* target;
	gsSpriteSheet *sprite;
	float size;

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