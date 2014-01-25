#ifndef __GS_GGJ_SHOP__
#define __GS_GGJ_SHOP__

#include "gsGGJObject.h"
#include "gsSpriteSheet.h"

class gsGGJShop : public gsGGJObject {
public:
	gsSpriteSheet *sprite;

	gsGGJShop(void) {}
	gsGGJShop(gsGGJGame *game);
	virtual ~gsGGJShop(void);

	virtual void update();
	virtual void draw();
	
	virtual void onCollision(gsGameObject *other, const gsCollisionInfo& info);

	void setUpSprite();
};

#endif