#ifndef __GS_GGJ_EXPLOSION__
#define __GS_GGJ_EXPLOSION__

#include "gsGGJObject.h"
#include "gsCollisionInfo.h"
#include "gsSpriteSheet.h"

class gsGGJExplosion : public gsGGJObject {
public:
	gsSpriteSheet *explosionSprite;
	float fadeOut;

	gsGGJExplosion(void) {}
	gsGGJExplosion(const gsCollisionInfo& collision, gsColor color, gsGGJGame *game);
	virtual ~gsGGJExplosion(void);

	virtual void update();
	virtual void draw();
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {};
	
	void setupSpritesheet();
};

#endif