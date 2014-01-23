#ifndef __GS_ANIMATION_CLIP__
#define __GS_ANIMATION_CLIP__

class gsAnimationClip {
public:
	const char* name;
	int* keyFrames;
	int keyFrameCount;
	float refreshInterval;

	gsAnimationClip(void);
	gsAnimationClip(const char* name, int* keyFrames, int keyFrameCount, float refreshInterval);
	~gsAnimationClip();
};

bool operator==(const gsAnimationClip& lhs, const gsAnimationClip& rhs);

#endif