#ifndef __GS_COLOR__
#define __GS_COLOR__


#include "gsVector3.h"

class gsColor {
public:
	float r;
	float g;
	float b;
	float a;

	gsColor();
	gsColor(float r, float g, float b, float a = 1.0f);

	void randomize();
	void sendToOpenGL_Color(void) const;

	void operator +=(const gsColor& rhs);
	void operator -=(const gsColor& rhs);
	void operator *=(const gsColor& rhs);
	void operator /=(const gsColor& rhs);
	void operator *=(const float& rhs);
	void operator /=(const float& rhs);

public:
	static gsColor white(float a = 1.0f) { return gsColor(1, 1, 1, a); }
	static gsColor black(float a = 1.0f) { return gsColor(0, 0, 0, a); }

	static gsColor red(float a = 1.0f) { return gsColor(1, 0, 0, a); }
	static gsColor green(float a = 1.0f) { return gsColor(0, 1, 0, a); }
	static gsColor blue(float a = 1.0f) { return gsColor(0, 0, 1, a); }

	static gsColor magenta(float a = 1.0f) { return gsColor(1, 0, 1, a); }
	static gsColor yellow(float a = 1.0f) { return gsColor(1, 1, 0, a); }
	static gsColor cyan(float a = 1.0f) { return gsColor(0, 1, 1, a); }
};

bool operator==(const gsColor& lhs, const gsColor& rhs);
bool operator!=(const gsColor& lhs, const gsColor& rhs);

gsColor operator+(const gsColor& lhs, const gsColor& rhs);
gsColor operator-(const gsColor& lhs, const gsColor& rhs);
gsColor operator*(const gsColor& lhs, const gsColor& rhs);
gsColor operator/(const gsColor& lhs, const gsColor& rhs);
gsColor operator*(const gsColor& lhs, const float& rhs);
gsColor operator/(const gsColor& lhs, const float& rhs);

// To String
std::ostream& operator<<(std::ostream& os, const gsVector3& vector);

#endif