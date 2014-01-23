#include "gsShootEmUp_Bullet.h"
#include "gsGraphics.h"

gsShootEmUp_Bullet::gsShootEmUp_Bullet(bool isPlayerBullet, gsShootEmUpObject* shooter, gsShootEmUpGame *game, gsVector3 speed) {
	// Carregar sprite da bullet

	gsVector3 pos = shooter->transform.position;
	gsVector3 spd = speed;
	gsVector3 size = gsVector3(10,10,0);


	transform = gsTransform(pos, size, gsVector3::zero(), spd,gsColor::white());
}
gsShootEmUp_Bullet::~gsShootEmUp_Bullet() {
	delete sprite;
}

void gsShootEmUp_Bullet::update() {
	transform.applySpeed();
	// Mover bala baseada na sua velocidade
}
void gsShootEmUp_Bullet::draw() {
	// ativar sprite no openGL
	// chamar rotina de desenh
}

void gsShootEmUp_Bullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	game->removeObjectFromObjectsList(this);
	// utilizar a tag para descobrir com que tipo de objeto colidiu.
	// fazer outro cast
	// deduzir do HP o damage recebido
}