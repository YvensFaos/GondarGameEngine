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
	gsVector2* textureCoordinates; //Coordenadas de textura
	gsColor   tint;     // A cor do objeto

	gsTransform() {}

	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsColor col) {
		position = pos;
		size = siz;
		rotation = rot;
		tint = col;
		
		textureCoordinates = new gsVector2[4];

		textureCoordinates[0] = gsVector2(0, 1);
		textureCoordinates[1] = gsVector2(1, 1);
		textureCoordinates[2] = gsVector2(1, 0);
		textureCoordinates[3] = gsVector2(0, 0);

		/*
		textureCoordinates[0] = gsVector2(0.5f, 0.2f);
		textureCoordinates[1] = gsVector2(0.2f, 0.2f);
		textureCoordinates[2] = gsVector2(0.2, 0.5f);
		textureCoordinates[3] = gsVector2(0.5f, 0.5f);
		*/
	}

	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsColor col, gsVector2* coords) {
		position = pos;
		size = siz;
		rotation = rot;
		tint = col;

		textureCoordinates = new gsVector2[4];
		textureCoordinates[0] = coords[0];
		textureCoordinates[1] = coords[1];
		textureCoordinates[2] = coords[2];
		textureCoordinates[3] = coords[3];
	}

	void setTextureCoordinates(gsVector2* coords)
	{
		textureCoordinates[0] = coords[0];
		textureCoordinates[1] = coords[1];
		textureCoordinates[2] = coords[2];
		textureCoordinates[3] = coords[3];
	}
};

#endif