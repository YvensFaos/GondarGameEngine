#include "random.h"
#include <stdlib.h> 

int gSeed = 0;

#define DEFAULT_SEED 1373

void Random::init()
{
	gSeed = DEFAULT_SEED;
	srand(gSeed);
}

bool Random::nextBool()
{
	int value = rand() % 2;
	return value;
}

int Random::nextInt(int min, int max)
{
	int value = rand() % (max - min) + min;
	return value;
}

double Random::nextDouble()
{
	double value = (rand() % 1000 + 1) / 1000.f;
}

bool Random::chance(int chance)
{
	if(chance > 100 || chance <= 0)
	{
		return false;
	}
	else
	{
		int value = nextInt(0, 101);
		if(value > chance)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}