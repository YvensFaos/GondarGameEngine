#include "gsColor.h"


#include "gsRandom.h"
#include "gsOpenGL.h"

gsColor::gsColor() {
	r = g = b = a = 0;
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

void gsColor::operator +=(const gsColor& rhs) {
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	a += rhs.a;
}
void gsColor::operator -=(const gsColor& rhs) {
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	a -= rhs.a;
}
void gsColor::operator *=(const gsColor& rhs) {
	r *= rhs.r;
	g *= rhs.g;
	b *= rhs.b;
	a *= rhs.a;
}
void gsColor::operator /=(const gsColor& rhs) {
	r /= rhs.r;
	g /= rhs.g;
	b /= rhs.b;
	a /= rhs.a;
}
void gsColor::operator *=(const float& rhs) {
	r *= rhs;
	g *= rhs;
	b *= rhs;
	a *= rhs;
}
void gsColor::operator /=(const float& rhs) {
	r /= rhs;
	g /= rhs;
	b /= rhs;
	a /= rhs;
}

bool operator==(const gsColor& lhs, const gsColor& rhs) {
	bool output;
	output &= lhs.r == rhs.r;
	output &= lhs.g == rhs.g;
	output &= lhs.b == rhs.b;
	output &= lhs.a == rhs.a;
	return output;
}
bool operator!=(const gsColor& lhs, const gsColor& rhs) {
	return !(operator==(lhs, rhs)); // implementando um operador utilizando outro
}

gsColor operator+(const gsColor& lhs, const gsColor& rhs) {
	return gsColor(
		lhs.r + rhs.r, 
		lhs.g + rhs.g, 
		lhs.b + rhs.b, 
		lhs.a + rhs.a);
}
gsColor operator-(const gsColor& lhs, const gsColor& rhs) {
	return gsColor(
		lhs.r - rhs.r, 
		lhs.g - rhs.g, 
		lhs.b - rhs.b, 
		lhs.a - rhs.a);
}
gsColor operator*(const gsColor& lhs, const gsColor& rhs) {
	return gsColor(
		lhs.r * rhs.r, 
		lhs.g * rhs.g, 
		lhs.b * rhs.b, 
		lhs.a * rhs.a);
}
gsColor operator/(const gsColor& lhs, const gsColor& rhs) {
	return gsColor(
		lhs.r / rhs.r, 
		lhs.g / rhs.g, 
		lhs.b / rhs.b, 
		lhs.a / rhs.a);
}
gsColor operator*(const gsColor& lhs, const float& rhs) {
	return gsColor(
		lhs.r * rhs, 
		lhs.g * rhs, 
		lhs.b * rhs,
		lhs.a * rhs);
}
gsColor operator/(const gsColor& lhs, const float& rhs) {
	return gsColor(
		lhs.r / rhs, 
		lhs.g / rhs, 
		lhs.b / rhs,
		lhs.a / rhs);
}

std::ostream& operator<<(std::ostream& os, const gsColor& color) {
	os << "(" << color.r << ", " << color.g << ", " << color.b <<  ", " << color.a << ")";
	return os;
}