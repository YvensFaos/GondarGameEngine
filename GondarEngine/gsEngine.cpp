#include "gsEngine.h"
#include "gsGame.h"

// subsystems
#include "gsLogger.h"
#include "gsWindow.h"
#include "gsClock.h"
#include "gsRandom.h"
#include "gsInput.h"
#include "gsGraphics.h"

// meta
#include "gsConfig.h"
#include "gsMacros.h"


gsEngine::gsEngine(gsGame* gameToBeRun) {
	gsAssert(gameToBeRun != 0);

	this->game = gameToBeRun;
}
gsEngine::~gsEngine() {
	this->game = 0;
}


void gsEngine::initializeEngineSystems() {
	gsLogger::init();
	gsWindow::init(GS_RESOLUTION_X, GS_RESOLUTION_Y);
	gsClock::init();
	gsRandom::init();
	gsInput::init();
	gsGraphics::init(GS_RESOLUTION_X, GS_RESOLUTION_Y);
}
void gsEngine::updateEngineSystems() {
	gsClock::update();
	gsInput::update();
}
void gsEngine::disposeEngineSystems() {
	gsGraphics::dispose();
	gsWindow::dispose();
}

void gsEngine::runGame() {
	initializeEngineSystems();

	game->start();
	while(game->isRunning() && gsWindow::isOpen()) {
		updateEngineSystems();

		game->update();

		gsGraphics::beginDraw();
			game->draw();
		gsGraphics::endDraw();
	}
	game->end();

	disposeEngineSystems();
}