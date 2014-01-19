#ifndef __GS_VECTOR_3__
#define __GS_VECTOR_3__


#include "gsAxis.h"

class gsVector3 {
public:
	float x;
	float y;
	float z;

	gsVector3(void);
	gsVector3(float points[3]);
	gsVector3(float _x, float _y, float _z);
	~gsVector3(void);

	void makeUnitary(void);
	void print(void);

	bool isZeroVector(void);
	bool isParalel(gsVector3* p);

	float magnitude(void);
	float angleTo(gsVector3* p);

	void drawVertex3f(void);
	void rotate(float angle, gsAxis axis);

	void operator +(gsVector3* p);
	void operator -(gsVector3* p);
	void operator *(float value);

public:
	static float dot(gsVector3*, gsVector3*);
	static gsVector3* vector(gsVector3*, gsVector3*);
	static gsVector3* crossProduct(gsVector3*, gsVector3*);
};

#endif