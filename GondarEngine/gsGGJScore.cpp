#include "gsGGJScore.h"
#include "gsGGJGame.h"
#include <math.h>


gsGGJScore::gsGGJScore(gsGGJGame *game) : gsGGJObject(game) {
	oldScore = gsGGJGlobal_Points;
	for(int i = 0; i < 6; i++) {
		numbers.add(new gsGGJNumber(getNumberByIndex(0, i), i, game));
	}

	transform = gsTransform(gsVector3::zero(), gsVector3::zero());
	transform.position.z = -.5f;
}
gsGGJScore::~gsGGJScore(void) {
	for (int i = 0; i < numbers.getSize(); i++) {
		delete numbers.get(i);
	}
}

void gsGGJScore::setScore(int score) {
	for (int i = 0; i < numbers.getSize(); i++) {
		numbers.get(i)->changeNumber(getNumberByIndex(score, i));
	}
	oldScore = gsGGJGlobal_Points;
}

void gsGGJScore::update() {}
void gsGGJScore::draw() {
	for(int i = 0; i < numbers.getSize() ; i++) {
		numbers.get(i)->transform.position += this->transform.position;
		numbers.get(i)->draw();
		numbers.get(i)->transform.position -= this->transform.position;
	}
}

int gsGGJScore::getNumberByIndex(int number, int index) {
	int aux = number % (int) pow(10, index + 1);
	aux = aux / (int)pow(10,index);
	return aux;
}

