#include "gsVector2.h"

#include "gsLogger.h"
#include "gsOpenGL.h"
#include <ostream>

gsVector2::gsVector2(void)
{
	x = 0.0f;
	y = 0.0f;
}
gsVector2::gsVector2(float points[2])
{
	x = points[0];
	y = points[1];
}
gsVector2::gsVector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

float gsVector2::magnitude(void) const
{
	return sqrt(x * x + y * y);
}
void gsVector2::normalize(void)
{
	float len = magnitude();
	if (len != 0.0f)
	{
		x /= len;
		y /= len;
	}
}

bool gsVector2::isZeroVector(void) const
{
	return x == 0 && y == 0;
}

float gsVector2::dot(const gsVector2& a, const gsVector2& b)
{
	return a.x*b.x + a.y*b.y;
}

void gsVector2::operator +=(const gsVector2& rhs) {
	x += rhs.x;
	y += rhs.y;
}

void gsVector2::operator -=(const gsVector2& rhs) {
	x -= rhs.x;
	y -= rhs.y;
}

void gsVector2::operator *=(const float& rhs) {
	x *= rhs;
	y *= rhs;
}

void gsVector2::operator /=(const float& rhs) {
	x /= rhs;
	y /= rhs;
}

gsVector2 operator+(const gsVector2& lhs, const gsVector2& rhs) {
	return gsVector2(
		lhs.x + rhs.x, 
		lhs.y + rhs.y);
}

gsVector2 operator-(const gsVector2& lhs, const gsVector2& rhs) {
	return gsVector2(
		lhs.x - rhs.x, 
		lhs.y - rhs.y);
}

gsVector2 operator*(const gsVector2& lhs, const float& rhs) {
	return gsVector2(
		lhs.x * rhs, 
		lhs.y * rhs);
}
gsVector2 operator/(const gsVector2& lhs, const float& rhs) {
	return gsVector2(
		lhs.x / rhs, 
		lhs.y / rhs);
}

std::ostream& operator<<(std::ostream& os, const gsVector2& vector) {
	os << "(" << vector.x << ", " << vector.y << ")";
	return os;
}