#ifndef __GS_GGJ_SCORE_H__
#define __GS_GGJ_SCORE_H__

#include "gsGGJObject.h"
#include "gsGGJNumber.h"
#include "gsArrayList.h"
#include "gsGGJGlobals.h"

class gsGGJScore : public gsGGJObject {
public:
	gsArrayList<gsGGJNumber*> numbers;
	int oldScore;

	gsGGJScore(void) {}
	gsGGJScore(gsGGJGame* game);
	virtual ~gsGGJScore(void);

	virtual void update();
	virtual void draw();

	void setScore(int score);
	
	int getNumberByIndex(int number, int index);

	void onCollision(gsGameObject *other, const gsCollisionInfo& info){}
};

#endif
