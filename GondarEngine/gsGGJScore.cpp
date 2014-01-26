#include "gsGGJScore.h"

void gsGGJScore::draw()
{
	for(int i = 0; i < numbers.getSize(); i++)
		numbers[i].draw();
}

void gsGGJScore::update()
{

}

gsGGJScore::gsGGJScore(void)
{
	for(int i = 0; i < numbers.getSize(); i++)
		numbers.add(gsGGJNumber());
}


gsGGJScore::~gsGGJScore(void)
{
	
}
