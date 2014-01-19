#include "gsTriangle.h"

#include "gsColor.h"

gsTriangle::gsTriangle(void) {}

gsTriangle::gsTriangle(gsVector3 _a, gsVector3 _b, gsVector3 _c)
{
	a = _a;
	b = _b;
	c = _c;

	color = gsColor();
	calculateNormal();
}

gsTriangle::~gsTriangle(void) {}

void gsTriangle::calculateNormal(void)
{
	gsVector3 p1 = gsVector3(a.x - b.x, b);
	gsVector3 p2 = gsVector3(a, c);

	normal = Point3D::crossProduct(p1, p2);
	normal->makeUnitary();
}

void gsTriangle::drawTriangle(void)
{
	glBegin(GL_TRIANGLES);		
		glColor3f(color->x, color->y, color->z);
		glNormal3f(normal->x, normal->y, normal->z);
		a->drawVertex3f();
		b->drawVertex3f();
		c->drawVertex3f();
	glEnd();
}

void gsTriangle::drawTriangleLines(void)
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

void gsTriangle::print(void)
{
	printf("Triangle\n");
	a->print();
	b->print();
	c->print();
	printf("\n");
}

gsTriangle* gsTriangle::randomTriangle(void)
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

void gsTriangle::translate(Point3D* translation)
{
	this->a->operator+(translation);
	this->b->operator+(translation);
	this->c->operator+(translation);
}

void gsTriangle::rotate(GLfloat angle, AxisEnum axis)
{
	a->rotate(angle, axis);
	b->rotate(angle, axis);
	c->rotate(angle, axis);

	calculateNormal();
}