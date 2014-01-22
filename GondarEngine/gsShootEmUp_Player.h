#ifndef __GS_SHOOT_EM_UP__PLAYER__
#define __GS_SHOOT_EM_UP__PLAYER__


#include "gsShootEmUpObject.h"

class gsShootEmUp_Player : public gsShootEmUpObject {
private:
	float health;
	float damage;
	float speed;
	float weapowCooldownTime;
	float swapowCooldown;
	
public:
	gsShootEmUp_Player() {}
	gsShootEmUp_Player(gsShootEmUpGame *game);

	void update();
	void draw();

	void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif