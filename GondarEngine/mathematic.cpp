#include "mathematics.h"

#include <ctime>
#include <stdlib.h>

Mathematic::Mathematic(void)
{ 
	srand(time(0));
}

float Mathematic::random(void)
{
	return (rand() % 100 + 1)/100.0f;
}

float Mathematic::random(int minValue, int maxValue)
{
	return rand() % (maxValue - minValue) + minValue;
}