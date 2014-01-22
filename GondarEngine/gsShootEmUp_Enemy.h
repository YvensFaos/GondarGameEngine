#ifndef __GS_SHOOT_EM_UP__ENEMY__
#define __GS_SHOOT_EM_UP__ENEMY__


#include "gsShootEmUpObject.h"
#include "gsSpriteSheet.h"

class gsShootEmUp_Enemy : public gsShootEmUpObject {
private:
	gsSpriteSheet *sprite;
	float hp;
	float damage;
	float weapowCooldownTime;
	float swapowCooldown;
	
public:
	gsShootEmUp_Enemy() {}
	gsShootEmUp_Enemy(gsShootEmUpGame *game);
	~gsShootEmUp_Enemy();

	void update();
	void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);
};

#endif