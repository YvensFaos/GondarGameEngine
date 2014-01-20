#ifndef __GS_DEBUG_GAME__COLLISIONS__
#define __GS_DEBUG_GAME__COLLISIONS__

#include "gsMacros.h"

#ifdef GS_DEBUG

#include "gsGame.h"
#include "gsGameObject.h"
#include "gsArrayList.h"


class gsDebugGame_Collisions : public gsGame {
private:
	gsArrayList<gsGameObject*> objects;

public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();
};

#endif // GS_DEBUG
#endif