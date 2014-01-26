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

#define SHOP_ITEM_SIZE_X gsVector3(42, 0, 0)
#define SHOP_ITEM_SIZE_Y gsVector3(0, 42, 0)

#define PICKUP_SHOP_ITEM_1_POS (gsVector3(15, 0, 0) - SHOP_ITEM_SIZE_X - SHOP_ITEM_SIZE_Y)
#define PICKUP_SHOP_ITEM_2_POS (gsVector3(-15, 0, 0) - SHOP_ITEM_SIZE_Y)

#define NORMAL_SHOP_ITEM_1_POS (gsVector3(15, 0, 0) - SHOP_ITEM_SIZE_X - SHOP_ITEM_SIZE_Y)
#define NORMAL_SHOP_ITEM_2_POS (gsVector3(0, -15, 0) - SHOP_ITEM_SIZE_Y)
#define NORMAL_SHOP_ITEM_3_POS (gsVector3(-15, 0, 0) - SHOP_ITEM_SIZE_Y)

bool gCanBuy(int tier) {
	switch (tier) {
	case 0: return (gsGGJGlobal_Points > UPGRADE_TIER_ONE_COST);
	case 1: return (gsGGJGlobal_Points > UPGRADE_TIER_TWO_COST);
	case 2: return (gsGGJGlobal_Points > UPGRADE_TIER_THREE_COST);
	case 3: return (gsGGJGlobal_Points > UPGRADE_TIER_FOUR_COST);
	default:
		//gsAssert(0); // tier inválido
		return false;
		break;
	}
}
void gsGGJShop::updatePowerCannon() {
	if (gColorChoosen) {
		gsGGJGlobal_PowerFactor = 1 + (gPowerCannons + 1) * 0.1f;
		game->player->powerFactor = gsGGJGlobal_PowerFactor;
	} else {
		gsGGJGlobal_Cannons =  (gPowerCannons + 2);
		game->player->cannons = gsGGJGlobal_Cannons;
	}
}
void gsGGJShop::updateColorAvoid() {
	if (gColorChoosen) {
		gsGGJGlobal_PhasesAvaiable = gColorAvoid + 2;
	} else {
		gsGGJGlobal_AvoidChance = (gColorAvoid + 1) * 0.1f;
		game->player->avoidChance = gsGGJGlobal_AvoidChance;
	}
}
void gsGGJShop::updateSize() {
	if (gSizePlusChoosen) {
		gsGGJGlobal_SizeFactor = 1 + (gPowerCannons + 1) * 0.1f;
		game->player->sizeFactor = gsGGJGlobal_SizeFactor;
	} else {
		gsGGJGlobal_SizeFactor = 1 - (gPowerCannons + 1) * 0.1f;
		game->player->sizeFactor = gsGGJGlobal_SizeFactor;
	}
}

