#include "gsGGJTutorial.h"

#include "gsSystem.h"
#include "gsGGJGlobals.h"

gsGGJTutorial::gsGGJTutorial(gsGGJGame *game)
{
	this->game = game;
	alpha = 0.0f;
	state = 0;
	setupSpritesheet();
}

void gsGGJTutorial::setupSpritesheet()
{
	tutorialSprite = new gsSpriteSheet("GGJ\\screen1.png", "screen", 1, 1);

	transform = gsTransform(gsVector3(200.f, 200.f, 0.f), gsVector3(400.f, 250.f, 0.f));
	transform.tint = gsColor::white(0.7f);

	pressSprite = new gsSpriteSheet("GGJ\\press_space.png", "press", 1, 1);

	pressSpaceTransform = gsTransform(gsVector3(300.f, 460.f, 0.f), gsVector3(200.f, 30.f, 0.f));
	pressSpaceTransform.tint = gsColor::white(0.7f);
}

gsGGJTutorial::~gsGGJTutorial(void) {
	delete tutorialSprite;
	delete pressSprite;
}

void gsGGJTutorial::update() {
	if(gsInput::queryKey(GLFW_KEY_SPACE) == gsKeyState::JustPressed)
	{
		switch (state)
		{
		case 0:
			tutorialSprite = new gsSpriteSheet("GGJ\\screen2.png", "screen", 1, 1);
			state++;
			break;
		case 1:
			tutorialSprite = new gsSpriteSheet("GGJ\\screen3.png", "screen", 1, 1);
			state++;
			break;
		case 2:
			startGame = true;
			game->removeObjectFromObjectsList(this);
		default:
			break;
		}
	}
}

void gsGGJTutorial::draw() {
	alpha += gsClock::getDeltaTime()*8;

	tutorialSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);

	pressSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(pressSpaceTransform);
	pressSpaceTransform.tint = gsColor::white(0.7f + sin(alpha));
}