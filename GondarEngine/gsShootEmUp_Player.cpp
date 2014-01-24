#include "gsShootEmUp_Player.h"


#include "gsSystem.h"
#include "gsShootEmUp_Bullet.h"


gsShootEmUp_Player::gsShootEmUp_Player(gsShootEmUpGame *game) : gsShootEmUpObject(game) {
	tag = gsShootEmUpObjectTag::Player;

	sprite = new gsSpriteSheet("Shoot\\player_walking.png", "player", 1, 4);

	health = 20;
	damage = 3;
	weaponCooldownTime = 0;
	weaponCooldown = 0.3;

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
	//delete sprite; <- bugando
}

void gsShootEmUp_Player::update() {

	if (transform.position.x < 0) {
		transform.position.x = 1;
	}
	else if (transform.position.x + transform.size.x > GS_RESOLUTION_X) {
		transform.position.x = GS_RESOLUTION_X - 1 - transform.size.x;
	}

	if (transform.position.y < 0) {
		transform.position.y = 1;
	}
	else if (transform.position.y + transform.size.y > GS_RESOLUTION_Y) {
		transform.position.y = GS_RESOLUTION_Y -1 - transform.size.y;
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

	weaponCooldownTime += gsClock::getDeltaTime();
	if(weaponCooldownTime >= weaponCooldown && (gsInput::queryKey(GLFW_KEY_SPACE) == gsKeyState::Pressed))
	{
		weaponCooldownTime -= weaponCooldown;

		gsShootEmUp_Bullet* bullet = new gsShootEmUp_Bullet(true, this, game, gsVector3(gsRandom::nextInt(-20, 20), -200, 0));
		bullet->setDamage(damage);
		game->addObjetToObjectsList(bullet);
	}
}
void gsShootEmUp_Player::draw() {
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsShootEmUp_Player::onCollision(gsGameObject *_other, const gsCollisionInfo& info) {
	gsShootEmUpObject *otherAsSEUObject = static_cast<gsShootEmUpObject*>(_other);

	if(otherAsSEUObject->tag == gsShootEmUpObjectTag::EnemyBullet)
	{
		gsShootEmUp_Bullet *other = static_cast<gsShootEmUp_Bullet*>(_other);
		health -= other->damage;
	}
}