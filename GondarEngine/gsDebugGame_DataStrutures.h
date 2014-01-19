#ifndef __GS_DEBUG_GAME__DATA_STRUTURES__
#define __GS_DEBUG_GAME__DATA_STRUTURES__

#include "gsMacros.h"

#ifdef GS_DEBUG

#include "gsGame.h"


class gsDebugGame_DataStrutures : public gsGame {
private:
	void testLinkedList();
	void testArrayList();

public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();
};

#endif // GS_DEBUG
#endif