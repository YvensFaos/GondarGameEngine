#ifndef __GS_GGJ_SHIP__
#define __GS_GGJ_SHIP__


#include "gsGGJObject.h"
#include "gsGGJTag.h"
#include "gsGGJPhase.h"
#include "gsGGJGlobals.h"
#include "gsSpriteSheet.h"


class gsGGJShip : public gsGGJObject {
public:
	float powerFactor;
	float sizeFactor;
	float speedFactor;
	int cannons;
	float avoidChance;
	float hp;
	float damage;
	gsSpriteSheet *sprite;
	gsGGJPhase phase;
	gsGGJBulletType bulletType;
	float weaponCooldown;
	float weaponCooldownTime;

	gsGGJShip() {}
	gsGGJShip(gsGGJGame *game) {
		powerFactor = gsGGJGlobal_PowerFactor;
		sizeFactor = gsGGJGlobal_SizeFactor;
		speedFactor = gsGGJGlobal_SpeedFactor;
		cannons = gsGGJGlobal_Cannons;
		avoidChance = gsGGJGlobal_AvoidChance;
		phase = gsGGJGlobal_Phase;
		bulletType = gsGGJGlobal_BulletType;
	}
	virtual ~gsGGJShip() {}
};

#endif