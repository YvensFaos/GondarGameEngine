#include "gsGGJPlayer.h"
#include "gsGGJBullet.h"

#include "gsSystem.h"


gsGGJPlayer::gsGGJPlayer(gsGGJGame *game) : gsGGJShip(game)
{
	tag = gsGGJTag::Player;

	setUpSpritesheet();

	hp = 20;
	damage = 3;
	cooldownTime = 0;
	//cooldown = PLAYER_COOLDOWN_TIME;
	cooldown = BULLET_SPREAD_COOLDOWN;

	// tetenta pelo construtor
	transform = gsTransform(gsVector3(400, 300, 0), gsVector3(66, 60, 0), gsColor::white(1.0f));
	collisionMask = 0x02;
	bulletType = gsGGJBulletType::Spread;
	changeColor(gsGGJPhase::BluePhase);
}

void gsGGJPlayer::draw()
{
	sprite->sendToOpenGL_Texture();
	gsGraphics::drawQuad(transform);
}

void gsGGJPlayer::shoot()
{
	cooldownTime += gsClock::getDeltaTime();
	if (cooldownTime >= cooldown && (gsInput::queryKey(GLFW_KEY_SPACE) == gsKeyState::Pressed))
	{
		cooldownTime = 0;
		
		gsTransform* bulletTransform = new gsTransform(transform);
		bulletTransform->position.x += 25;
		bulletTransform->position.y += 80;
		gsGGJBullet *bullet = new gsGGJBullet(true, bulletType, bulletTransform, game, phase);
		game->addObjetToObjectsList(bullet);
	}
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
	} else if (transform.position.x + transform.size.x > GS_RESOLUTION_X) {
		transform.position.x = GS_RESOLUTION_X - 1 - transform.size.x;
	}

	if (transform.position.y < 0) {
		transform.position.y = 1;
	} else if (transform.position.y + transform.size.y > GS_RESOLUTION_Y) {
		transform.position.y = GS_RESOLUTION_Y -1 - transform.size.y;
	}
}

void gsGGJPlayer::update()
{
	move();
	shoot();
	toChangeColor();
	/*sprite->updateAnimation();
	transform.setTextureCoordinates(sprite->getCurrentSprite());*/
}

void gsGGJPlayer::toChangeColor()
{
	if(gsInput::queryKey(GLFW_KEY_Q) == gsKeyState::Pressed)
		changeColor(gsGGJPhase::RedPhase);
	else if(gsInput::queryKey(GLFW_KEY_W) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 1)
		changeColor(gsGGJPhase::GreenPhase);
	else if (gsInput::queryKey(GLFW_KEY_E) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 2)
		changeColor(gsGGJPhase::BluePhase);
	else if (gsInput::queryKey(GLFW_KEY_R) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 3)
		changeColor(gsGGJPhase::YellowPhase);
	else if (gsInput::queryKey(GLFW_KEY_T) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 4)
		changeColor(gsGGJPhase::MagentaPhase);
}

void gsGGJPlayer::changeColor(gsGGJPhase phase)
{
	this->phase = phase;
	collisionMask &= ~phase;
	if (phase == gsGGJPhase::RedPhase) transform.tint = PHASE_RED_COLOR;
	else if (phase == gsGGJPhase::GreenPhase) transform.tint = PHASE_GREEN_COLOR;
	else if (phase == gsGGJPhase::BluePhase) transform.tint = PHASE_BLUE_COLOR;
	else if (phase == gsGGJPhase::YellowPhase) transform.tint = PHASE_YELLOW_COLOR;
	else if (phase == gsGGJPhase::MagentaPhase) transform.tint = PHASE_MAGENTA_COLOR;
	collisionMask |= phase;
}

void gsGGJPlayer::onCollision(gsGameObject *_other, const gsCollisionInfo& info)
{
	gsGGJObject *otherCastedToGGJObject = static_cast<gsGGJObject*>(_other);

	if (otherCastedToGGJObject->tag == gsGGJTag::EnemyBullet) {
		gsGGJBullet *other = static_cast<gsGGJBullet*>(_other);
		if (phase != other->phase) {
			hp -= other->damage;

			if (hp <= 0) {
				GS_LOG("Morreu");
				return;
			}
		}
	}
}

void gsGGJPlayer::setUpSpritesheet() {
	sprite = new gsSpriteSheet("GGJ\\main_ship.png", "player", 1, 1);
	//Animação walking
	//int* frames = new int(4);
	//frames[0] = 0;
	//frames[1] = 1;
	//frames[2] = 2;
	//frames[3] = 3;

	//gsAnimationClip* clip = new gsAnimationClip("walking", frames, 4, 0.4f);
	//sprite->addAnimation(clip);
	//sprite->setAnimation("walking");
}