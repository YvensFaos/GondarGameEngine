#include "gsGGJPlayer.h"


#include "gsSystem.h"


gsGGJPlayer::gsGGJPlayer(gsGame *game)
{
	//tag = gsShootEmUpObjectTag::Player;

	sprite = new gsSpriteSheet("Shoot\\player_walking.png", "player", 1, 4);

	hp = 20;
	damage = 3;
	weaponCooldownTime = 0;
	weaponCooldown = 0.5;

	//Animação walking
	int* frames = new int(4);
	frames[0] = 0;
	frames[1] = 1;
	frames[2] = 2;
	frames[3] = 3;

	gsAnimationClip* clip = new gsAnimationClip("walking", frames, 4, 0.4f);
	sprite->addAnimation(clip);
	sprite->setAnimation("walking");

	// tetenta pelo construtor
	transform = gsTransform(gsVector3(400, 300, 0), gsVector3(50, 50, 0), gsColor::white(1.0f));
	collisionMask = 0x02;
}

void gsGGJPlayer::draw()
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJPlayer::shoot()
{
	weaponCooldownTime += gsClock::getDeltaTime();
	if(weaponCooldownTime >= weaponCooldown && (gsInput::queryKey(GLFW_KEY_SPACE) == gsKeyState::Pressed))
	{
		weaponCooldownTime = 0;
		
		/*gsGGJBullet* bullet = new gsGGJBullet(true, this, game, gsVector3(gsRandom::nextInt(-20, 20), -200, 0));
		bullet->setDamage(damage);
		game->addObjetToObjectsList(bullet);*/
	}
	
	weaponCooldownTime += gsClock::getDeltaTime();
}

gsGGJPlayer::~gsGGJPlayer(void)
{

}

void gsGGJPlayer::move()
{
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
}

void gsGGJPlayer::update()
{
	move();
	sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());
}

void gsGGJPlayer::onCollision(gsGameObject *other, const gsCollisionInfo& info)
{

}