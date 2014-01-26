#include "gsGGJScore.h"
#include "gsGGJGame.h"
#include <math.h>


void gsGGJScore::draw()
{
	for(int i = 0; i < numbers.getSize() ; i++)
	{
		numbers.get(i)->draw();
	}
}

void gsGGJScore::update()
{
	if(oldScore != gsGGJGlobal_Points)
	{
		for (int i = 0; i < numbers.getSize(); i++)
		{
			numbers.get(i)->changeNumber(getNumberByIndex(i));
		}
		oldScore = gsGGJGlobal_Points;
	}
	
	
}

gsGGJScore::gsGGJScore(gsGGJGame *game) : gsGGJObject(game)
{
	oldScore = gsGGJGlobal_Points;
	for(int i = 0; i < 6; i++)
		numbers.add(new gsGGJNumber(getNumberByIndex(i),i,game));

}

int gsGGJScore::getNumberByIndex(int index)
{
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

