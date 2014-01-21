#ifndef __GS_VECTOR_2__
#define __GS_VECTOR_2__


#include "gsAxis.h"
#include <ostream>

class gsVector2 {
public:
	float x;
	float y;

	gsVector2(void);
	gsVector2(float points[2]);
	gsVector2(float _x, float _y);

	float magnitude(void)  const;
	void normalize(void);

	bool isZeroVector(void) const;

	void operator +=(const gsVector2& rhs);
	void operator -=(const gsVector2& rhs);
	void operator *=(const float& rhs);
	void operator /=(const float& rhs);

public:
	static float dot(const gsVector2&, const gsVector2&);

	static gsVector2 zero() { return gsVector2(0.0f, 0.0f); }
	static gsVector2 one() { return gsVector2(1.0f, 1.0f); }
};

gsVector2 operator+(const gsVector2& lhs, const gsVector2& rhs);
gsVector2 operator-(const gsVector2& lhs, const gsVector2& rhs);
gsVector2 operator*(const gsVector2& lhs, const float& rhs);
gsVector2 operator/(const gsVector2& lhs, const float& rhs);

std::ostream& operator<<(std::ostream& os, const gsVector2& vector);

#endif