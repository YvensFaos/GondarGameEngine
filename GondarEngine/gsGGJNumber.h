#ifndef __GS_GGJ_NUMBER_H_
#define __GS_GGJ_NUMBER_H_

#include "gsGGJObject.h"

class gsSpriteSheet;

class gsGGJNumber : public gsGGJObject
{
public:
	gsSpriteSheet *sprite;

	gsGGJNumber(void) {}
	gsGGJNumber(gsGGJGame* game);
	virtual ~gsGGJNumber(void);

	virtual void update();
	virtual void draw();

<<<<<<< HEAD
	void onCollision(gsGameObject *other, const gsCollisionInfo& info){}
	void draw(int number,int x, int y);
=======
	~gsGGJNumber(void);
>>>>>>> f8ecffa20a5f5efa1354fd6adb6742856874d61b
};

#endif