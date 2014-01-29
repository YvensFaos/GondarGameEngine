#ifndef __GS_GGJ_DROP_MESSAGE__
#define __GS_GGJ_DROP_MESSAGE__

#include "gsGGJObject.h"
#include "gsCollisionInfo.h"
#include "gsSpriteSheet.h"

class gsGGJDropMessage : public gsGGJObject {
public:
	gsSpriteSheet *messageSprite;
	float fadeOut;

	gsGGJDropMessage(void) {}
	gsGGJDropMessage(const gsCollisionInfo& collision, gsColor color, gsGGJGame *game, char* texture);
	virtual ~gsGGJDropMessage(void);

	virtual void update();
	virtual void draw();
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {};
	
	void setupSpritesheet(char* texture);
};

#endif