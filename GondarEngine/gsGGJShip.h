#ifndef __GS_GGJ_SHIP__
#define __GS_GGJ_SHIP__

#include "gsGGJObject.h"
#include "gsGGJTag.h"
#include "gsGGJPhase.h"
#include "gsGGJGlobals.h"
#include "gsGGJHealth.h"
#include "gsSpriteSheet.h"

class gsGGJShip : public gsGGJObject {
public:
	float hp;
	float maxHp;
	float damage;
	gsSpriteSheet *sprite;
	gsGGJPhase phase;
	gsGGJBulletType bulletType;
	gsGGJHealth* healthBar;
	float cooldown;
	float cooldownTime;

	gsGGJShip() {}
	gsGGJShip(gsGGJGame *game) : gsGGJObject(game) {
		phase = gsGGJPhase::BluePhase; // it will be reset at the enemy constructor
		bulletType = gsGGJGlobal_BulletType;
	}
	virtual ~gsGGJShip() {}
};

#endif