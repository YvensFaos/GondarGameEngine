#ifndef __GS_GGJ_OBJECT__
#define __GS_GGJ_OBJECT__


#include "gsGameObject.h"
#include "gsGGJGame.h"
#include "gsGGJTag.h"

class gsGGJObject : public gsGameObject {
public:
	gsGGJGame *game;
	gsGGJTag tag;

	gsGGJObject() {}
	gsGGJObject(gsGGJGame *game) : gsGameObject() { 
		this->game = game;
		this->tag = gsGGJTag::TuNaoSetouAindaViado;
	}
	virtual ~gsGGJObject() {}
};

#endif