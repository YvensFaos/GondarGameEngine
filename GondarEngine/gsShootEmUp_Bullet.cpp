#include "gsShootEmUp_Bullet.h"


gsShootEmUp_Bullet::gsShootEmUp_Bullet(bool isPlayerBullet, gsShootEmUpGame *game) {
	// Carregar sprite do jogador
}
gsShootEmUp_Bullet::~gsShootEmUp_Bullet() {
	delete sprite;
}

void gsShootEmUp_Bullet::update() {
	// Mover bala baseada na sua velocidade
}
void gsShootEmUp_Bullet::draw() {
	// ativar sprite no openGL
	// chamar rotina de desenho
}

void gsShootEmUp_Bullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *other = static_cast<gsShootEmUpObject*>(_other);

	// utilizar a tag para descobrir com que tipo de objeto colidiu.
	// fazer outro cast
	// deduzir do HP o damage recebido
}