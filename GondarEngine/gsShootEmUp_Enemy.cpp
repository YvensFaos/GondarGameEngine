#include "gsShootEmUp_Enemy.h"


gsShootEmUp_Enemy::gsShootEmUp_Enemy(gsShootEmUpGame *game) {
	// Carregar sprite do inimigo
}
gsShootEmUp_Enemy::~gsShootEmUp_Enemy() {
	delete sprite;
}

void gsShootEmUp_Enemy::update() {
	// Aplicar velocidade
	// Verificar se este objeto cruzou a linha de baixo da tela
	// Se não estiver no cooldown, atirar
}
void gsShootEmUp_Enemy::draw() {
	// ativar sprite no openGL
	// chamar rotina de desenho
}

void gsShootEmUp_Enemy::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *other = static_cast<gsShootEmUpObject*>(_other);

	// utilizar a tag para descobrir com que tipo de objeto colidiu.
	// fazer outro cast
	// deduzir do HP o damage recebido
}