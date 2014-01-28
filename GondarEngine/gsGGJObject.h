#ifndef __GS_GGJ_OBJECT__
#define __GS_GGJ_OBJECT__


#include "gsGameObject.h"
#include "gsGGJGlobals.h"
#include "gsGGJGame.h"
#include "gsGGJTag.h"

class gsGGJObject : public gsGameObject {
public:
	gsGGJGame *game;
	gsGGJTag tag;

	gsGGJObject() {}
	gsGGJObject(gsGGJGame *game) : gsGameObject() { 
		this->game = game;
		this->solid = false;
		this->tag = gsGGJTag::TuNaoSetouAindaViado;
	}
	virtual ~gsGGJObject() {}

	void setPhaseColor(gsGGJPhase phase) {
		if (phase == gsGGJPhase::RedPhase) transform.tint = PHASE_RED_COLOR;
		else if (phase == gsGGJPhase::GreenPhase) transform.tint = PHASE_GREEN_COLOR;
		else if (phase == gsGGJPhase::BluePhase) transform.tint = PHASE_BLUE_COLOR;
		else if (phase == gsGGJPhase::YellowPhase) transform.tint = PHASE_YELLOW_COLOR;
		else if (phase == gsGGJPhase::MagentaPhase) transform.tint = PHASE_MAGENTA_COLOR;
	}
};

#endif