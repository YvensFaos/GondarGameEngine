#ifndef __GS_SHOOT_EM_UP__BULLET__
#define __GS_SHOOT_EM_UP__BULLET__


#include "gsShootEmUpObject.h"
#include "gsSpriteSheet.h"

class gsShootEmUp_Bullet : public gsShootEmUpObject {
private:
	gsSpriteSheet *sprite;
	float damage;
	
public:
	gsShootEmUp_Bullet() {}
	gsShootEmUp_Bullet(bool isPlayerBullet, gsShootEmUpGame *game);
	~gsShootEmUp_Bullet();

	void update();
	void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif