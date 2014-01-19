#include "gsVector3.h"


#include "gsLogger.h"

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

void gsVector3::makeUnitary(void)
{
	float len = magnitude();
	if (len != 0.0f)
	{
		x /= len;
		y /= len;
		z /= len;
	}
}

void gsVector3::print()
{
	GS_LOG("> " << x << " - " << y << " - " << z);
}

bool gsVector3::isZeroVector(void)
{
	return x == 0 && y == 0 && z == 0;
}

bool gsVector3::isParalel(gsVector3 p)
{
	gsVector3* cross = gsVector3::crossProduct(this, p);
	bool paralel = cross->isZeroVector();
	delete cross;

	return paralel;
}

GLfloat Point3D::magnitude(void)
{
	return sqrt(x * x + y * y + z * z);
}

GLfloat Point3D::angleTo(Point3D* p)
{
	GLfloat dot = Point3D::dot(this, p);
	GLfloat cosO = dot / this->magnitude() * p->magnitude();

	return acosf(cosO);
}

void Point3D::drawVertex3f(void)
{
	glVertex3f(x, y, z);
}

void Point3D::rotate(GLfloat angle, AxisEnum axis)
{
	if(angle == 0.0f)
	{
		return;
	}

	GLfloat newX = 0;
	GLfloat newY = 0;
	GLfloat newZ = 0;

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

void Point3D::operator+(Point3D* p)
{
	x += p->x;
	y += p->y;
	z += p->z;
}

void Point3D::operator-(Point3D* p)
{
	x -= p->x;
	y -= p->y;
	z -= p->z;
}

void Point3D::operator*(GLfloat value)
{
	x *= value;
	y *= value;
	z *= value;
}

GLfloat Point3D::dot(Point3D* a, Point3D* b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z;
}

Point3D* Point3D::vector(Point3D* a, Point3D* b)
{
	GLfloat x = b->x - a->x;
	GLfloat y = b->y - a->y;
	GLfloat z = b->z - a->z;

	return new Point3D(x, y, z);
}

Point3D* Point3D::crossProduct(Point3D* a, Point3D* b)
{
	GLfloat x = a->y * b->z - a->z * b->y;
	GLfloat y = a->z * b->x - a->x * b->z;
	GLfloat z = a->x * b->y - a->y * b->x;

	return new Point3D(x, y, z);
}

Point3D::~Point3D(void)
{ }