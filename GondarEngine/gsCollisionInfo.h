#ifndef __GS_COLLISION_INFO__
#define __GS_COLLISION_INFO__


#include "gsVector3.h"

class gsCollisionInfo {
public:
	gsVector3 contactPoints[8];
	gsVector3 penetration;

	gsCollisionInfo() {}
	gsCollisionInfo(gsVector3 p, gsVector3 *contacts) {
		penetration = p;
		for (int i = 0; i < 8; i++)
		{
			contactPoints[i] = contacts[i];
		}
	}
};

#endif