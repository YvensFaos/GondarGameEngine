#include "gsWindow.h"

#include "gsConfig.h"
#include "gsMacros.h"
#include "GLFW\glfw3.h"


GLFWwindow *gWindow;

void gsWindow::init(int resX, int resY) {
    if (!glfwInit())
	{
		gsAssert(0);
		exit(EXIT_FAILURE);
	}

	//Criação da janela de renderização
	gWindow = glfwCreateWindow(resX, resY, GS_ENGINE_NAME GS_ENGINE_VERSION, NULL, NULL);
    if (!gWindow)
    {
		gsAssert(0);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(gWindow);
   
    glfwGetFramebufferSize(gWindow, &resX, &resY);
	float ratio = resX / (float) resY;

	glfwSetWindowPos(gWindow, GS_WINDOW_POS_X, GS_WINDOW_POS_Y);
}
void gsWindow::dispose() {
	glfwDestroyWindow(gWindow);
    glfwTerminate();
}

GLFWwindow* gsWindow::getWindow() {
	return gWindow;
}