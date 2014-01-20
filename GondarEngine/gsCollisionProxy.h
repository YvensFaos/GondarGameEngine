#ifndef __GS_COLLISION_PROXY__
#define __GS_COLLISION_PROXY__


#include "gsVector3.h"
#include "gsTransform.h"
#include "gsGameObject.h"
#include "gsCollisionInfo.h"

class gsCollisionProxy {
public:
	gsGameObject *object;
	gsVector3 aabbMin;
	gsVector3 aabbMax;

	gsCollisionProxy() {}
	gsCollisionProxy(gsGameObject* obj) {
		object = obj;
		aabbMin = object->transform.position;
		aabbMax = object->transform.position + object->transform.size;
	}

public:
	static bool broadTest(const gsCollisionProxy& a, const gsCollisionProxy& b);
	static const gsCollisionInfo* narrowTest(const gsCollisionProxy& a, const gsCollisionProxy& b);
};

#endif