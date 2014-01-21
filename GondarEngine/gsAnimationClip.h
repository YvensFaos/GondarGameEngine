#ifndef __GS_ANIMATION_CLIP__
#define __GS_ANIMATION_CLIP__

class gsAnimationClip
{
private:
	int* positions;
	int size;

	int position;
public:
	gsAnimationClip(void);
	gsAnimationClip(int* positions, int size);

	int actual(void);
	int next(void);
};

#endif