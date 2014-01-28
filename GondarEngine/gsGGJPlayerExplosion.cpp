#include "gsGGJPlayerExplosion.h"


#include "gsGGJBullet.h"
#include "gsSystem.h"


gsGGJPlayerExplosion::gsGGJPlayerExplosion(gsTransform* transform, gsGGJPhase phase, gsGGJGame *game) : gsGGJObject(game) {
	this->transform = gsTransform(transform->position, transform->size, transform->rotation, transform->tint);

	collident = solid = false;
	this->phase = phase;

	time = PLAYER_DEAD_TIME;

	gsAudio::play("GGJ\\Player Respawning.mp3", false, 0.6, gsAudio::findPan(transform));
}

void gsGGJPlayerExplosion::update() {
	time -= gsClock::getDeltaTime();

	if (time < 0) {
		game->removeObjectFromObjectsList(this);
		return;
	} else {
		gsGGJBullet *bullet;
		for (int i = 0; i < gsGGJGlobal_Cannons; i++)
		{
			bullet = new gsGGJBullet(true, gsGGJBulletType::Spread, &transform, game, phase);
			bullet->transform.position = transform.position + transform.size / 2;
			bullet->transform.position += gsVector3(gsRandom::nextDouble() - 0.5f, gsRandom::nextDouble() - 0.5f, 0) * 16;
			bullet->transform.speed = gsVector3(gsRandom::nextDouble() - 0.5f, gsRandom::nextDouble() - 0.5f, 0) * 1200;
			game->addObjetToObjectsList(bullet);
		}
	}
}