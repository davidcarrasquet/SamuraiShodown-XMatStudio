#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "p2Qeue.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"


#define JUMPINGFRAMES 60
#define JUMP_INIT_VY 11.4166666666 //initial velocity on the Y coord. //16.2
#define JUMP_INIT_AY 0.47568444444 //initial acceleration on the Y coord. //0.867

#define JUMP_TIME 3000
#define PUNCH_TIME 28
#define KICK_TIME 17

#define HEALTH_VALUE 129
#define MAXNUMOFCOLLIDERS 6
#define FALLBOUNCES 1


struct SDL_Texture;
struct collider;

enum player2_states
{
	ST_UNKNOWN2,

	ST_IDLE2,
	ST_WALK_FORWARD2,
	ST_WALK_BACKWARD2,
	ST_JUMP_NEUTRAL2,
	ST_JUMP_FORWARD2,
	ST_JUMP_BACKWARD2,
	ST_CROUCH2,
	ST_PUNCH_STANDING2,
	ST_PUNCH_NEUTRAL_JUMP2,
	ST_PUNCH_FORWARD_JUMP2,
	ST_PUNCH_BACKWARD_JUMP2,
	ST_PUNCH_CROUCH2,
	ST_KICK_STANDING2,
	ST_KICK_NEUTRAL_JUMP2,
	ST_KICK_FORWARD_JUMP2,
	ST_KICK_BACKWARD_JUMP2,
	ST_SPECIAL2,
	ST_FALLING2,
	ST_KICK_CROUCH2
	//new
	//new
};

enum player2_inputs
{
	IN_LEFT_DOWN2,
	IN_LEFT_UP2,
	IN_RIGHT_DOWN2,
	IN_RIGHT_UP2,
	IN_LEFT_AND_RIGHT2,
	IN_JUMP2,
	IN_CROUCH_UP2,
	IN_CROUCH_DOWN2,
	IN_JUMP_AND_CROUCH2,
	IN_X2,
	IN_KICK2,
	IN_SPECIAL2,
	IN_JUMP_FINISH2,
	IN_JUMP_KICK_FINISH2,
	IN_JUMP_PUNCH_FINISH2,
	IN_PUNCH_FINISH2,
	IN_FALL_FINISH2,//new
	IN_FALL2,
	IN_DEATH2
};


class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

	bool external_input(p2Qeue<player2_inputs>& p2inputs, p2Qeue<player_inputs>& inputs);
	void internal_input(p2Qeue<player2_inputs>& p2inputs);
	player2_states process_fsm(p2Qeue<player2_inputs>& p2inputs);

public:
	p2Qeue<player2_inputs> p2inputs;
	player2_states current_state = ST_UNKNOWN2;

	Collider *colisionadores[MAXNUMOFCOLLIDERS];
	SDL_Texture * graphics = nullptr;
	SDL_Texture* ui = nullptr;
	SDL_Texture* shadow = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	Animation kick;
	Animation punch;
	Animation tornado;
	Animation hurtLow;
	Animation* current_animation;
	Animation jumpKick;
	Animation jumpPunch;
	Animation jumpBackward;
	Animation jumpFw;
	Animation jumpFwPunch;
	Animation crouch;
	Animation crouchKick;
	Animation crouchPunch;
	Animation getUp;
	Animation fall;
	iPoint position;

	Uint32 p2jump_timer = 0;
	Uint32 p2punch_timer = 0;
	Uint32 p2kick_timer = 0;
	Uint32 fall_bounces = 0;//new

	//Collider* body = nullptr;

	bool jumping = false;
	bool doingAction = false;
	bool punching = false;
	bool kicking = false;
	int jumpingframe = 0;
	int groundlevelaux = 0;
	bool tornading = false;
	bool getsHit = false;
	bool hasjumped = false;
	char sAction;
	bool godMode2 = false;
	bool playerFlip = true;
	bool invencibleframes = false;
	bool JumpPunching = false;
	bool JumpKicking = false;
	bool crouchpunching = false;
	bool crouchkicking = false;
	bool airhit = false;
	
	bool jumpleft = false;
	bool jumpright = false;
	bool crouching = false;
	bool neutralJumpPunching = false;
	bool audioPlayed = false;
	int health = 100;
	int falling = false;//new
	int posyaux;//new
	int aux = 10;
	int invencibleaux = 0;
	int delay = 0;

	int playerPivotX = 0; //declare & inizialize pivot
	int playerPivotY = 0;//declare & inizialize pivot

};

#endif
