/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState_onPause.h
 */

#ifndef TEST_GAME_STATE_ON_PAUSE_H
#define TEST_GAME_STATE_ON_PAUSE_H

#include <SDL.h>

#include "script.h"

class TestGameState;

class TestGameState_onPause : public Script
{
public:
	TestGameState_onPause(TestGameState& scene);
	~TestGameState_onPause();

	void eventHandler(const SDL_Event& event);
	void update();
	void render();
private:
	TestGameState& scene_;
};

#endif /* TEST_GAME_STATE_ON_PAUSE_H */
