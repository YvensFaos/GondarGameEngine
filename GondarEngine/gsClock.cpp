#include "gsClock.h"


#include "GLFW\glfw3.h"

double gTotalTime; // Tempo total decorrido em segundos
double gDeltaTime; // Tempo decorrido entre os dois últimos updates. Em segundos.


void gsClock::init()
{
	gTotalTime = glfwGetTime();
	gDeltaTime = gTotalTime;
}

void gsClock::update()
{
	double newTime = glfwGetTime();
	gDeltaTime = newTime - gTotalTime;
	gTotalTime = newTime;
}

double gsClock::getTotalTime()
{
	return gTotalTime;
}
double gsClock::getDeltaTime()
{
	return gDeltaTime;
}
