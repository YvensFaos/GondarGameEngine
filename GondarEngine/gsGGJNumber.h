#ifndef __GS_GGJ_NUMBER_H_
#define __GS_GGJ_NUMBER_H_

#include "gsGGJObject.h"

class gsSpriteSheet;

class gsGGJNumber : public gsGGJObject
{
public:
	gsSpriteSheet *sprite;
	int digit;

	gsGGJNumber(void) {}
	gsGGJNumber(int digit,gsGGJGame* game);
	virtual ~gsGGJNumber(void);

	virtual void update();
	virtual void draw();

	void onCollision(gsGameObject *other, const gsCollisionInfo& info){}
};

#endif