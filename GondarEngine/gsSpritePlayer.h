#ifndef __GS_SPRITE_PLAYER__
#define __GS_SPRITE_PLAYER__

#include "gsSpriteSheet.h"

class gsAnimationClip;

class gsSpritePlayer
{
private:
	gsSpriteSheet spriteSheet;
	gsAnimationClip* animations;

	int animationsCount;
	int selected;
public:
	gsSpritePlayer(void);
	gsSpritePlayer(gsSpriteSheet spriteSheet, gsAnimationClip* animations, int animationsCount);

	void setSelected(int selection);
	void update(void);
};

#endif