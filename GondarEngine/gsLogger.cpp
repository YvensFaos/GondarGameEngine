#include "gsLogger.h"

#include "GLFW\glfw3.h"
#include <iostream>

using namespace std;

void glfwErrorCallback(int error, const char* description)
{
	GS_LOG("GLFW Error (Code: " << error << "): " << description);
}

void gsLogger::init() {
	glfwSetErrorCallback(glfwErrorCallback);
}

void gsLogger::log(const stringstream& message) {
	cout << message.str() << '\n';
}