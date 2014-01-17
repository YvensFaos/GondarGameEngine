#include "gsInput.h"

#include "gsWindow.h"
#include "GLFW\glfw3.h"

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
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
	glfwSetKeyCallback(gsWindow::getWindow(), glfwKeyCallback);
}

void gsInput::update() {

}