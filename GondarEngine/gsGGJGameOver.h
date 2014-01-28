#ifndef __GS_GGJ_GAME_OVER__
#define __GS_GGJ_GAME_OVER__

#include "gsGGJObject.h"
#include "gsSpriteSheet.h"

class gsTransform;

class gsGGJGameOver : public gsGGJObject {
public:
	gsSpriteSheet *tutorialSprite;

	gsSpriteSheet *pressSprite;
	gsTransform pressSpaceTransform;

	gsSpriteSheet *escSprite;
	gsTransform pressEscTransform;

	float alpha;

	gsGGJGameOver(void) {}
	gsGGJGameOver(gsGGJGame *game);
	virtual ~gsGGJGameOver(void);

	virtual void update(void);
	virtual void draw(void);
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {};
	
	void setupSpritesheet(void);
};

#endif