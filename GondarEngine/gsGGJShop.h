#ifndef __GS_GGJ_SHOP__
#define __GS_GGJ_SHOP__

#include "gsGGJObject.h"

class gsShop : public gsGGJObject {
public:
	gsShop(void) {}
	gsShop(gsGGJGame *game);
	virtual ~gsShop(void);

	virtual void update();
	virtual void draw();
	
	virtual void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif