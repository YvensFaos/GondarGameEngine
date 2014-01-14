#ifndef __GLINPUT__
#define __GLINPUT__

struct GLFWwindow;

class GlInput
{
public:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif