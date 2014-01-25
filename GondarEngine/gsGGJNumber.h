#ifndef __GS_GGJ_NUMBER_H_
#define __GS_GGJ_NUMBER_H_

#include "gsSpriteSheet.h"

class gsGGJNumber
{
public:
	static gsSpriteSheet numberSpriteSheet;

	gsGGJNumber(void);
	
	void draw();

	~gsGGJNumber(void);
};

#endif