#include "gsGGJGameOver.h"

#include "gsSystem.h"
#include "gsGGJGlobals.h"
#include "gsGGJScore.h"

gsGGJGameOver::gsGGJGameOver(gsGGJGame *game)
{
	this->game = game;
	alpha = 0.0f;
	setupSpritesheet();
}

void gsGGJGameOver::setupSpritesheet()
{
	tutorialSprite = new gsSpriteSheet("GGJ\\gameOver.png", "screen", 1, 1);

	transform = gsTransform(gsVector3(200.f, 200.f, 0.f), gsVector3(400.f, 250.f, 0.f));
	transform.tint = gsColor::white(0.7f);

	pressSprite = new gsSpriteSheet("GGJ\\restart.png", "press", 1, 1);

	pressSpaceTransform = gsTransform(gsVector3(250.f, 460.f, 0.f), gsVector3(300.f, 14.f, 0.f));
	pressSpaceTransform.tint = gsColor::white(0.7f);

	escSprite = new gsSpriteSheet("GGJ\\quit.png", "press", 1, 1);

	pressEscTransform = gsTransform(gsVector3(250.f, 500.f, 0.f), gsVector3(300.f, 14.f, 0.f));
	pressEscTransform.tint = gsColor::white(0.7f);

	gsGGJScore* scoreDisplay = game->scoreDisplay;
	scoreDisplay->setScore(gsGGJGlobal_TotalPoints);
	scoreDisplay->transform.position = gsVector3(332.f, 285.f, 0.f);
}

gsGGJGameOver::~gsGGJGameOver(void) 
{
	delete tutorialSprite;
	delete pressSprite;
	delete escSprite;
}

void gsGGJGameOver::update() 
{
	if(gsInput::queryKey(GLFW_KEY_SPACE) == gsKeyState::JustPressed)
	{
		restartGame = true;
	}
}

void gsGGJGameOver::draw() 
{
	alpha += gsClock::getDeltaTime()*8;

	tutorialSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);

	pressSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(pressSpaceTransform);
	pressSpaceTransform.tint = gsColor::white(0.6f + sin(alpha));

	escSprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(pressEscTransform);
	pressEscTransform.tint = gsColor::white(0.6f + sin(alpha));
}