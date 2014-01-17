#ifndef __GS_INPUT__
#define __GS_INPUT__

// a ser definida.
// requer um enum com as teclas e quatro métodos:
// - está pressionado, está solto, acabou de ser pressionado e acabou de ser solto.

class gsInput
{
public:
	static void init();

	static void update();
};

#endif