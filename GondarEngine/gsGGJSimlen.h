#include "gsGGJEnemy.h"

class gsGGJSimlen: public gsGGJEnemy{

private:
	bool modifyShot;

public:
	gsGGJSimlen() {}
	gsGGJSimlen(gsGGJGame *game);
	virtual ~gsGGJSimlen() {}

	virtual void update();
	
	virtual void setupSpritesheet();
	virtual void shoot();
};