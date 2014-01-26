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
	float cooldown;
	float cooldownTime;

	gsGGJShip() {}
	gsGGJShip(gsGGJGame *game) : gsGGJObject(game) {
		powerFactor = gsGGJGlobal_PowerFactor;
		sizeFactor = gsGGJGlobal_SizeFactor;
		speedFactor = gsGGJGlobal_SpeedFactor;
		cannons = gsGGJGlobal_Cannons;
		avoidChance = gsGGJGlobal_AvoidChance;
		phase = gsGGJPhase::BluePhase; // it will be reset at the enemy constructor
		bulletType = gsGGJGlobal_BulletType;
	}
	virtual ~gsGGJShip() {}
};

#endif