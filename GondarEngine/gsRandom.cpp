#include "gsRandom.h"
#include <stdlib.h> 

int gSeed = 0;

#define DEFAULT_SEED 1373

void gsRandom::init()
{
	gSeed = DEFAULT_SEED;
	srand(gSeed);
}

bool gsRandom::nextBool()
{
	bool value = (rand() % 2) == 0;
	return value;
}

int gsRandom::nextInt(int min, int max)
{
	int value = rand() % (max - min) + min;
	return value;
}

double gsRandom::nextDouble()
{
	double value = rand() / (double)RAND_MAX;;
	return value;
}

bool gsRandom::chance(int chance)
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