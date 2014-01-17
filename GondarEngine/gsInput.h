#ifndef __GS_INPUT__
#define __GS_INPUT__

struct GLFWwindow;

// a ser definida.
// requer um enum com as teclas e quatro métodos:
// - está pressionado, está solto, acabou de ser pressionado e acabou de ser solto.

class gsInput
{
public:
	static void init();

	static void update();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif