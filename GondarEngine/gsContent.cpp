#include "gsContent.h"


#include "gsRandom.h"
#include "gsAnimationClip.h"
#include "gsHashMap.h"

#include <cstring>


// Buffers comuns
int g123anim[3] = {0, 1, 2};
int g1234anim[4] = {0, 1, 2, 3};

void gsContent::init() {
	
}
void gsContent::dispose() {
	
}


gsTexture* gsContent::getTexture(const char* name) {
	return 0;
}

gsSpriteSheet* gsContent::getSpriteSheet(const char* name) {
	return 0;
}