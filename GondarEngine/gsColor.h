#ifndef __GS_COLOR__
#define __GS_COLOR__


#include "gsVector3.h"

class gsColor
{
public:
	float r;
	float g;
	float b;
	float a;

	gsColor();
	gsColor(float r, float g, float b);
	gsColor(float r, float g, float b, float a);

	void randomize();
	void sendToOpenGL_Color(void) const;

public:
	static gsColor white() { return gsColor(1, 1, 1); }
	static gsColor black() { return gsColor(0, 0, 0); }
	static gsColor red() { return gsColor(1, 0, 0); }
	static gsColor green() { return gsColor(0, 1, 0); }
	static gsColor blue() { return gsColor(0, 0, 1); }

	static gsColor magenta() { return gsColor(1, 0, 1); }
	static gsColor yellow() { return gsColor(1, 1, 0); }
	static gsColor cyan() { return gsColor(0, 1, 1); }
};

#endif