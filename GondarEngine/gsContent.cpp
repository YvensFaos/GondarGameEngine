#include "gsContent.h"


#include "gsRandom.h"
#include "gsAnimationClip.h"
#include "gsHashMap.h"

#include <cstring>

int gSeed;

// Buffers comuns
int g123anim[3] = {0, 1, 2};
int g1234anim[4] = {0, 1, 2, 3};


// "murmur hash"
int stringToHash(const char* string) {
	int len = strlen(string);
	int output = 0;
	int aux = 0;

	int *data = (int*)string;
	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	output = gSeed ^ len; // ^ é o xor do c++

	while (len >= 4) {
		aux = *data;

		aux *= m;
		aux ^= aux >> r;
		aux *= m;

		output *= m;
		output *= k;

		data++;
		len -= 4;
	}
	switch (len) {
	case 3: output ^= data[2] << 16;
	case 2: output ^= data[1] << 8;
	case 1: output ^= data[0];
	        output *= m;
	}

	output ^= output >> 13;
	output *= m;
	output ^= output >> 15;

	return output;
}




void gsContent::init() {
	gSeed = rand();

	// criar hash com name - > path
	// criar hash com name - > gluint
}
void gsContent::dispose() {
	
}


gsTexture* gsContent::getTexture(const char* name) {
	return 0;
}

gsSpriteSheet* gsContent::getSpriteSheet(const char* name) {
	return 0;
}