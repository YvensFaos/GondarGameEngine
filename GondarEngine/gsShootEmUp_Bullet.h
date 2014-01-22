#ifndef __GS_SHOOT_EM_UP__BULLET__
#define __GS_SHOOT_EM_UP__BULLET__


#include "gsShootEmUpObject.h"

class gsShootEmUp_Bullet : public gsShootEmUpObject {
private:
	float damage;
	float speed;
	
public:
	gsShootEmUp_Bullet() {}
	gsShootEmUp_Bullet(bool isPlayerBullet, gsShootEmUpGame *game);

	void update();
	void draw();

	void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif