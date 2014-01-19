#include "gsDebugGame_Graphics.h"

#include "gsLogger.h"
#include "gsClock.h"
#include "gsRandom.h"
#include "gsOpenGL.h"


void gsDebugGame_Graphics::start() {
	GS_LOG("Teste Inicializado\n");
	frameCounter = 0;
}
void gsDebugGame_Graphics::end() {
	GS_LOG("Teste Finalizado");
}

bool gsDebugGame_Graphics::isRunning() {
	return frameCounter < 600;
}

void gsDebugGame_Graphics::update() {
	frameCounter++;
}
void gsDebugGame_Graphics::draw() {
	glBegin(GL_QUADS);

	glColor3f(1, 0, 0);
	glVertex3f(-0.5, -0.5, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0.5, -0.5, 0);
	glColor3f(1, 1, 1);
	glVertex3f(0.5, 0.5, 0);
	glColor3f(0, 0, 1);
	glVertex3f(-0.5, 0.5, 0);
	glEnd();
}