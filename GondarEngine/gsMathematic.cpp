#include "gsMathematics.h"

#include <ctime>
#include <stdlib.h>

gsMathematic::gsMathematic(void)
{ 
	srand(time(0));
}

float gsMathematic::random(void)
{
	return (rand() % 100 + 1)/100.0f;
}

float gsMathematic::random(int minValue, int maxValue)
{
	return rand() % (maxValue - minValue) + minValue;
}