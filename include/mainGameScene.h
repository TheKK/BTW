/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameScene.h
 */

#ifndef MAIN_GAME_SCENE_H
#define MAIN_GAME_SCENE_H

#include <SDL.h>

#include "controller.h"
#include "scene.h"
#include "gameActor_Zup.h"
#include "texture.h"
#include "hpBar.h"

#include "mainGameScene_onFight.h"
#include "mainGameScene_onPause.h"

enum MainGameSceneScript {
	SCRIPT_ON_FIGHT = 0x0000,
	SCRIPT_ON_PAUSE,

	SCRIPT_COUNT
};

class Graphics;

class MainGameScene : public Scene
{
friend class MainGameScene_onFight;
friend class MainGameScene_onPause;

public:
	MainGameScene(Graphics& graphics);
	~MainGameScene();

	void eventHandler(const SDL_Event& event);
	void update();
	void render(Graphics& graphics);
private:
	Controller controller_;
	Controller controller2_;

	GameActor_Zup actor_;
	GameActor_Zup actor2_;

	HPBar boosHpBar_;

	Texture backGroundBG_;
	Texture backGroundFG_;

	std::vector<Script*> scripts_;
	Script* currentScript_ = NULL;
	MainGameScene_onFight onFight_;
	MainGameScene_onPause onPause_;

	void changeScript_(enum MainGameSceneScript which);
};

#endif /* MAIN_GAME_SCENE_H */
