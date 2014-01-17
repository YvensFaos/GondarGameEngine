#include "gsClock.h"

#include <Windows.h>

LARGE_INTEGER gClockFrequency;

LARGE_INTEGER gStartTime;   // Tempo quando o clock foi inicializado
LARGE_INTEGER gLastTime;    // Tempo no frame passado
LARGE_INTEGER gCurrentTime; // Tempo atual

double gTotalTime; // Tempo total decorrido em segundos
double gDeltaTime; // Tempo decorrido entre os dois últimos updates. Em segundos.


void gsClock::init()
{
	QueryPerformanceFrequency(&gClockFrequency);
	QueryPerformanceCounter(&gStartTime);

	gCurrentTime = gStartTime;
}

void gsClock::update()
{
	gLastTime = gCurrentTime;

	QueryPerformanceCounter(&gCurrentTime);

	gTotalTime = (gCurrentTime.QuadPart - gStartTime.QuadPart) / (double)gClockFrequency.QuadPart;;
	gDeltaTime = (gCurrentTime.QuadPart - gLastTime.QuadPart) / (double)gClockFrequency.QuadPart;
}

double gsClock::getTotalTime()
{
	return gTotalTime;
}
double gsClock::getDeltaTime()
{
	return gDeltaTime;
}
