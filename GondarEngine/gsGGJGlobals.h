#ifndef __GS_GGJ_GLOBALS__
#define __GS_GGJ_GLOBALS__


#include "gsGGJPhase.h"
#include "gsGGJBulletType.h"
#include "gsRandom.h"

extern float gsGGJGlobal_PowerFactor;
extern float gsGGJGlobal_SizeFactor;
extern float gsGGJGlobal_SpeedFactor;
extern float gsGGJGlobal_AvoidChance;
extern int gsGGJGlobal_Cannons;
extern int gsGGJGlobal_PhasesAvaiable;
extern gsGGJBulletType gsGGJGlobal_BulletType;

extern int gsGGJGlobal_Points;

//Definições dos valores iniciais do jogo
#define INITIAL_PLAYER_HEATH 80
#define INITIAL_PLAYER_DAMAGE 10
#define INITIAL_PLAYER_SIZE gsVector3(32, 32, 0);

#define INITIAL_ENEMY_HEALTH 100
#define INITIAL_ENEMY_DAMAGE 6
#define INITIAL_ENEMY_SIZE gsVector3(32, 32, 0);

#define INITIAL_BULLET_SPEED gsVector3(0, 100, 0);
#define INITIAL_BULLET_SIZE gsVector3(16, 16, 0)

#define INITIAL_POWER_FACTOR 1.f
#define INITIAL_SIZE_FACTOR 1.f
#define INITIAL_SPEED_FACTOR 1.f
#define INITIAL_AVOID_CHANCE 1.f
#define INITIAL_CANNONS 1
#define INITIAL_PHASES_AVAIABLE 5
#define INITIAL_BULLET_TYPE gsGGJBulletType::Normal

#define POINTS_WHEN_ENEMY_DIES gsRandom::nextInt(45, 55);
#define POINTS_WHEN_BULLET_STRIKES gsRandom::nextInt(1, 3); 

#define PLAYER_COOLDOWN_TIME 0.4

#define ENEMY_BURST_TIME 1.6
#define ENEMY_WAITING_TIME 3.8
#define ENEMY_INITIAL_WAITING_TIME 2
#define ENEMY_COOLDOWN_TIME 0.5

#define ENEMY_SPAWNER_COOLDOWN 1.2f
#define ENEMY_SPAWNER_TIMER 0.6f

//Enemy Simlen Attributes
#define ENEMY_SIMLEN_HEALTH 150
#define ENEMY_SIMLEN_BURSTWAITCOOLDOWN 2.5
#define ENEMY_SIMLEN_BURSTWAITTIME 0
#define ENEMY_SIMLEN_COOLDOWN 0.5
#define ENEMY_SIMLEN_COOLDOWNTIME 0 
#define ENEMY_SIMLEN_WAITING true

//Enemy Slaien Attributes
#define ENEMY_SLAIEN_HEALTH 200
#define ENEMY_SLAIEN_BURSTWAITCOOLDOWN 3
#define ENEMY_SLAIEN_BURSTWAITTIME 0
#define ENEMY_SLAIEN_COOLDOWN 1
#define ENEMY_SLAIEN_COOLDOWNTIME 0
#define ENEMY_SLAIEN_WAITING true

//Enemy Fractalis Attributes
#define ENEMY_FRACTALIS_HEALTH 300
#define ENEMY_FRACTALIS_BURSTWAITCOOLDOWN 3.5
#define ENEMY_FRACTALIS_BURSTWAITTIME 0
#define ENEMY_FRACTALIS_COOLDOWN 1.5
#define ENEMY_FRACTALIS_COOLDOWNTIME 0
#define ENEMY_FRACTALIS_WAITING true

#define BULLET_DAMAGE_NORMAL 30.0f
#define BULLET_DAMAGE_SPIRAL 20.0f
#define BULLET_DAMAGE_SPREAD 15.0f

#define PHASE_RED_COLOR gsColor(1.0f, 0.0f, 0.0f)
#define PHASE_GREEN_COLOR gsColor(0.0f, 1.0f, 0.0f)
#define PHASE_BLUE_COLOR gsColor(0.145f, 0.56f, 0.682)
#define PHASE_YELLOW_COLOR gsColor(1.0f, 1.0f, 0.0f)
#define PHASE_MAGENTA_COLOR gsColor(1.0f, 0.0f, 1.0f)

// 0 145    0 56     0 682


#endif