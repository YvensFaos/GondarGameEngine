#include "gsGGJEnemy.h"


#include "gsSystem.h"
#include "gsGGJBullet.h"


gsGGJEnemy::gsGGJEnemy(gsGGJGame *game) : gsGGJShip(game) {
	tag = gsGGJTag::Enemy;
}
gsGGJEnemy::~gsGGJEnemy() {
	//delete sprite;
}

void gsGGJEnemy::update() {
	if (transform.leftTheSceen()) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	// Logica de atualização do inimigo
}
void gsGGJEnemy::draw() {
	//sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJEnemy::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsGGJObject *otherCastedToGGJObject = static_cast<gsGGJObject*>(_other);

	if (otherCastedToGGJObject->tag == gsGGJTag::PlayerBullet)
	{
		gsGGJBullet *other = static_cast<gsGGJBullet*>(_other);
		
	}
}