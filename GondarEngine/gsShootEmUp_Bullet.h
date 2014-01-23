#ifndef __GS_SHOOT_EM_UP__BULLET__
#define __GS_SHOOT_EM_UP__BULLET__


#include "gsShootEmUpObject.h"
#include "gsSpriteSheet.h"

class gsShootEmUp_Bullet : public gsShootEmUpObject {
public:
	gsSpriteSheet *sprite;
	float damage;

	gsShootEmUp_Bullet() {}
	gsShootEmUp_Bullet(bool isPlayerBullet, gsShootEmUpObject* shooter, gsShootEmUpGame *game, gsVector3 speed);
	~gsShootEmUp_Bullet();

	void update();
	void draw();

	void setDamage(float damage);
	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif
