#include "geometric.h"

#include <stdio.h>
#include <Windows.h>
#include <GL\GLU.h>
#include <math.h>

#include "mathematics.h"

Point3D* defaultColor = new Point3D(0.42f, 0.85f, 0.5f);
Mathematic* mathematic = new Mathematic();

//Objeto Point3D

Point3D::Point3D(void)
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Point3D::Point3D(GLfloat points[3])
{
	x = points[0];
	y = points[1];
	z = points[2];
}

Point3D::Point3D(GLfloat _x, GLfloat _y, GLfloat _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Point3D* Point3D::copy()
{
	return new Point3D(x, y, z);
}

void Point3D::makeUnitary(void)
{
	GLfloat len = magnitude();
	if (len != 0.0f)
	{
		x /= len;
		y /= len;
		z /= len;
	}
}

void Point3D::print()
{
	printf("> %f %f %f\n", x, y, z);
}

bool Point3D::isZeroVector(void)
{
	return x == 0 && y == 0 && z == 0;
}

bool Point3D::isParalel(Point3D* p)
{
	Point3D* cross = Point3D::crossProduct(this, p);
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

//Objecto Triangle

Triangle3D::Triangle3D(void)
{ }

Triangle3D::Triangle3D(Point3D* _a, Point3D* _b, Point3D* _c)
{
	a = _a->copy();
	b = _b->copy();
	c = _c->copy();

	color = defaultColor->copy();
	calculateNormal();
}

Triangle3D::~Triangle3D(void)
{
	delete a;
	delete b;
	delete c;
	delete normal;
	delete color;
}

void Triangle3D::calculateNormal(void)
{
	Point3D* p1 = Point3D::vector(a, b);
	Point3D* p2 = Point3D::vector(a, c);

	normal = Point3D::crossProduct(p1, p2);
	normal->makeUnitary();
}

void Triangle3D::drawTriangle(void)
{
	glBegin(GL_TRIANGLES);		
		glColor3f(color->x, color->y, color->z);
		glNormal3f(normal->x, normal->y, normal->z);
		a->drawVertex3f();
		b->drawVertex3f();
		c->drawVertex3f();
	glEnd();
}

void Triangle3D::drawTriangleLines(void)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		a->drawVertex3f();
		b->drawVertex3f();

		b->drawVertex3f();
		c->drawVertex3f();

		a->drawVertex3f();
		c->drawVertex3f();
	glEnd();
}

void Triangle3D::print(void)
{
	printf("Triangle\n");
	a->print();
	b->print();
	c->print();
	printf("\n");
}

Triangle3D* Triangle3D::randomTriangle(void)
{
	GLfloat w = mathematic->random(0, 5);
	GLfloat h = mathematic->random(0, 5);
	GLfloat z = 0;

	//printf("-> %f e %f\n", w, h);

	Point3D* a = new Point3D(0.f, 0.f, z);
	Point3D* b = new Point3D(w, 0.f, z);
	Point3D* c = new Point3D(w/2, h, z);

	Triangle3D* triangle = new Triangle3D(a,b,c);

	GLint pos = (mathematic->random(0, 2) == 0)? 1 : -1;
	w = pos*mathematic->random(0, 10);
	pos = (mathematic->random(0, 2) == 0)? 1 : -1;
	h = pos*mathematic->random(0, 10);

	//printf("->r %f e %f\n", w, h);

	Point3D* translation = new Point3D(w,h,0);
	triangle->translate(translation);

	triangle->color = Color3D::randomColor();

	delete a;
	delete b;
	delete c;
	delete translation;

	return triangle;
}

void Triangle3D::translate(Point3D* translation)
{
	this->a->operator+(translation);
	this->b->operator+(translation);
	this->c->operator+(translation);
}

void Triangle3D::rotate(GLfloat angle, AxisEnum axis)
{
	a->rotate(angle, axis);
	b->rotate(angle, axis);
	c->rotate(angle, axis);

	calculateNormal();
}

//Objecto Plane

Plane3D::Plane3D(void)
{ 
	wireFrame = false;
}

Plane3D::Plane3D(Point3D* _a, Point3D* _normal)
{
	a = _a->copy();
	normal = _normal->copy();

	color = defaultColor->copy();

	wireFrame = true;
}

Plane3D::~Plane3D(void)
{
	delete a;
	delete normal;
	delete color;
}

void Plane3D::createWireframe(void)
{
	if(normal->isZeroVector())
	{
		printf(">> ERRO!");
		return;
	}

	GLfloat alpha1 = 0.0f;
	if(normal->z == 0.0f)
	{
		if(normal->y == 0.0f)
		{
			p1 = new Point3D(0.0f, 1.0, 0.0f);
		}
		else
		{
			alpha1 = -1*normal->x/normal->y;
			p1 = new Point3D(1.0f, alpha1, 0.0f);
		}
	}
	else
	{
		alpha1 = -1*normal->x/normal->z;
		p1 = new Point3D(1.0f, 0.0f, alpha1);
	}

	p2 = Point3D::crossProduct(normal, p1);

	//p1->print();
	//p2->print();
	//printf("teste %f %f", Point3D::dot(normal, p1), Point3D::dot(normal, p2));
}

void Plane3D::setWireframe(bool wireFrame)
{
	this->wireFrame = wireFrame;
	if(wireFrame)
	{
		createWireframe();
	}
}

void Plane3D::drawPlane(void)
{
	if(wireFrame)
	{
		glColor3f(1.0, 1.0, 1.0);

		Point3D* p = new Point3D();

		glBegin(GL_LINES);
		for (GLfloat i = -planeSize; i <= planeSize; i += 1.0f) {
			p = parametricPoint3D(i, planeSize);
			p->drawVertex3f();

			p = parametricPoint3D(i, -planeSize);
			p->drawVertex3f();

			p = parametricPoint3D(planeSize, i);
			p->drawVertex3f();

			p = parametricPoint3D(-planeSize, i);
			p->drawVertex3f();
		}

		glEnd();

		delete p;
	}
	else
	{

	}
}

Point3D* Plane3D::parametricPoint3D(GLfloat s, GLfloat t)
{
	GLfloat x = normal->x + s*p1->x + t*p2->x;
	GLfloat y = normal->y + s*p1->y + t*p2->y;
	GLfloat z = normal->z + s*p1->z + t*p2->z;

	return new Point3D(x, y, z);
}

//Class Color3D

Point3D* Color3D::randomColor(void)
{
	GLfloat red = mathematic->random();
	GLfloat green = mathematic->random();
	GLfloat blue = mathematic->random();

	Point3D* color = new Point3D(red,green,blue);

	return color;
}

Point3D* Color3D::getColor(GLfloat red, GLfloat green, GLfloat blue)
{
	Point3D* color = new Point3D(red, green, blue);

	return color;
}
