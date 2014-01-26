#include "gsGGJEnemy.h"

class gsGGJSlaien: public gsGGJEnemy{

public:
	gsGGJSlaien() {}
	gsGGJSlaien(gsGGJGame *game);
	virtual ~gsGGJSlaien();

	//virtual void update();
	virtual void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);

	virtual void setupSpritesheet();
	virtual void move();
	virtual void shoot();
};