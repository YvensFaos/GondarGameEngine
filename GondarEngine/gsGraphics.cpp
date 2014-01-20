#include "gsGraphics.h"

#include "gsOpenGL.h"
#include "gsWindow.h"

int gResX;
int gResY;

void gsGraphics::init(int resX, int resY) {
	gResX = resX;
	gResY = resY;

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void gsGraphics::dispose() {
	gResX = 0;
	gResY = 0;
}

void gsGraphics::beginDraw() {
	glfwGetFramebufferSize(gsWindow::getWindow(), &gResX, &gResY);
    glViewport(0, 0, gResX, gResY);

    glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	glOrtho(0, gResX, gResY, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void gsGraphics::drawQuad(const gsTransform& transform) {
	gsVector3 corners[4];
	corners[0] = transform.position;
	corners[1] = transform.position + gsVector3(transform.size.x, 0, 0);
	corners[2] = transform.position + gsVector3(transform.size.x, transform.size.y, 0);
	corners[3] = transform.position + gsVector3(0, transform.size.y, 0);

	glBegin(GL_QUADS);
		transform.tint.sendToOpenGL_Color();
		corners[0].sendToOpenGL_Vertex();
		corners[1].sendToOpenGL_Vertex();
		corners[2].sendToOpenGL_Vertex();
		corners[3].sendToOpenGL_Vertex();
	glEnd();
}
void gsGraphics::endDraw() {
	glfwSwapBuffers(gsWindow::getWindow());
    glfwPollEvents();
}