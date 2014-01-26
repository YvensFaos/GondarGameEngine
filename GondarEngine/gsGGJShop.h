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
	gsTransform itemTransform;

	gsGGJShop(void) {}
	gsGGJShop(gsGGJGame *game);
	virtual ~gsGGJShop(void);

	virtual void update();
	virtual void draw();
	
	virtual void onCollision(gsGameObject *other, const gsCollisionInfo& info);

	void setUpSprite();

	void pickShopUpdate(int id); // para as três primeiras compras
	void normalShopUpdate(); // para as demais onde já foram escolhidas as opções antagônicas
	void pickShopDraw(int id); // para as três primeiras compras
	void normalShopDraw(); // para as demais onde já foram escolhidas as opções antagônicas

	void updatePowerCannon();
	void updateColorAvoid();
	void updateSize();
};

#endif