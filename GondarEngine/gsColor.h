#ifndef __GS_COLOR__
#define __GS_COLOR__


#include "gsVector3.h"

class gsColor : public gsVector3
{
public:
	gsColor();
	gsColor(float r, float g, float b);

	void randomize();

	void setAsOpenGLColor();
};

#endif