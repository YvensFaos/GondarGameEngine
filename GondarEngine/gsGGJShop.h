#ifndef __GS_GGJ_SHOP__
#define __GS_GGJ_SHOP__

#include "gsGGJObject.h"
#include "gsSpriteSheet.h"

class gsGGJShop : public gsGGJObject {
public:
	gsSpriteSheet *hudSprite;
	gsSpriteSheet *powerCannonsSprite;
	gsSpriteSheet *colorAvoidSprite;
	gsSpriteSheet *sizeSprite;

	gsGGJShop(void) {}
	gsGGJShop(gsGGJGame *game);
	virtual ~gsGGJShop(void);

	virtual void update();
	virtual void draw();
	
	virtual void onCollision(gsGameObject *other, const gsCollisionInfo& info);

	void setUpSprite();
	void showShop();

	void pickShop(int id); // para as três primeiras compras
	void normalShop(); // para as demais onde já foram escolhidas as opções antagônicas
};

#endif