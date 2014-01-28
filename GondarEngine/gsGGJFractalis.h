#include "gsGGJEnemy.h"

class gsGGJFractalis: public gsGGJEnemy{

public:
	int multishotState;
	float multishot;
	
	gsGGJFractalis() {}
	gsGGJFractalis(gsGGJGame *game);
	virtual ~gsGGJFractalis() {}
	virtual void update();
	virtual void setupSpritesheet();
};