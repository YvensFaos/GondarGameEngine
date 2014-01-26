#include "gsGGJScore.h"
#include "gsGGJGame.h"
#include <math.h>

/*
void gsGGJScore::draw()
{
	for(int i = 0; i < numbers.getSize() ; i++)
	{
		numbers.get(i)->draw();
	}
}

void gsGGJScore::update()
{
	for (int i = 0; i < numbers.getSize(); i++)
	{
		delete numbers.get(i);
	}
	numbers.clear();
	for(int i = 0; i < 6; i++)
			numbers.add(new gsGGJNumber(getNumberByIndex(i),i,game));
}

gsGGJScore::gsGGJScore(gsGGJGame *game) : gsGGJObject(game)
{
	for(int i = 0; i < 6; i++)
		numbers.add(new gsGGJNumber(getNumberByIndex(i),i,game));

}

int gsGGJScore::getNumberByIndex(int index)
{
	float aux;
	aux = gsGGJGlobal_Points % (int) pow(10,index + 1);
	aux = aux / pow(10,index );
	return (int) aux;
}


gsGGJScore::~gsGGJScore(void)
{
	for (int i = 0; i < numbers.getSize(); i++)
	{
		delete numbers.get(i);
	}
}
*/
