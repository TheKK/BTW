/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState.h
 */

#ifndef TEST_GAME_STATE_H
#define TEST_GAME_STATE_H

#include <iostream>
#include <SDL.h>

#include "gameState.h"
#include "gameActor_Zup.h"
#include "gameActorController.h"
#include "texture.h"
#include "hpBar.h"
#include "window.h"

#include "testGameState_onFight.h"
#include "testGameState_onPause.h"

enum TestGameStateScript {
	SCRIPT_ON_FIGHT = 0x0000,
	SCRIPT_ON_PAUSE,

	SCRIPT_COUNT
};

class TestGameState : public GameState
{
friend class TestGameState_onFight;
friend class TestGameState_onPause;

public:
	TestGameState();
	~TestGameState();

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
	TestGameState_onFight onFight_;
	TestGameState_onPause onPause_;

	void changeScript_(enum TestGameStateScript which);
};

#endif /* TEST_GAME_STATE_H */
