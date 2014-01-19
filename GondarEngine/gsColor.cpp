#include "gsColor.h"


#include "gsRandom.h"
#include <Windows.h>
#include <gl\GL.h>

gsColor::gsColor() {
	x = y = z = 0; // preto
}
gsColor::gsColor(float r, float g, float b) {
	x = r;
	y = g;
	z = b;
}

void gsColor::randomize() {
	x = gsRandom::nextDouble();
	y = gsRandom::nextDouble();
	z = gsRandom::nextDouble();
}

void gsColor::setAsOpenGLColor() {
	glColor3f(x, y, z);
}
