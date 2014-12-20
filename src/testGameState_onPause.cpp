/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState_onPause.cpp
 */

#include "testGameState_onPause.h"

#include "testGameState.h"

TestGameState_onPause::TestGameState_onPause(TestGameState& scene):
	scene_(scene)
{
}

TestGameState_onPause::~TestGameState_onPause()
{
}

void
TestGameState_onPause::eventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_QUIT:
		scene_.setNext(GAME_STATE_QUIT);
		break;
	}

	scene_.controller_.updateState(event);
	scene_.controller2_.updateState(event);
}

void
TestGameState_onPause::update()
{
	if (scene_.controller_.ifButtonPressed(BUTTON_JUMP))
		scene_.changeScript_(SCRIPT_ON_FIGHT);
}

void
TestGameState_onPause::render()
{
	scene_.backGroundBG_.renderFullWindow();

	scene_.actor_.render();
	scene_.actor2_.render();

	scene_.backGroundFG_.renderFullWindow();

	scene_.boosHpBar_.render();
}

