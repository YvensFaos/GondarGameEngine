#ifndef __GS_TRANSFORM__
#define __GS_TRANSFORM__

#include "gsVector2.h"
#include "gsVector3.h"
#include "gsColor.h"

// Classe que representa a posição, o tamanho e a orientação de um objeto do jogo.
class gsTransform  {
public:
	gsVector3 position; // A posição do objeto
	gsVector3 size;    // O tamanho do objeto
	gsVector3 rotation; // A orientação do objeto (em graus)
	gsVector2 textureCoordinates[4]; //Coordenadas de textura
	gsColor   tint;     // A cor do objeto

	gsTransform() {}

	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsColor col) {
		position = pos;
		size = siz;
		rotation = rot;
		tint = col;

		textureCoordinates[0] = gsVector2(0, 1);
		textureCoordinates[1] = gsVector2(1, 1);
		textureCoordinates[2] = gsVector2(1, 0);
		textureCoordinates[3] = gsVector2(0, 0);
	}

	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsColor col, gsVector2 coords[4]) {
		position = pos;
		size = siz;
		rotation = rot;
		tint = col;

		textureCoordinates[0] = coords[0];
		textureCoordinates[1] = coords[1];
		textureCoordinates[2] = coords[2];
		textureCoordinates[3] = coords[3];
	}
};

#endif