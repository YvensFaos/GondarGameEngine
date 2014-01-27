#ifndef __GS_GGJ_LIFE__
#define __GS_GGJ_LIFE__

#include "gsGGJObject.h"
#include "gsGGJGlobals.h"
#include "gsSpriteSheet.h"

class gsGGJLifes : public gsGGJObject {
public:
	gsSpriteSheet *lifeSprite;
	int oldScore;

	gsGGJLifes(void) {}
	gsGGJLifes(gsGGJGame* game);
	virtual ~gsGGJLifes(void);

	virtual void update();
	virtual void draw();

	void onCollision(gsGameObject *other, const gsCollisionInfo& info){}
};

#endif