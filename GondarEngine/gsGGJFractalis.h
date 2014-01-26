#include "gsGGJEnemy.h"

class gsGGJFractalis: public gsGGJEnemy{

public:
	gsGGJFractalis() {}
	gsGGJFractalis(gsGGJGame *game);
	virtual ~gsGGJFractalis() {}

	virtual void setupSpritesheet();
};