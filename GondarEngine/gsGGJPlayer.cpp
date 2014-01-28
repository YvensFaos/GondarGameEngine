#include "gsGGJPlayer.h"
#include "gsGGJBullet.h"

#include "gsSystem.h"
#include "gsGGJHealth.h"
#include "gsGGJExplosion.h"

gsGGJPlayer::gsGGJPlayer(gsGGJGame *game) : gsGGJShip(game)
{
	tag = gsGGJTag::Player;

	setUpSpritesheet();

	hp = PLAYER_HEALTH;
	maxHp = hp;
	damage = 3;
	cooldownTime = 0;
	cooldown = BULLET_NORMAL_COOLDOWN;

	// tetenta pelo construtor
	transform = gsTransform(INITIAL_PLAYER_POS, INITIAL_PLAYER_SIZE, gsColor::white(1.0f));
	collisionMask = 0x02;
	bulletType = gsGGJGlobal_BulletType;
	changeColor(gsGGJPhase::BluePhase);

	healthBar = new gsGGJHealth(game, this);
	game->addObjetToObjectsList(healthBar);

	state = gsGGJPlayerState::Alive;
}

gsGGJPlayer::~gsGGJPlayer(void) {}

void gsGGJPlayer::update()
{
	if (state == gsGGJPlayerState::Dead) {
		stateTransitionTime += gsClock::getDeltaTime();

		if (stateTransitionTime >= PLAYER_DEAD_TIME) {
			state = gsGGJPlayerState::Blinking;
			stateTransitionTime = 0;
			blinkTime = 0;
			transform.position = INITIAL_PLAYER_POS;
			hp = maxHp;

			healthBar = new gsGGJHealth(game, this);
			game->addObjetToObjectsList(healthBar);
		}
		return; // unable to move or shoot
	} else if (state == gsGGJPlayerState::Blinking) {
		stateTransitionTime += gsClock::getDeltaTime();
		blinkTime += gsClock::getDeltaTime();

		if (blinkTime >= PLAYER_BLINKING_INTERVAL) {
			if (transform.tint.a == 0) {
				transform.tint.a = (100 - gsGGJGlobal_AvoidChance) / 2.0f;
			} else {
				transform.tint.a = 0;
			}
			blinkTime = 0;
		}
		if (stateTransitionTime >= PLAYER_BLINKING_TIME) {
			state = gsGGJPlayerState::Alive;
			transform.tint.a = (100 - gsGGJGlobal_AvoidChance) / 2.0f;
		}
	}

	move();
	shoot();
	toChangeColor();
}
void gsGGJPlayer::draw()
{
	if (state != gsGGJPlayerState::Dead) {
		sprite->sendToOpenGL_Texture();
		gsGraphics::drawQuad(transform);
	}
}

void gsGGJPlayer::shoot()
{
	cooldownTime += gsClock::getDeltaTime();
	if (cooldownTime >= cooldown && (gsInput::queryKey(GLFW_KEY_SPACE) == gsKeyState::Pressed)) {
		gsGGJBullet *bullet;
		cooldownTime = 0;

		if (cannons == 1) {
			bullet = new gsGGJBullet(true, bulletType, &transform, game, phase);
			game->addObjetToObjectsList(bullet);
		} else {
			int count = 0;
			switch (cannons) {
				case 2: count = 2; break;
				case 3: count = 3; break;
				case 4: count = 5; break;
				case 5: count = 8; break;
				default: break;
			}

			float margin = CANNONS_INTERBULLET_MARGIN;
			float offset = (margin * (count-1)) / 2.0f;
			for (int i = 0; i < count; i++) {
				bullet = new gsGGJBullet(true, bulletType, &transform, game, phase);
				bullet->transform.position.x += margin * i - offset;
				bullet->transform.position.y += abs(((i - (count-1) / 2.0f) * 8));
				game->addObjetToObjectsList(bullet);
			}
		} 
	}
}

void gsGGJPlayer::move()
{
	if (gsInput::queryKey(GLFW_KEY_LEFT) == gsKeyState::Pressed)
	{
		transform.speed = gsVector3(-380, 0, 0) * gsGGJGlobal_SpeedFactor;
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_RIGHT) == gsKeyState::Pressed)
	{
		transform.speed = gsVector3(380, 0, 0) * gsGGJGlobal_SpeedFactor;
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_UP) == gsKeyState::Pressed){
		transform.speed = gsVector3(0, -380, 0) * gsGGJGlobal_SpeedFactor;
		transform.applySpeed();
	}

	if (gsInput::queryKey(GLFW_KEY_DOWN) == gsKeyState::Pressed){
		transform.speed = gsVector3(0, 380, 0) * gsGGJGlobal_SpeedFactor;
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

void gsGGJPlayer::toChangeColor()
{
	if (gsGGJGlobal_PhasesAvaiable != 1) {
		if(gsInput::queryKey(GLFW_KEY_Q) == gsKeyState::Pressed)
			changeColor(gsGGJPhase::BluePhase);
		else if(gsInput::queryKey(GLFW_KEY_W) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 1)
			changeColor(gsGGJPhase::RedPhase);
		else if (gsInput::queryKey(GLFW_KEY_E) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 2)
			changeColor(gsGGJPhase::GreenPhase);
		else if (gsInput::queryKey(GLFW_KEY_R) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 3)
			changeColor(gsGGJPhase::YellowPhase);
		else if (gsInput::queryKey(GLFW_KEY_T) == gsKeyState::Pressed && gsGGJGlobal_PhasesAvaiable > 4)
			changeColor(gsGGJPhase::MagentaPhase);
	}
}

void gsGGJPlayer::changeColor(gsGGJPhase phase)
{
	this->phase = phase;
	setPhaseColor(phase);
}

void gsGGJPlayer::onCollision(gsGameObject *_other, const gsCollisionInfo& info)
{
	if (state != gsGGJPlayerState::Alive) {
		return;
	}

	gsGGJObject *otherCastedToGGJObject = static_cast<gsGGJObject*>(_other);

	if (otherCastedToGGJObject->tag == gsGGJTag::EnemyBullet) {
		gsGGJBullet *other = static_cast<gsGGJBullet*>(_other);
		if (phase != other->phase) {
			if (!gsRandom::chance(gsGGJGlobal_AvoidChance)) {
				hp -= other->damage;

				if (hp <= 0) {
					gsGGJGlobal_Lifes--;
					if (gsGGJGlobal_Lifes >= 0) {
						state = gsGGJPlayerState::Dead;
						stateTransitionTime = 0;

						bulletType = gsGGJBulletType::Normal;
						cooldown = BULLET_NORMAL_COOLDOWN;
					} else {
						game->removeObjectFromObjectsList(this);
						game->addObjetToObjectsList(new gsGGJExplosion(info, transform.tint, game));
					}
				}
				game->removeObjectFromObjectsList(other);
				game->addObjetToObjectsList(new gsGGJExplosion(info, transform.tint, game));
			} else {
				other->collident = false;
				other->transform.tint = gsColor(0.3, 0.3, 0.3, 0.5);
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