gsGGJShop::gsGGJShop(gsGGJGame *game) : gsGGJObject(game) {
	collident = solid = false;
	setUpSprite();
	gsGGJGlobal_Points = 12345;
	transform.tint = gsColor::white(0.3f);

	gPowerCannons = 0;
	gColorAvoid = 0;
	gSize = 0;

	gPowerChoosen = false;
	gColorChoosen = false;
	gSizePlusChoosen = false;

	itemTransform = gsTransform(gsVector3::zero(), SHOP_ITEM_SIZE_X + SHOP_ITEM_SIZE_Y);
	itemTransform.tint = gsColor::white();
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
	}
	if (gsInput::queryKey(GLFW_KEY_TAB) == gsKeyState::Pressed) {
		if (gPowerCannons != 0) {
			if (gColorAvoid != 0) {
				if (gSize != 0) { // showing all three options you choosed
					normalShopUpdate();
				} else { // showing only size plus and size minus
					pickShopUpdate(2);
				}
			} else { // showing only avoid or color
				pickShopUpdate(1);
			}
		} else { // showing only power or cannons
			pickShopUpdate(0);
		}
	}

	if (gsInput::queryKey(GLFW_KEY_H) == gsKeyState::JustPressed) {
		gPowerCannons++;
		GS_LOG(gPowerCannons << ", " << gColorAvoid << ", " << gSize);
	}
	if (gsInput::queryKey(GLFW_KEY_J) == gsKeyState::JustPressed) {
		gColorAvoid++;
		GS_LOG(gPowerCannons << ", " << gColorAvoid << ", " << gSize);
	}
	if (gsInput::queryKey(GLFW_KEY_K) == gsKeyState::JustPressed) {
		gSize++;
		GS_LOG(gPowerCannons << ", " << gColorAvoid << ", " << gSize);
	}
}
void gsGGJShop::draw() {
	if (gsInput::queryKey(GLFW_KEY_TAB) == gsKeyState::Pressed) {
		gsGGJPlayer *player = game->player;
		transform.position = player->transform.position - gsVector3(32, 32, 0);
		transform.size = player->transform.size + gsVector3(64, 64, 0);
		hudSprite->sendToOpenGL_Texture();
		gsGraphics::drawQuad(transform);

		if (gPowerCannons != 0) {
			if (gColorAvoid != 0) {
				if (gSize != 0) { // showing all three options you choosed
					normalShopDraw();
				} else { // showing only size plus and size minus
					pickShopDraw(2);
				}
			} else { // showing only avoid or color
				pickShopDraw(1);
			}
		} else { // showing only power or cannons
			pickShopDraw(0);
		}
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

	powerCannonsSprite = new gsSpriteSheet("GGJ\\bar.png", "powCan", 1, 8);
	colorAvoidSprite = new gsSpriteSheet("GGJ\\numbers.png", "colAvoid", 1, 8);
	sizeSprite = new gsSpriteSheet("GGJ\\main_ship.png", "size", 1, 2);
}


void gsGGJShop::pickShopUpdate(int id) {
	switch(id) {
		case 0: 
			if (gsInput::queryKey(GLFW_KEY_1) == gsKeyState::JustPressed) {
				if (gCanBuy(0)) {
					gPowerCannons += 1;
					gPowerChoosen = true;
					updatePowerCannon();
				}
			} else if (gsInput::queryKey(GLFW_KEY_2) == gsKeyState::JustPressed) {
				if (gCanBuy(0)) {
					gPowerCannons += 1;
					gPowerChoosen = false;
					updatePowerCannon();
				}
			}
			break;
		case 1: 
			if (gsInput::queryKey(GLFW_KEY_1) == gsKeyState::JustPressed) {
				if (gCanBuy(0)) {
					gColorAvoid += 1;
					gColorChoosen = true;
					updateColorAvoid();
				}
			} else if (gsInput::queryKey(GLFW_KEY_2) == gsKeyState::JustPressed) {
				if (gCanBuy(0)) {
					gColorAvoid += 1;
					gColorChoosen = false;
					updateColorAvoid();
				}
			}
			break;
		case 2: 
			if (gsInput::queryKey(GLFW_KEY_1) == gsKeyState::JustPressed) {
				if (gCanBuy(0)) {
					gSize += 1;
					gSizePlusChoosen = true;
					updateSize();
				}
			} else if (gsInput::queryKey(GLFW_KEY_2) == gsKeyState::JustPressed) {
				if (gCanBuy(0)) {
					gSize += 1;
					gSizePlusChoosen = false;
					updateSize();
				}
			}
			break;
	}
}
void gsGGJShop::normalShopUpdate() {
	if (gsInput::queryKey(GLFW_KEY_1) == gsKeyState::Pressed) {
		if (gCanBuy(gPowerCannons)) {
			gPowerCannons += 1;
			updatePowerCannon();
		}
	} else if (gsInput::queryKey(GLFW_KEY_2) == gsKeyState::Pressed) {
		if (gCanBuy(gColorAvoid)) {
			gColorAvoid += 1;
			updateColorAvoid();
		}
	} else if (gsInput::queryKey(GLFW_KEY_3) == gsKeyState::Pressed) {
		if (gCanBuy(gSize)) {
			gSize += 1;
			updateSize();
		}
	}
}

void gsGGJShop::pickShopDraw(int id) {
	gsSpriteSheet *sprite;
	switch(id) {
		case 0: sprite = powerCannonsSprite; break;
		case 1: sprite = colorAvoidSprite; break;
		case 2: sprite = sizeSprite; break;
	}

	if (!gCanBuy(0)) { itemTransform.tint = gsColor(0.4, 0.4, 0.4); } else { itemTransform.tint = gsColor::white(); }
	sprite->sendToOpenGL_Texture();

	itemTransform.position = PICKUP_SHOP_ITEM_1_POS + transform.position;
	itemTransform.setTextureCoordinates(sprite->getSprite(0));
	gsGraphics::drawQuad(itemTransform);

	itemTransform.position = PICKUP_SHOP_ITEM_2_POS + transform.position;
	itemTransform.position.x += transform.size.x;
	if (id != 2) {
		itemTransform.setTextureCoordinates(sprite->getSprite(5));
	} else {
		itemTransform.setTextureCoordinates(sprite->getSprite(1)); // caso especial do size
	}
	gsGraphics::drawQuad(itemTransform);
}
void gsGGJShop::normalShopDraw() {
	if (!gCanBuy(gPowerCannons)) { itemTransform.tint = gsColor(0.4, 0.4, 0.4); } else { itemTransform.tint = gsColor::white(); }
	powerCannonsSprite->sendToOpenGL_Texture();

	itemTransform.position = NORMAL_SHOP_ITEM_1_POS + transform.position;
	itemTransform.setTextureCoordinates(powerCannonsSprite->getSprite(
		gPowerCannons + (gPowerChoosen) ? 0 : 5));
	gsGraphics::drawQuad(itemTransform);

	if (!gCanBuy(gColorAvoid)) { itemTransform.tint = gsColor(0.4, 0.4, 0.4); } else { itemTransform.tint = gsColor::white(); }
	colorAvoidSprite->sendToOpenGL_Texture();

	itemTransform.position = NORMAL_SHOP_ITEM_2_POS + transform.position;
	itemTransform.position.x += transform.size.x / 2;
	itemTransform.position.x -= itemTransform.size.x / 2;
	itemTransform.setTextureCoordinates(colorAvoidSprite->getSprite(
		gColorAvoid + (gColorAvoid) ? 0 : 5));
	gsGraphics::drawQuad(itemTransform);

	if (!gCanBuy(gSize)) { itemTransform.tint = gsColor(0.4, 0.4, 0.4); } else { itemTransform.tint = gsColor::white(); }
	sizeSprite->sendToOpenGL_Texture();

	itemTransform.position = NORMAL_SHOP_ITEM_3_POS + transform.position;
	itemTransform.position.x += transform.size.x;
	itemTransform.setTextureCoordinates(sizeSprite->getSprite(
		(gSizePlusChoosen) ? 0 : 1));
	gsGraphics::drawQuad(itemTransform);
}