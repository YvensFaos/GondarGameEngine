#ifndef __GS_SHOOT_EM_UP__PLAYER__
#define __GS_SHOOT_EM_UP__PLAYER__


#include "gsShootEmUpObject.h"
#include "gsSpriteSheet.h"

// Classe que representa a nave do jogador
class gsShootEmUp_Player : public gsShootEmUpObject {
public:
	gsSpriteSheet *sprite;
	float health;
	float damage;
	float weaponCooldownTime;
	float weaponCooldown;
	
	gsShootEmUp_Player() {}
	gsShootEmUp_Player(gsShootEmUpGame *game);
	virtual ~gsShootEmUp_Player();

	void update();
	void draw();

	void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif