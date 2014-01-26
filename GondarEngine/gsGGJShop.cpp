#include "gsGGJShop.h"


#include "gsSystem.h"
#include "gsGGJGlobals.h"
#include "gsGGJPlayer.h"

int gPowerCannons;
int gColorAvoid;
int gSize;
bool gPowerChoosen;
bool gColorChoosen;
bool gSizePlusChoosen;



gsGGJShop::gsGGJShop(gsGGJGame *game) : gsGGJObject(game) {
	collident = solid = false;
	setUpSprite();

	transform.tint = gsColor::white(0.3f);

	gPowerCannons = 0;
	gColorAvoid = 0;
	gSize = 0;

	gPowerChoosen = false;
	gColorChoosen = false;
	gSizePlusChoosen = false;
}
gsGGJShop::~gsGGJShop(void) {
	delete hudSprite;
	delete powerCannonsSprite;
	delete colorAvoidSprite;
	delete sizeSprite;
}

void gsGGJShop::update() {
	hudSprite->updateAnimation();
	transform.setTextureCoordinates(hudSprite->getCurrentSprite());

	if (gsInput::queryKey(GLFW_KEY_TAB) == gsKeyState::JustPressed) {
		GS_LOG(gsGGJGlobal_Points);

		showShop();
	}
}
void gsGGJShop::draw() {
	if (gsInput::queryKey(GLFW_KEY_TAB) == gsKeyState::Pressed) {
		gsGGJPlayer *player = game->player;
		transform.position = player->transform.position - gsVector3(32, 32, 0);
		transform.size = player->transform.size + gsVector3(64, 64, 0);
		hudSprite->sendToOpenGL_Texture();
		gsGraphics::drawQuad(transform);
	}
}
	
void gsGGJShop::onCollision(gsGameObject *other, const gsCollisionInfo& info) {}

void gsGGJShop::setUpSprite() {
	int *frames = new int[3];
	frames[0] = 0; frames[1] = 1; frames[2] = 2;
	gsAnimationClip *clip = new gsAnimationClip("idle", frames, 3, 0.2);
	hudSprite = new gsSpriteSheet("GGJ\\tab_hud.png", "hud", 1, 3);
	hudSprite->addAnimation(clip);
	hudSprite->setAnimation("idle");

	powerCannonsSprite = new gsSpriteSheet("GGJ\\numbers.png", "powCan", 1, 8);
	colorAvoidSprite = new gsSpriteSheet("GGJ\\numbers.png", "colAvoid", 1, 8);
	sizeSprite = new gsSpriteSheet("GGJ\\main_ship.png", "size", 1, 2);
}

void gsGGJShop::showShop() {
	if (gPowerCannons != 0) {
		if (gPowerCannons != 0) {
			if (gPowerCannons != 0) { // showing all three options you choosed
				normalShop();
			} else { // showing only size plus and size minus
				pickShop(0);
			}
		} else { // showing only avoid or color
			pickShop(0);
		}
	} else { // showing only power or cannons
		pickShop(0);
	}
}

void gsGGJShop::pickShop(int id) {

}
void gsGGJShop::normalShop() {

}