#ifndef __GS_GGJ_GLOBALS__
#define __GS_GGJ_GLOBALS__


#include "gsGGJPhase.h"
#include "gsGGJBulletType.h"

extern float gsGGJGlobal_PowerFactor;
extern float gsGGJGlobal_SizeFactor;
extern float gsGGJGlobal_SpeedFactor;
extern float gsGGJGlobal_AvoidChance;
extern int gsGGJGlobal_Cannons;
extern gsGGJPhase gsGGJGlobal_Phase;
extern gsGGJBulletType gsGGJGlobal_BulletType;

//Definições dos valores iniciais do jogo
#define INITIAL_PLAYER_HEATH 80
#define INITIAL_PLAYER_DAMAGE 10

#define INITIAL_ENEMY_HEATH 42
#define INITIAL_ENEMY_DAMAGE 6

#define INITIAL_POWER_FACTOR 1.f
#define INITIAL_SIZE_FACTOR 1.f
#define INITIAL_SPEED_FACTOR 1.f
#define INITIAL_AVOID_CHANCE 1.f
#define INITIAL_CANNONS 1
#define INITIAL_PHASE gsGGJPhase::BluePhase
#define INITIAL_BULLET_TYPE gsGGJBulletType::Normal

#endif