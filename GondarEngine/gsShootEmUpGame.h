#ifndef __GS_SHOOT_EM_UP_GAME__
#define __GS_SHOOT_EM_UP_GAME__


#include "gsGame.h"
#include "gsGameObject.h"
#include "gsArrayList.h"

class gsShootEmUpGame : public gsGame {
private:
	gsArrayList<gsGameObject*> objects;

public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();
};

#endif