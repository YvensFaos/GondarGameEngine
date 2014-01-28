#ifndef __GS_GGJ_PLAYER_EXPLOSION__
#define __GS_GGJ_PLAYER_EXPLOSION__

#include "gsGGJObject.h"
#include "gsCollisionInfo.h"
#include "gsSpriteSheet.h"

class gsGGJPlayerExplosion : public gsGGJObject {
public:
	gsGGJPhase phase;
	float time;

	gsGGJPlayerExplosion(void) {}
	gsGGJPlayerExplosion(gsTransform* transform, gsGGJPhase phase, gsGGJGame *game);
	virtual ~gsGGJPlayerExplosion(void) {}

	virtual void update();
	virtual void draw() {}
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {};
};

#endif