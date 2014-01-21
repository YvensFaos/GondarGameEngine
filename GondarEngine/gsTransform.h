#ifndef __GS_TRANSFORM__
#define __GS_TRANSFORM__

#include "gsVector2.h"
#include "gsVector3.h"
#include "gsLogger.h"
#include "gsColor.h"

// Classe que representa a posição, o tamanho e a orientação de um objeto do jogo.
class gsTransform  {
public:
	gsVector3 position; // A posição do objeto
	gsVector3 size;    // O tamanho do objeto
	gsVector3 rotation; // A orientação do objeto (em graus)
	gsVector3 speed;    // A velocidade do objeto
	gsVector2 textureCoordinates[4]; //Coordenadas de textura
	gsColor   tint;     // A cor do objeto

private:
	void _init(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsVector3 spd, gsVector2* texCoords, gsColor col);

public:
	gsTransform() {}

	gsTransform(gsVector3 pos, gsVector3 siz) {
		_init(pos, siz, gsVector3::zero(), gsVector3::zero(), 0, gsColor::white());
	}
	gsTransform(gsVector3 pos, gsVector3 siz, gsColor col) {
		_init(pos, siz, gsVector3::zero(), gsVector3::zero(), 0, col);
	}
	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsColor col) {
		_init(pos, siz, rot, gsVector3::zero(), 0, col);
	}
	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsVector3 spd, gsColor col) {
		_init(pos, siz, rot, spd, 0, col);
	}
	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsColor col, gsVector2* coords) {
		_init(pos, siz, rot, gsVector3::zero(), coords, col);
	}
	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsVector3 spd, gsColor col, gsVector2* coords) {
		_init(pos, siz, rot, spd, coords, col);
	}

	void applySpeed();
	void bounceAtScreenEdges();

	void setTextureCoordinates(gsVector2* coords);
};

#endif