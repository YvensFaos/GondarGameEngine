#include "gsShootEmUp_Player.h"

#include "gsGraphics.h"
#include "gsInput.h"
#include "gsConfig.h"


gsShootEmUp_Player::gsShootEmUp_Player(gsShootEmUpGame *game) {
	// Carregar sprite do jogador
	tag = gsShootEmUpObjectTag::Player;

	sprite = new gsSpriteSheet("Shoot\\player_walking.png", "player", 1, 4);

	//Animação walking
	int* frames = new int(4);
	frames[0] = 0;
	frames[1] = 1;
	frames[2] = 2;
	frames[3] = 3;

	gsAnimationClip* clip = new gsAnimationClip("walking", frames, 4, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("walking");


	transform.position = gsVector3(400, 300, 0);
	transform.size = gsVector3(50, 50, 0);
	transform.tint = gsColor::white();

	collisionMask = 0x02;
}
gsShootEmUp_Player::~gsShootEmUp_Player() {
	delete sprite;
}

void gsShootEmUp_Player::update() {

	if (transform.position.x < 0) {
		transform.position.x = 1;
		transform.speed.x *= -1;
	}
	else if (transform.position.x + transform.size.x > GS_RESOLUTION_X) {
		transform.position.x = GS_RESOLUTION_X - 1 - transform.size.x;
		transform.speed.x *= -1;
	}

	if (transform.position.y < 0) {
		transform.position.y = 1;
		transform.speed.y *= -1;
	}
	else if (transform.position.y + transform.size.y > GS_RESOLUTION_Y) {
		transform.position.y = GS_RESOLUTION_Y -1 - transform.size.y;
		transform.speed.y *= -1;
	}

	if (gsInput::queryKey(GLFW_KEY_LEFT) == gsKeyState::Pressed)
	{
		transform.speed = gsVector3(-380, 0, 0);
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_RIGHT) == gsKeyState::Pressed)
	{
		transform.speed = gsVector3(380, 0, 0);
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_UP) == gsKeyState::Pressed){
		transform.speed = gsVector3(0, -380, 0);
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_DOWN) == gsKeyState::Pressed){
		transform.speed = gsVector3(0, 380, 0);
		transform.applySpeed();
	}
	
	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
	// Verificar teclas direcionais para realizar a movimentação
	// Verificar se o player saiu da tela
	// Se a arma estiver fora do cooldown, verificar teclas para atacar
	// - Criar balas
}
void gsShootEmUp_Player::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
	// ativar sprite no openGL
	// chamar rotina de desenho
}

void gsShootEmUp_Player::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *other = static_cast<gsShootEmUpObject*>(_other);
	if (other->tag == gsShootEmUpObjectTag::EnemyBullet)
	{

	}
	// utilizar a tag para descobrir com que tipo de objeto colidiu.
	// fazer outro cast
	// deduzir do HP o damage recebido
}