#ifndef __GS_GGJ_TUTORIAL__
#define __GS_GGJ_TUTORIAL__

#include "gsGGJObject.h"
#include "gsSpriteSheet.h"

class gsTransform;

class gsGGJTutorial : public gsGGJObject {
public:
	gsSpriteSheet *tutorialSprite;
	gsSpriteSheet *pressSprite;
	gsTransform pressSpaceTransform;

	int state;
	float alpha;

	gsGGJTutorial(void) {}
	gsGGJTutorial(gsGGJGame *game);
	virtual ~gsGGJTutorial(void);

	virtual void update(void);
	virtual void draw(void);
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {};
	
	void setupSpritesheet(void);
};

#endif