#include "gsGGJScore.h"
#include "gsGGJGame.h"
#include <math.h>


gsGGJScore::gsGGJScore(gsGGJGame *game) : gsGGJObject(game) {
	oldScore = gsGGJGlobal_Points;
	for(int i = 0; i < 6; i++) {
		numbers.add(new gsGGJNumber(getNumberByIndex(i),i,game));
	}
}
gsGGJScore::~gsGGJScore(void) {
	for (int i = 0; i < numbers.getSize(); i++) {
		delete numbers.get(i);
	}
}


void gsGGJScore::update() {
	if(oldScore != gsGGJGlobal_Points) {
		for (int i = 0; i < numbers.getSize(); i++) {
			numbers.get(i)->changeNumber(getNumberByIndex(i));
		}
		oldScore = gsGGJGlobal_Points;
	}
}
void gsGGJScore::draw() {
	for(int i = 0; i < numbers.getSize() ; i++) {
		numbers.get(i)->draw();
	}
}

int gsGGJScore::getNumberByIndex(int index) {
	int aux = gsGGJGlobal_Points % (int) pow(10, index + 1);
	aux = aux / (int)pow(10,index);
	return aux;
}

