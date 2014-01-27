#ifndef __GS_GGJ_PLAYER_H__
#define __GS_GGJ_PLAYER_H__

#include "gsGGJship.h"
#include "gsGGJPlayerState.h"


class gsGGJPlayer : public gsGGJShip {
public: 
	gsGGJPlayerState state;
	float stateTransitionTime;
	float blinkTime;

	gsGGJPlayer(void) {}
	gsGGJPlayer(gsGGJGame *game);
	virtual ~gsGGJPlayer(void);

	virtual void update();
	virtual void draw();
	
	virtual void onCollision(gsGameObject *other, const gsCollisionInfo& info);

	void move();
	void shoot();
	void changeColor(gsGGJPhase color);
	void toChangeColor();

	void setUpSpritesheet();
};

#endif