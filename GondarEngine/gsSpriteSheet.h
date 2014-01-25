#ifndef __GS_SPRITE_SHEET__
#define __GS_SPRITE_SHEET__

#include "gsTexture.h"
#include "gsArrayList.h"
#include "gsAnimationClip.h"

class gsVector2;

class gsSpriteSheet : public gsTexture{
private:
	gsVector2* positions;
	int column;
	int rows;
	int cellCount;

	gsArrayList<gsAnimationClip*> animations;
	gsAnimationClip *currentAnimation;
	float elapsedTime;
	int currentKeyframe;

	void genCoordinates();
	
public:
	gsSpriteSheet(void);
	gsSpriteSheet(const char* file, const char* name, int _rows, int _column);
	~gsSpriteSheet(void);

	void updateAnimation();

	void addAnimation(gsAnimationClip* clip);
	void setAnimation(const char* animationName);

	gsVector2* getCurrentSprite();
	gsVector2* getSprite(int i);

};

#endif