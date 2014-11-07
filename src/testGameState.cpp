/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState.cpp
 */

#include "testGameState.h"

TestGameState::TestGameState():
	actor(Window::renderer())
{
	actor.setGravity(1);
}

TestGameState::~TestGameState()
{
}

void
TestGameState::eventHandler(const SDL_Event& event)
{
	if (event.type == SDL_QUIT)
		setNext(GAME_STATE_QUIT);

	actor.eventHandler(event);
}

void
TestGameState::update()
{
	actor.update();
}

void
TestGameState::render()
{
	actor.render();
}
