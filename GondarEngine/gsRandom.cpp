#include "gsRandom.h"
#include <stdlib.h> 

int gSeed = 0;

//#define DEFAULT_SEED 0x1534ff65
#ifndef DEFAULT_SEED
#include <ctime>
#define DEFAULT_SEED time(0)
#endif

// Valor utilizado para melhorar a distribuição do nextInt

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
	int value = rand() % ((max + 1) - min) + min;
	return value;
}

double gsRandom::nextDouble()
{
	double value = rand() / (double)RAND_MAX;;
	return value;
}

bool gsRandom::chance(int chance)
{
	if(chance > 100) return true;
	if(chance < 0) return false;

	int value = nextInt(0, 100);
	if(value < chance)
	{
		return true;
	}
	else
	{
		return false;
	}
}