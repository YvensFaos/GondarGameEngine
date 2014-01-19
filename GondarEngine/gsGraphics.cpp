#include "gsGraphics.h"

#include "gsOpenGL.h"
#include "gsWindow.h"

int gResX;
int gResY;

void gsGraphics::init(int resX, int resY) {
	gResX = resX;
	gResY = resY;
}
void gsGraphics::dispose() {
	gResX = 0;
	gResY = 0;
}

void gsGraphics::beginDraw() {
	glfwGetFramebufferSize(gsWindow::getWindow(), &gResX, &gResY);
    glViewport(0, 0, gResX, gResY);

    glClear(GL_COLOR_BUFFER_BIT);


    /*
	float ratio = gResX / (float) gResY;

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	gluPerspective(camera->ffov, ratio, camera->fnear, camera->ffar);
	camera->cameraLookAt();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();*/
}
void gsGraphics::endDraw() {
	glfwSwapBuffers(gsWindow::getWindow());
    glfwPollEvents();
}