#include "gsShootEmUpGame.h"

#include "gsLogger.h"
#include "gsInput.h"
#include "gsGraphics.h"
#include "gsOpenGL.h"


void gsShootEmUpGame::start() {
	GS_LOG("Shoot 'em Up Game Initialized\n");
	// Criar objetos do jogo aqui
}
void gsShootEmUpGame::end() {
	GS_LOG("Shoot 'em Up Game Ended\n");
	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}
}

bool gsShootEmUpGame::isRunning() {
	return true;
}

void gsShootEmUpGame::update() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->update();
	}
}
void gsShootEmUpGame::draw() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->draw();
	}
}