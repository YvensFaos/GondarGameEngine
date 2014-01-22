#include "gsAnimationClip.h"
#include <cstring>

gsAnimationClip::gsAnimationClip(void)
{
	name = "Unloaded Animation Clip";
	keyFrames = 0;
	keyFrameCount = 0;
	refreshInterval = 0;
}
gsAnimationClip::gsAnimationClip(const char* name, int* keyFrames, int keyFrameCount)
{
	this->name = name;
	this->keyFrames = keyFrames;
	this->keyFrameCount = keyFrameCount;
	this->refreshInterval = 0.4f;
}
gsAnimationClip::~gsAnimationClip(void)
{
	if (keyFrames) {
		delete[] keyFrames;
	}
}

bool operator==(const gsAnimationClip& lhs, const gsAnimationClip& rhs) {
	return !strcmp(lhs.name, rhs.name);
}