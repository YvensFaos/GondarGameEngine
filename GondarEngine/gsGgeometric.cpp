#include "gsGeometric.h"

#include <stdio.h>
#include <Windows.h>
#include <GL\GLU.h>
#include <math.h>

#include "gsMathematics.h"

Point3D* defaultColor = new Point3D(0.42f, 0.85f, 0.5f);
gsMathematic* mathematic = new gsMathematic();

//Objeto Point3D



//Objecto Triangle



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
