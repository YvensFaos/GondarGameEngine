#include "gsAnimationClip.h"

gsAnimationClip::gsAnimationClip(void)
{
	size = 0;
	position = 0;
}

gsAnimationClip::gsAnimationClip(int* positions, int size)
{
	this->positions = positions;
	this->size = size;
	
	position = 0;
}

int gsAnimationClip::actual(void)
{
	return position;
}

int gsAnimationClip::next(void)
{
	return ++position % size;
}