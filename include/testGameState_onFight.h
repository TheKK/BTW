/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState_onFight.h
 */

#ifndef TEST_GAME_STATE_ON_FIGHT_H
#define TEST_GAME_STATE_ON_FIGHT_H

#include <SDL.h>

#include "script.h"

class TestGameState;

class TestGameState_onFight : public Script
{
public:
	TestGameState_onFight(TestGameState& scene);
	~TestGameState_onFight();

	void eventHandler(const SDL_Event& event);
	void update();
	void render();
private:
	TestGameState& scene_;
};

#endif /* TEST_GAME_STATE_ON_FIGHT_H */
