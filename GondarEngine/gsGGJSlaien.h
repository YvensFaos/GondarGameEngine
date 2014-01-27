#include "gsGGJEnemy.h"

class gsGGJSlaien: public gsGGJEnemy {
public:
	float multishot;

	gsGGJSlaien() {}
	gsGGJSlaien(gsGGJGame *game);
	virtual ~gsGGJSlaien() {}

	virtual void update();
	virtual void setupSpritesheet();
};