#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#define JUMPINGFRAMES 60
#define JUMP_INIT_VY 11.4166666666 //initial velocity on the Y coord. //16.2
#define JUMP_INIT_AY 0.47568444444 //initial acceleration on the Y coord. //0.867

#define JUMP_TIME 3000
#define PUNCH_TIME 28
#define KICK_TIME 17


#define HEALTH_VALUE 129
#define MAXNUMOFCOLLIDERS 6



#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"

struct SDL_Texture;
struct collider;

enum player_states
{
	ST_UNKNOWN,

	ST_IDLE,
	ST_WALK_FORWARD,
	ST_WALK_BACKWARD,
	ST_JUMP_NEUTRAL,
	ST_JUMP_FORWARD,
	ST_JUMP_BACKWARD,
	ST_CROUCH,
	ST_PUNCH_STANDING,
	ST_PUNCH_NEUTRAL_JUMP,
	ST_PUNCH_FORWARD_JUMP,
	ST_PUNCH_BACKWARD_JUMP,
	ST_PUNCH_CROUCH,
	ST_KICK_STANDING,
	ST_SPECIAL
};

enum player_inputs
{
	IN_LEFT_DOWN,
	IN_LEFT_UP,
	IN_RIGHT_DOWN,
	IN_RIGHT_UP,
	IN_LEFT_AND_RIGHT,
	IN_JUMP,
	IN_CROUCH_UP,
	IN_CROUCH_DOWN,
	IN_JUMP_AND_CROUCH,
	IN_X,
	IN_KICK,
	IN_SPECIAL,
	IN_JUMP_FINISH,
	IN_PUNCH_FINISH
};



class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

	bool external_input(p2Qeue<player_inputs>& inputs);
	void internal_input(p2Qeue<player_inputs>& inputs);
	player_states process_fsm(p2Qeue<player_inputs>& inputs);

public:
	p2Qeue<player_inputs> inputs;
	player_states current_state = ST_UNKNOWN;
	
	Collider *colisionadores[MAXNUMOFCOLLIDERS];
	SDL_Texture* graphics = nullptr;
	SDL_Texture* ui = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	Animation kick;
	Animation punch;
	Animation tornado;
	Animation hurtLow;
	Animation jumpKick;
	Animation* current_animation;
	iPoint position;

	Uint32 jump_timer = 0;
	Uint32 punch_timer = 0;
	Uint32 kick_timer = 0;

	bool jumping = false;
	bool doingAction = false;
	bool punching = false;
	bool kicking = false;
	bool tornading = false;
	int jumpingframe = 0;
	int groundlevelaux = 0;
	bool getsHit = false;
	bool hasjumped = false;
	char sAction;
	bool godMode = false;
	bool playerFlip = false;
	int health = 0;
	//int attack_life = 0;
	//int attack_born = 0;
	int playerPivotX=0; //declare & inizialize pivot
	int playerPivotY = 0;//declare & inizialize pivot
};

#endif