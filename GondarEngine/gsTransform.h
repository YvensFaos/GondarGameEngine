#ifndef __GS_TRANSFORM__
#define __GS_TRANSFORM__


#include "gsVector3.h"
#include "gsColor.h"

// Classe que representa a posição, o tamanho e a orientação de um objeto do jogo.
class gsTransform  {
public:
	gsVector3 position; // A posição do objeto
	gsVector3 size;    // O tamanho do objeto
	gsVector3 rotation; // A orientação do objeto (em graus)
	gsColor   tint;     // A cor do objeto

	gsTransform() {}
	gsTransform(gsVector3 pos, gsVector3 siz, gsVector3 rot, gsColor col) {
		position = pos;
		size = siz;
		rotation = rot;
		tint = col;
	}
};

#endif