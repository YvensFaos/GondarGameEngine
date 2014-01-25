#ifndef __GS_GGJ_PLAYER_H__
#define __GS_GGJ_PLAYER_H__

#include "gsGGJship.h"


class gsGGJPlayer : public gsGGJShip
{
public: 
	gsGGJPlayer(void) {}
	gsGGJPlayer(gsGame *game);
	virtual ~gsGGJPlayer(void);

	virtual void update();
	virtual void draw();
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info);

	void move();
	void shoot();
};

#endif