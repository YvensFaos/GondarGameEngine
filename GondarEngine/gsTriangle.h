#ifndef __GS_TRIANGLE__
#define __GS_TRIANGLE__


#include "gsAxis.h"
#include "gsVector3.h"
#include "gsColor.h"
#include <ostream>

class gsTriangle {
public:
	gsVector3 a;
	gsVector3 b;
	gsVector3 c;
	gsVector3 normal;

	gsColor color;

	gsTriangle(void);
	gsTriangle(gsVector3 _a, gsVector3 _b, gsVector3 _c);

	void calculateNormal(void);

	void drawSolid(void);
	void drawWireFrame(void);

	void translate(const gsVector3& amount);
	void rotate(float angle, gsAxis axis);
};

// To String
std::ostream& operator<<(std::ostream& os, const gsTriangle& triangle);

#endif