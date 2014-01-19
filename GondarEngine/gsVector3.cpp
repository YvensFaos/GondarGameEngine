#include "gsVector3.h"


#include "gsLogger.h"
#include "gsOpenGL.h"
#include <ostream>

gsVector3::gsVector3(void)
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}
gsVector3::gsVector3(float points[3])
{
	x = points[0];
	y = points[1];
	z = points[2];
}
gsVector3::gsVector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float gsVector3::magnitude(void) const
{
	return sqrt(x * x + y * y + z * z);
}
void gsVector3::normalize(void)
{
	float len = magnitude();
	if (len != 0.0f)
	{
		x /= len;
		y /= len;
		z /= len;
	}
}

float gsVector3::angleTo(const gsVector3& p) const
{
	float dot = gsVector3::dot(*this, p);
	float cosO = dot / this->magnitude() * p.magnitude();

	return acosf(cosO);
}
void gsVector3::rotate(float angle, const gsAxis& axis)
{
	if(angle == 0.0f)
	{
		return;
	}

	float newX = 0;
	float newY = 0;
	float newZ = 0;

	switch (axis)
	{
	case X:
		newY = y*cos(angle) + z*sin(angle);
		newZ = y*-1*sin(angle) + z*cos(angle);

		y = newY;
		z = newZ;
		break;
	case Y:
		newX = x*cos(angle) - z*sin(angle);
		newZ = x*sin(angle) + z*cos(angle);

		x = newX;
		z = newZ;
		break;
	case Z:
		newX = x*cos(angle) + y*sin(angle);
		newY = -1*x*sin(angle) + y*cos(angle);

		x = newX;
		y = newY;
		break;

	default:
		break;
	}
}

bool gsVector3::isZeroVector(void) const
{
	return x == 0 && y == 0 && z == 0;
}
bool gsVector3::isParalel(const gsVector3& p) const
{
	gsVector3 cross = gsVector3::cross(*this, p);
	bool paralel = cross.isZeroVector();
	return paralel;
}

void gsVector3::sendToOpenGL_Vertex(void) const {
	glVertex3f(x, y, z);
}
void gsVector3::sendToOpenGL_Normal(void) const {
	glNormal3f(x, y, z);
}
void gsVector3::sendToOpenGL_Color(void) const {
	glColor3f(x, y, z);
}

float gsVector3::dot(const gsVector3& a, const gsVector3& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
gsVector3 gsVector3::cross(const gsVector3& a, const gsVector3& b)
{
	float x = a.y * b.z - a.z * b.y;
	float y = a.z * b.x - a.x * b.z;
	float z = a.x * b.y - a.y * b.x;

	return gsVector3(x, y, z);
}

void gsVector3::operator +=(const gsVector3& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}
void gsVector3::operator -=(const gsVector3& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}
void gsVector3::operator *=(const float& rhs) {
	x *= rhs;
	y *= rhs;
	z *= rhs;
}
void gsVector3::operator /=(const float& rhs) {
	x /= rhs;
	y /= rhs;
	z /= rhs;
}

gsVector3 operator+(const gsVector3& lhs, const gsVector3& rhs) {
	return gsVector3(
		lhs.x + rhs.x, 
		lhs.y + rhs.y, 
		lhs.z + rhs.z);
}
gsVector3 operator-(const gsVector3& lhs, const gsVector3& rhs) {
	return gsVector3(
		lhs.x - rhs.x, 
		lhs.y - rhs.y, 
		lhs.z - rhs.z);
}
gsVector3 operator*(const gsVector3& lhs, const float& rhs) {
	return gsVector3(
		lhs.x * rhs, 
		lhs.y * rhs, 
		lhs.z * rhs);
}
gsVector3 operator/(const gsVector3& lhs, const float& rhs) {
	return gsVector3(
		lhs.x / rhs, 
		lhs.y / rhs, 
		lhs.z / rhs);
}

std::ostream& operator<<(std::ostream& os, const gsVector3& vector) {
	os << "(" << vector.x << ", " << vector.y << ", " << vector.y << ")";
	return os;
}