#ifndef __GS_INPUT__
#define __GS_INPUT__

// a ser definida.
// requer um enum com as teclas e quatro métodos:
// - está pressionado, está solto, acabou de ser pressionado e acabou de ser solto.
// - preciso de um map/hashmap para implementar esta classe para todos os buttones do teclado
// - suporte pra mouse e joystick?

class gsInput
{
public:
	static void init();

	static void update();
};

#endif