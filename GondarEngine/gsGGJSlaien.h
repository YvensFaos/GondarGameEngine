#include "gsGGJEnemy.h"

class gsGGJSlaien: public gsGGJEnemy{

public:
	gsGGJSlaien() {}
	gsGGJSlaien(gsGGJGame *game);
	virtual ~gsGGJSlaien() {}

	virtual void setupSpritesheet();
};