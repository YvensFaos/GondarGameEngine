#include "gsGGJBullet.h"


#include "gsSystem.h"

gsGGJBullet::gsGGJBullet(bool isPlayerBullet, gsGGJBulletType bulletType, gsTransform* shooterTransform, gsGGJGame *game) : gsGGJObject(game) {
	if (isPlayerBullet) {
		tag = gsGGJTag::PlayerBullet;
	} else {
		tag = gsGGJTag::EnemyBullet;
	}
	this->bulletType = bulletType;

	// Setar valores do transform da bala baseado na transform do shooter.
	// Definir speed utilizando o tipo da bala
}
gsGGJBullet::~gsGGJBullet() {
	delete sprite;
}

void gsGGJBullet::update() {
	// Aplicar velocidade
	// Destruir se sair da tela
	if (bulletType == gsGGJBulletType::Spiral) {
		doSpiral();
	}
	if (bulletType == gsGGJBulletType::Normal) {
		doNormal();
	}
	if (bulletType = gsGGJBulletType::Spread) {
		doSpread();
	}
}
void gsGGJBullet::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
	// desenhar
	// 
}

void gsGGJBullet::doSpiral() {
	gsVector3 normalSpd = speed;
	gsVector3 spiralSpd = gsVector3(-200, 0, 0);
	tag = gsShootEmUpObjectTag::PlayerBullet;
		sprite = new gsSpriteSheet("Shoot/player_bullet.png", "bullet", 1, 3);
		collisionMask = 0x01
	for (int i = 0; i < 200; i++){

	}
}

void gsGGJBullet::doNormal() {
	transform.applySpeed();

	if (transform.position.x + transform.size.x < 0 || transform.position.x > GS_RESOLUTION_X) {
		game->removeObjectFromObjectsList(this);
	}
	if (transform.position.y + transform.size.y < 0 || transform.position.y > GS_RESOLUTION_Y) {
		game->removeObjectFromObjectsList(this);
	}
}

void gsGGJBullet::doSpread() {

}

void gsGGJBullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {

}