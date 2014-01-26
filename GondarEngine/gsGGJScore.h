#ifndef __GS_GGJ_SCORE_H__
#define __GS_GGJ_SCORE_H__

#include "gsGGJObject.h"
#include "gsGGJNumber.h"
#include "gsArrayList.h"
#include "gsGGJGlobals.h"

class gsGGJScore : public gsGGJObject
{
private:
		float aux;

public:
	gsArrayList<gsGGJNumber *> numbers;

	gsGGJScore(void) {}
	gsGGJScore(gsGGJGame* game);

	int oldScore;

	virtual ~gsGGJScore(void);

	virtual void update();
	virtual void draw();
	
	int getNumberByIndex(int index);

	void onCollision(gsGameObject *other, const gsCollisionInfo& info){}
};

#endif
