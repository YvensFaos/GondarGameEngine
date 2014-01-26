#include "gsGGJEnemy.h"

class gsGGJSimlen: public gsGGJEnemy{

private:
	bool modifyShot;

public:
	gsGGJSimlen() {}
	gsGGJSimlen(gsGGJGame *game);
	virtual ~gsGGJSimlen();

	//virtual void update();
	virtual void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);

	virtual void setupSpritesheet();
	virtual void move();
	virtual void shoot();
};