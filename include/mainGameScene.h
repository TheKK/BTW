/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameScene.h
 */

#ifndef MAIN_GAME_SCENE_H
#define MAIN_GAME_SCENE_H

#include <iostream>
#include <SDL.h>

#include "scene.h"
#include "gameActor_Zup.h"
#include "gameActorController.h"
#include "texture.h"
#include "hpBar.h"
#include "window.h"

#include "mainGameScene_onFight.h"
#include "mainGameScene_onPause.h"

enum MainGameSceneScript {
	SCRIPT_ON_FIGHT = 0x0000,
	SCRIPT_ON_PAUSE,

	SCRIPT_COUNT
};

class MainGameScene : public Scene
{
friend class MainGameScene_onFight;
friend class MainGameScene_onPause;

public:
	MainGameScene();
	~MainGameScene();

	void eventHandler(const SDL_Event& event);
	void update();
	void render();
private:
	GameActorController controller_;
	GameActorController controller2_;

	GameActor_Zup actor_;
	GameActor_Zup actor2_;

	HPBar boosHpBar_;

	Texture backGroundBG_;
	Texture backGroundFG_;

	vector<Script*> scripts_;
	Script* currentScript_ = NULL;
	MainGameScene_onFight onFight_;
	MainGameScene_onPause onPause_;

	void changeScript_(enum MainGameSceneScript which);
};

#endif /* MAIN_GAME_SCENE_H */
