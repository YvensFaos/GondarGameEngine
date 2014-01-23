#ifndef __GS_SHOOT_EM_UP_OBJECT__
#define __GS_SHOOT_EM_UP_OBJECT__


#include "gsGameObject.h"
#include "gsShootEmUpGame.h"
#include "gsShootEmUpObjectTag.h"

class gsShootEmUpObject : public gsGameObject {
protected:
	gsShootEmUpGame *game;

public:
	gsShootEmUpObjectTag tag;

	gsShootEmUpObject() {}
	gsShootEmUpObject(gsShootEmUpGame *game) : gsGameObject() { this->game = game; }

	gsShootEmUpObjectTag getTag() { return tag; }
};

#endif