#ifndef __GS_AUDIO__
#define __GS_AUDIO__


#include "gsTransform.h"
typedef int gsChannel;

class gsAudio {
public:
	static void init();
	static void update();
	static void dispose();

	static gsChannel play(const char* path, bool repeat, float volume, float pan);
	static void stop(gsChannel channel);
	static float findPan(gsTransform *transform);
};

#endif