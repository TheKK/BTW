/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState.cpp
 */

#include "testGameState.h"

TestGameState::TestGameState():
	controller_(),
	//controller2_("./game/setting/debugController.json"),
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

	controller_.eventHandler(event);
	//controller2_.eventHandler(event);
}

void
TestGameState::update()
{
	actor_.handleInput(controller_);
	actor_.update();

	//actor2_.handleInput(controller2_);
	//actor2_.update();

	controller_.update();
	//controller2_.update();
}

void
TestGameState::render()
{
	backGroundBG_.renderFullWindow();
	actor_.render();
	//actor2_.render();
	backGroundFG_.renderFullWindow();
}
