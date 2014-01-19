#ifndef __GS_TRIANGLE__
#define __GS_TRIANGLE__


#include "gsAxis.h"
#include "gsVector3.h"
#include "gsColor.h"

class gsTriangle {
public:
	gsVector3 a;
	gsVector3 b;
	gsVector3 c;
	gsVector3 normal;

	gsColor color;

	gsTriangle(void);
	gsTriangle(gsVector3 _a, gsVector3 _b, gsVector3 _c);
	~gsTriangle(void);

	void calculateNormal(void);
	void drawTriangle(void);
	void drawTriangleLines(void);
	void print(void);

	void translate(gsVector3 translation);
	void rotate(float angle, gsAxis axis);
};

#endif