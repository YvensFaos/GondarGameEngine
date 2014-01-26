#include "gsGGJEnemy.h"

class gsGGJFractalis: public gsGGJEnemy{

public:
	gsGGJFractalis() {}
	gsGGJFractalis(gsGGJGame *game);
	virtual ~gsGGJFractalis();

	//virtual void update();
	virtual void draw();

	void onCollision(gsGameObject *_other, const gsCollisionInfo& info);

	virtual void setupSpritesheet();
	virtual void move();
	virtual void shoot();
};