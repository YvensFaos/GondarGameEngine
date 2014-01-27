#ifndef __GS_DROP_PANORAMA__
#define __GS_DROP_PANORAMA__

#include "gsGGJObject.h"

class gsSpriteSheet;
class gsTranform;

class gsGGJDrop : public gsGGJObject {
public:
	gsSpriteSheet *sprite;
	float size;

	gsGGJDrop(void) {}
	gsGGJDrop(gsGGJGame *game, gsTransform* transform);
	virtual ~gsGGJDrop(void);

	virtual void update();
	virtual void draw();
	
	void onCollision(gsGameObject *other, const gsCollisionInfo& info);
};

#endif