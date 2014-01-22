#ifndef __GS_SHOOT_EM_UP__ENEMY__
#define __GS_SHOOT_EM_UP__ENEMY__


#include "gsShootEmUpObject.h"

class gsShootEmUp_Enemy : public gsShootEmUpObject {
private:
	float hp;
	float damage;
	float speed;
	float weapowCooldownTime;
	float swapowCooldown;
	
public:
	gsShootEmUp_Enemy() {}
	gsShootEmUp_Enemy(bool isPlayerBullet, gsShootEmUpGame *game);

	void update();
	void draw();

	void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif