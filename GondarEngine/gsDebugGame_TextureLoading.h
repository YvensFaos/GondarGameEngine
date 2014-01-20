#ifndef __GS_DEBUG_GAME__TEXTURE_LOADING__
#define __GS_DEBUG_GAME__TEXTURE_LOADING__

#include "gsMacros.h"

#ifdef GS_DEBUG

#include "gsGame.h"
#include "gsTexture.h"
#include "gsGameObject.h"
#include "gsArrayList.h"

class gsDebugGame_TextureLoading : public gsGame {
private:
	gsTexture texture;
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