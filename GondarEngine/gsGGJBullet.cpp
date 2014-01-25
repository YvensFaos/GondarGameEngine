#include "gsGGJBullet.h"
#include <math.h>

#include "gsSystem.h"

gsGGJBullet::gsGGJBullet(bool isPlayerBullet, gsGGJBulletType bulletType, gsTransform* shooterTransform, gsGGJGame *game) : gsGGJObject(game) {
	if (isPlayerBullet) {
		tag = gsGGJTag::PlayerBullet;
	} else {
		tag = gsGGJTag::EnemyBullet;
	}
	this->bulletType = bulletType;
	offset = gsVector3::zero();
	// Setar valores do transform da bala baseado na transform do shooter.
	// Definir speed utilizando o tipo da bala
	angulo = 0;
}
gsGGJBullet::~gsGGJBullet() {
	delete sprite;
}

void gsGGJBullet::update() {
	if (transform.position.x + transform.size.x < 0 || transform.position.x > GS_RESOLUTION_X) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	if (transform.position.y + transform.size.y < 0 || transform.position.y > GS_RESOLUTION_Y) {
		game->removeObjectFromObjectsList(this);
		return;
	}
	
	if (bulletType == gsGGJBulletType::Spiral) {
		doSpiral();
	}

	
	transform.applySpeed();
	
}
void gsGGJBullet::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
	// desenhar
	// 
}

void gsGGJBullet::doSpiral() {
	int raio = 40;
	transform.position -= offset;
	angulo += gsClock::getDeltaTime();
	offset.x = sin(angulo*raio);
	offset.y = cos(angulo*raio);
	transform.position += offset;

}



void gsGGJBullet::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {

}