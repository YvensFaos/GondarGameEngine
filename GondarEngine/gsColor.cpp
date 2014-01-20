#include "gsColor.h"


#include "gsRandom.h"
#include "gsOpenGL.h"

gsColor::gsColor() {
	r = g = b = a = 0;
}
gsColor::gsColor(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = 1;
}
gsColor::gsColor(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void gsColor::randomize() {
	r = gsRandom::nextDouble();
	g = gsRandom::nextDouble();
	b = gsRandom::nextDouble();
	a = gsRandom::nextDouble();
}

void gsColor::sendToOpenGL_Color(void) const {
	glColor4f(r, g, b, a);
}