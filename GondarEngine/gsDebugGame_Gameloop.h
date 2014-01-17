#ifndef __GS_DEBUG_GAME__GAME_LOOP__
#define __GS_DEBUG_GAME__GAME_LOOP__

#include "gsMacros.h"

#ifdef GS_DEBUG

#include "gsGame.h"


class gsDebugGame_GameLoop : public gsGame {
private:
	int frameCounter;

public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();
};

#endif // GS_DEBUG
#endif