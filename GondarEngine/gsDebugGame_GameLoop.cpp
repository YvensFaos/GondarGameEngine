#include "gsDebugGame_Gameloop.h"

#include "gsLogger.h"
#include "gsClock.h"


void gsDebugGame_GameLoop::start() {
	GS_LOG("Jogo Inicializado\n");
	frameCounter = 0;
}
void gsDebugGame_GameLoop::end() {
	float time = gsClock::getTotalTime();
	float fps = frameCounter / time;


	GS_LOG("\nJogo finalizado");
	GS_LOG("Frames: " << frameCounter);
	GS_LOG("Tempo total: " << time);
	GS_LOG("FPS: " << fps << "\n\n");
}

bool gsDebugGame_GameLoop::isRunning() {
	return frameCounter < 120;
}

void gsDebugGame_GameLoop::update() {
	GS_LOG("Frame: " << frameCounter << ", delta time: " << gsClock::getDeltaTime());
	frameCounter++;
}
void gsDebugGame_GameLoop::draw() {
	// nada
}