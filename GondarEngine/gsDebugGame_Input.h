#ifndef __GS_DEBUG_GAME__INPUT__
#define __GS_DEBUG_GAME__INPUT__

#include "gsMacros.h"

#ifdef GS_DEBUG

#include "gsGame.h"
#include "gsGameObject.h"
#include "gsArrayList.h"

class gsDebugGame_Input : public gsGame {
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