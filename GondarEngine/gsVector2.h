#ifndef __GS_VECTOR_2__
#define __GS_VECTOR_2__


#include "gsAxis.h"

class gsVector2 {
public:
	float x;
	float y;

	gsVector2(void);
	gsVector2(float points[2]);
	gsVector2(float _x, float _y);
	~gsVector2(void);

	gsVector2* copy(void);
	void makeUnitary(void);
	void print(void);

	bool isZeroVector(void);
	bool isParalel(gsVector2* p);

	float magnitude(void);
	float angleTo(gsVector2* p);

	void drawVertex2f(void);
	void rotate(float angle, gsAxis axis);

	void operator +(gsVector2* p);
	void operator -(gsVector2* p);
	void operator *(float value);

public:
	static float dot(gsVector2*, gsVector2*);
	static gsVector2* vector(gsVector2*, gsVector2*);
};

#endif