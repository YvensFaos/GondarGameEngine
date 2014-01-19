#ifndef __GS_COLOR__
#define __GS_COLOR__


#include "gsVector3.h"

class gsColor : public gsVector3
{
public:
	gsColor();
	gsColor(float r, float g, float b);

	void randomize();

public:
	static gsColor white() { return gsColor(1, 1, 1); }
	static gsColor black() { return gsColor(0, 0, 0); }
	static gsColor red() { return gsColor(1, 0, 0); }
	static gsColor blue() { return gsColor(0, 1, 0); }
	static gsColor green() { return gsColor(0, 0, 1); }
};

#endif