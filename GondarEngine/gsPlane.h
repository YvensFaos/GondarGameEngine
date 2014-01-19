#ifndef __GS_PLANE__
#define __GS_PLANE__


#include "gsVector3.h"

class gsPlane {
private:
	bool wireFrame;

public:
	gsVector3 a;
	gsVector3 normal;

	gsVector3 p1;
	gsVector3 p2;

	gsVector3 color;

	gsPlane(void);
	gsPlane(gsVector3 _a, gsVector3 _normal);
	~gsPlane(void);

	void setWireframe(bool);
	void drawPlane(void);
	void createWireframe(void);

	gsVector3* parametricPoint3D(float s, float t);
};

#endif