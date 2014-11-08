/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState.cpp
 */

#include "testGameState.h"

TestGameState::TestGameState():
	actor_(Window::renderer()),
	backGroundBG_("./game/images/battleField.png", Window::renderer()),
	backGroundFG_("./game/images/battleFieldFG.png", Window::renderer())
{
}

TestGameState::~TestGameState()
{
}

void
TestGameState::eventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_QUIT:
		setNext(GAME_STATE_QUIT);
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (event.button.button == SDL_BUTTON_MIDDLE) {
			cout << "x, y: " << event.button.x << ":"
				<< event.button.y << endl;
		}
		break;
	}

	actor_.eventHandler(event);
}

void
TestGameState::update()
{
	actor_.update();
}

void
TestGameState::render()
{
	backGroundBG_.renderFullWindow();
	actor_.render();
	backGroundFG_.renderFullWindow();
}
