#include "gsTriangle.h"


#include "gsColor.h"
#include "gsOpenGL.h"

gsTriangle::gsTriangle()
{
	a = gsVector3::zero();
	b = gsVector3::zero();
	c = gsVector3::zero();

	color = gsColor::white();
	calculateNormal();
}
gsTriangle::gsTriangle(gsVector3 _a, gsVector3 _b, gsVector3 _c)
{
	a = _a;
	b = _b;
	c = _c;

	color = gsColor::white();
	calculateNormal();
}

void gsTriangle::calculateNormal(void)
{
	gsVector3 p1 = a - b;
	gsVector3 p2 = a - c;

	normal = gsVector3::cross(p1, p2);
	normal.normalize();
}

void gsTriangle::drawSolid(void)
{
	glBegin(GL_TRIANGLES);		
		color.sendToOpenGL_Color();
		normal.sendToOpenGL_Normal();
		a.sendToOpenGL_Vertex();
		b.sendToOpenGL_Vertex();
		c.sendToOpenGL_Vertex();
	glEnd();
}
void gsTriangle::drawWireFrame(void)
{
	gsColor::white().sendToOpenGL_Color();
	glBegin(GL_LINES);
		a.sendToOpenGL_Vertex();
		b.sendToOpenGL_Vertex();

		b.sendToOpenGL_Vertex();
		c.sendToOpenGL_Vertex();

		a.sendToOpenGL_Vertex();
		c.sendToOpenGL_Vertex();
	glEnd();
}

void gsTriangle::translate(const gsVector3& amount)
{
	a += amount;
	b += amount;
	c += amount;
}
void gsTriangle::rotate(float angle, gsAxis axis)
{
	a.rotate(angle, axis);
	b.rotate(angle, axis);
	c.rotate(angle, axis);

	calculateNormal();
}

std::ostream& operator<<(std::ostream& os, const gsTriangle& triangle) {
	os << "(Triangle: {" << triangle.a << ", " << triangle.b << ", " << triangle.c << "})";
	return os;
}