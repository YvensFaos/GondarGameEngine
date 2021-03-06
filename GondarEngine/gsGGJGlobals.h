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
extern int gsGGJGlobal_TotalPoints;
extern int gsGGJGlobal_UpgradesPurchased;

extern int gsGGJGlobal_Lifes;
extern bool startGame;
extern bool restartGame;

//Definições dos valores iniciais do jogo
#define INITIAL_PLAYER_HEATH 10
#define INITIAL_PLAYER_DAMAGE 2
#define INITIAL_PLAYER_POS gsVector3(400, 300, 0)
#define INITIAL_PLAYER_SIZE gsVector3(66, 60, 0)

#define INITIAL_LIVES 3

#define INITIAL_ENEMY_HEALTH 2
#define INITIAL_ENEMY_DAMAGE 1
#define INITIAL_ENEMY_SIZE gsVector3(32, 32, 0);

#define INITIAL_BULLET_SPEED gsVector3(0, 300, 0);
#define INITIAL_BULLET_SIZE gsVector3(16, 16, 0)

#define INITIAL_POWER_FACTOR 1.f
#define INITIAL_SIZE_FACTOR 1.f
#define INITIAL_SPEED_FACTOR 1.f

#define INITIAL_AVOID_CHANCE 0.f
#define INITIAL_CANNONS 1
#define INITIAL_PHASES_AVAIABLE 1
#define INITIAL_BULLET_TYPE gsGGJBulletType::Normal

#define CANNONS_INTERBULLET_MARGIN 20

#define LIFES_POSITION gsVector3(10, 40, 0)
#define LIFES_SIZE gsVector3(25, 25, 0)
#define LIFES_MARGIN gsVector3(8 + LIFES_SIZE.x, 0, 0)

#define POINTS_POSITION gsVector3(8, 8, 0);
#define POINTS_WHEN_ENEMY_DIES gsRandom::nextInt(45, 55);
#define POINTS_WHEN_BULLET_STRIKES gsRandom::nextInt(1, 3); 

#define PLAYER_HEALTH 30
#define PLAYER_DEAD_TIME 1
#define PLAYER_BLINKING_TIME 2
#define PLAYER_BLINKING_INTERVAL 0.2

#define ENEMY_BURST_TIME 1.6
#define ENEMY_WAITING_TIME 3.8
#define ENEMY_INITIAL_WAITING_TIME 0.6
#define ENEMY_COOLDOWN_TIME 0.5
#define ENEMY_SHAKING_TIME 0.3
#define ENEMY_SHAKE_AMOUNT gsVector3(2.2f, 0, 0);

#define ENEMY_SPAWNER_COOLDOWN 6.0f
#define ENEMY_SPAWNER_TIMER 0.6f

//Enemy Simlen Attributes
#define ENEMY_SIMLEN_HEALTH 4
#define ENEMY_SIMLEN_BURSTWAITCOOLDOWN 2.5
#define ENEMY_SIMLEN_BURSTWAITTIME 0
#define ENEMY_SIMLEN_COOLDOWN 0.5
#define ENEMY_SIMLEN_COOLDOWNTIME 0 
#define ENEMY_SIMLEN_WAITING true
#define ENEMY_SIMLEN_CONE 80

//Enemy Slaien Attributes
#define ENEMY_SLAIEN_HEALTH 12
#define ENEMY_SLAIEN_BURSTWAITCOOLDOWN 3
#define ENEMY_SLAIEN_BURSTWAITTIME 0
#define ENEMY_SLAIEN_COOLDOWN 1
#define ENEMY_SLAIEN_COOLDOWNTIME 0
#define ENEMY_SLAIEN_WAITING true

//Enemy Fractalis Attributes
#define ENEMY_FRACTALIS_HEALTH 30
#define ENEMY_FRACTALIS_BURSTWAITCOOLDOWN 3.5
#define ENEMY_FRACTALIS_BURSTWAITTIME 0
#define ENEMY_FRACTALIS_COOLDOWN 1.5
#define ENEMY_FRACTALIS_COOLDOWNTIME 0
#define ENEMY_FRACTALIS_WAITING true

#define BULLET_DAMAGE_NORMAL 2.0f
#define BULLET_DAMAGE_SPIRAL 4.0f
#define BULLET_DAMAGE_SPREAD 2.5f
#define BULLET_NORMAL_COOLDOWN 0.40f
#define BULLET_SPREAD_COOLDOWN 0.09f
#define BULLET_SPREAD_CONE 120
#define BULLET_SPIRAL_COOLDOWN 0.40f
#define BULLET_SPIRAL_RADIUS 30
#define BULLET_SPIRAL_FREQUENCY 20

#define PHASE_RED_COLOR gsColor(0.921f, 0.16f, 0.052f)
#define PHASE_GREEN_COLOR gsColor(0.003f, 0.858f, 0.027f)
#define PHASE_BLUE_COLOR gsColor(0.145f, 0.56f, 0.682)
#define PHASE_YELLOW_COLOR gsColor(0.905f, 0.737f, 0.066f)
#define PHASE_MAGENTA_COLOR gsColor(1.0f, 0.454f, 0.870f)

#define UPGRADE_TIER_ONE_COST 250
#define UPGRADE_TIER_TWO_COST UPGRADE_TIER_ONE_COST + 200
#define UPGRADE_TIER_THREE_COST UPGRADE_TIER_TWO_COST + 400
#define UPGRADE_TIER_FOUR_COST UPGRADE_TIER_THREE_COST + 600
#define UPGRADE_TIER_FIVE_COST UPGRADE_TIER_FOUR_COST + 1000

#define PANORAMA_INITIAL_SPEED 50

#endif