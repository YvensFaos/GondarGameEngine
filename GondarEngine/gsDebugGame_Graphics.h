#ifndef __GS_DEBUG_GAME__GRAPHICS__
#define __GS_DEBUG_GAME__GRAPHICS__

#include "gsMacros.h"

#ifdef GS_DEBUG

#include "gsGame.h"


class gsDebugGame_Graphics : public gsGame {
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