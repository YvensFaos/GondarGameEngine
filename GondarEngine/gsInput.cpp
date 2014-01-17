#include "gsInput.h"

#include "GLFW\glfw3.h"

void gsInput::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}
}

void gsInput::init() {

}

void gsInput::update() {

}