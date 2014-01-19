#ifndef __GS_PLANE__
#define __GS_PLANE__


#include "gsVector3.h"

class gsPlane {
public:
	gsVector3 a;
	gsVector3 normal;

	gsPlane(gsVector3 _a, gsVector3 _normal);
};

#endif