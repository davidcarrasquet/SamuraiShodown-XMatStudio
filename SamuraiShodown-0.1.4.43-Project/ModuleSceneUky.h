#ifndef __MODULESCENEUKY_H__
#define __MODULESCENEUKY_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneUky : public Module
{
public:
	ModuleSceneUky();
	~ModuleSceneUky();

	bool Start();
	update_status Update();
	bool CleanUp();


public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* ui = nullptr;
	SDL_Rect ground;
	SDL_Rect foreground;
	SDL_Rect background;

	Animation backgroundanim;

	void roundFinish();
	void BattleEnd();


	//text vars
	bool start = false;
};

#endif // __MODULESCENEUKY_H__