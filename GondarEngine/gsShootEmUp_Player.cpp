#include "gsShootEmUp_Player.h"
#include "gsGraphics.h"
#include "gsInput.h"


gsShootEmUp_Player::gsShootEmUp_Player(gsShootEmUpGame *game) {
	// Carregar sprite do jogador
	transform.position = gsVector3(400, 300, 0);
	transform.size = gsVector3(100, 100, 0);
	transform.tint = gsColor::blue();

}
gsShootEmUp_Player::~gsShootEmUp_Player() {
	delete sprite;
}

void gsShootEmUp_Player::update() {
	if (gsInput::queryKey(GLFW_KEY_LEFT) == gsKeyState::Pressed)
	{
		transform.speed = gsVector3(-80, 0, 0);
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_RIGHT) == gsKeyState::Pressed)
	{
		transform.speed = gsVector3(80, 0, 0);
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_UP) == gsKeyState::Pressed){
		transform.speed = gsVector3(0, -80, 0);
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_DOWN) == gsKeyState::Pressed){
		transform.speed = gsVector3(0, 80, 0);
		transform.applySpeed();
	}
		
	// Verificar teclas direcionais para realizar a movimentação
	// Verificar se o player saiu da tela
	// Se a arma estiver fora do cooldown, verificar teclas para atacar
	// - Criar balas
}
void gsShootEmUp_Player::draw() {
	gsGraphics::drawQuad(transform);
	// ativar sprite no openGL
	// chamar rotina de desenho
}

void gsShootEmUp_Player::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *other = static_cast<gsShootEmUpObject*>(_other);

	// utilizar a tag para descobrir com que tipo de objeto colidiu.
	// fazer outro cast
	// deduzir do HP o damage recebido
}