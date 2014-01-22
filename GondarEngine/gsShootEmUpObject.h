#ifndef __GS_SHOOT_EM_UP_OBJECT__
#define __GS_SHOOT_EM_UP_OBJECT__


#include "gsGameObject.h"
#include "gsShootEmUpGame.h"
#include "gsShootEmUpObjectTag.h"

class gsShootEmUpObject : public gsGameObject {
protected:
	gsShootEmUpGame *game;
	gsShootEmUpObjectTag tag;

public:
	gsShootEmUpObject() {}
	gsShootEmUpObject(gsShootEmUpGame *game) { this->game = game; }

	gsShootEmUpObjectTag getTag() { return tag; }
};

#endif