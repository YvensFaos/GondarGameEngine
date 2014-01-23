#include "gsShootEmUp_Player.h"



gsShootEmUp_Player::gsShootEmUp_Player(gsShootEmUpGame *game) {
	// Carregar sprite do jogador
}
gsShootEmUp_Player::~gsShootEmUp_Player() {
	delete sprite;
}

void gsShootEmUp_Player::update() {
	// Verificar teclas direcionais para realizar a movimentação
	// Verificar se o player saiu da tela
	// Se a arma estiver fora do cooldown, verificar teclas para atacar
	// - Criar balas
}
void gsShootEmUp_Player::draw() {
	// ativar sprite no openGL
	// chamar rotina de desenho
}

void gsShootEmUp_Player::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *other = static_cast<gsShootEmUpObject*>(_other);

	// utilizar a tag para descobrir com que tipo de objeto colidiu.
	// fazer outro cast
	// deduzir do HP o damage recebido
}