#include "gsGGJShop.h"


#include "gsSystem.h"
#include "gsGGJGlobals.h"
#include "gsGGJPlayer.h"

gsGGJShop::gsGGJShop(gsGGJGame *game) : gsGGJObject(game) {
	collident = solid = false;
	setUpSprite();

	transform.tint = gsColor::white();
}
gsGGJShop::~gsGGJShop(void) {
	delete sprite;
}

void gsGGJShop::update() {
	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
}
void gsGGJShop::draw() {
	if (gsInput::queryKey(GLFW_KEY_TAB) == gsKeyState::Pressed) {
		gsGGJPlayer *player = game->player;
		transform.position = player->transform.position - gsVector3(32, 32, 0);
		transform.size = player->transform.size + gsVector3(64, 64, 0);
		sprite->sendToOpenGL_Texture();
		gsGraphics::drawQuad(transform);
	}
}
	
void gsGGJShop::onCollision(gsGameObject *other, const gsCollisionInfo& info) {}

void gsGGJShop::setUpSprite() {
	int *frames = new int[3];
	frames[0] = 0; frames[1] = 1; frames[2] = 2;
	gsAnimationClip *clip = new gsAnimationClip("idle", frames, 3, 0.2);
	sprite = new gsSpriteSheet("GGJ\\tab_hud.png", "hud", 1, 3);
	sprite->addAnimation(clip);
	sprite->setAnimation("idle");
}