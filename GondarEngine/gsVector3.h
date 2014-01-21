#ifndef __GS_VECTOR_3__
#define __GS_VECTOR_3__


#include "gsAxis.h"
#include <ostream>

class gsVector3 {
public:
	float x;
	float y;
	float z;

	gsVector3(void);
	gsVector3(float points[3]);
	gsVector3(float _x, float _y, float _z);

	float magnitude(void)  const;
	void normalize(void);

	float angleTo(const gsVector3& p) const;
	void rotate(float angle, const gsAxis& axis);

	bool isZeroVector(void) const;
	bool isParalel(const gsVector3& p) const;

	void sendToOpenGL_Vertex(void) const;
	void sendToOpenGL_Normal(void) const;
	void sendToOpenGL_Color(void) const;

	void operator +=(const gsVector3& rhs);
	void operator -=(const gsVector3& rhs);
	void operator *=(const gsVector3& rhs);
	void operator /=(const gsVector3& rhs);
	void operator *=(const float& rhs);
	void operator /=(const float& rhs);

public:
	static float dot(const gsVector3&, const gsVector3&);
	static gsVector3 cross(const gsVector3&, const gsVector3&);

	static gsVector3 zero() { return gsVector3(0.0f, 0.0f, 0.0f); }
	static gsVector3 one() { return gsVector3(1.0f, 1.0f, 1.0f); }
};

gsVector3 operator+(const gsVector3& lhs, const gsVector3& rhs);
gsVector3 operator-(const gsVector3& lhs, const gsVector3& rhs);
gsVector3 operator*(const gsVector3& lhs, const gsVector3& rhs);
gsVector3 operator/(const gsVector3& lhs, const gsVector3& rhs);
gsVector3 operator*(const gsVector3& lhs, const float& rhs);
gsVector3 operator/(const gsVector3& lhs, const float& rhs);

// To String
std::ostream& operator<<(std::ostream& os, const gsVector3& vector);

#endif