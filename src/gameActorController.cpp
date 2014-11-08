/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorController.cpp
 */

#include "gameActorController.h"

GameActorController::GameActorController():
	keyState_(SDL_GetKeyboardState(nullptr))
{
	buttonKeyMap_[BUTTON_JUMP] = 		SDLK_z;
	buttonKeyMap_[BUTTON_NORMAL_ATTACK] = 	SDLK_x;
	buttonKeyMap_[BUTTON_SPECIAL_ATTACK] = 	SDLK_s;
	buttonKeyMap_[BUTTON_EVADE] = 		SDLK_a;

	buttonKeyMap_[BUTTON_UP] = 		SDLK_UP;
	buttonKeyMap_[BUTTON_DOWN] = 		SDLK_DOWN;
	buttonKeyMap_[BUTTON_RIGHT] = 		SDLK_RIGHT;
	buttonKeyMap_[BUTTON_LEFT] = 		SDLK_LEFT;
}

GameActorController::~GameActorController()
{
}

void
GameActorController::eventHandler(const SDL_Event& event)
{
	enum Buttons whichButton;
	SDL_Keycode keycode;

	switch (event.type) {
	case SDL_KEYUP:
	case SDL_KEYDOWN:
		/* No repeat fire */
		if (event.key.repeat)
			return;

		keycode = event.key.keysym.sym;

		if (keycode == buttonKeyMap_[BUTTON_UP])
			whichButton = BUTTON_UP;
		else if (keycode == buttonKeyMap_[BUTTON_DOWN])
			 whichButton = BUTTON_DOWN;
		else if (keycode == buttonKeyMap_[BUTTON_RIGHT])
			 whichButton = BUTTON_RIGHT;
		else if (keycode == buttonKeyMap_[BUTTON_LEFT])
			 whichButton = BUTTON_LEFT;
		else if (keycode == buttonKeyMap_[BUTTON_JUMP])
			 whichButton = BUTTON_JUMP;
		else if (keycode == buttonKeyMap_[BUTTON_EVADE])
			 whichButton = BUTTON_EVADE;
		else if (keycode == buttonKeyMap_[BUTTON_NORMAL_ATTACK])
			 whichButton = BUTTON_NORMAL_ATTACK;
		else if (keycode == buttonKeyMap_[BUTTON_SPECIAL_ATTACK])
			 whichButton = BUTTON_SPECIAL_ATTACK;

		if (event.key.state == SDL_PRESSED) {
			buttonPressed_[whichButton] = true;
			buttonReleased_[whichButton] = false;
		} else {
			buttonPressed_[whichButton] = false;
			buttonReleased_[whichButton] = true;
		}
		break;
	}
}

void
GameActorController::update()
{
	for (bool& e : buttonPressed_)
		e = false;

	for (bool& e : buttonReleased_)
		e = false;
}

bool
GameActorController::getButtonState(enum Buttons which) const
{
	/* TODO Make this flexible to change */
	switch (which) {
	case BUTTON_JUMP:
		return keyState_[SDL_SCANCODE_Z];
		break;
	case BUTTON_NORMAL_ATTACK:
		return keyState_[SDL_SCANCODE_X];
		break;
	case BUTTON_SPECIAL_ATTACK:
		return keyState_[SDL_SCANCODE_S];
		break;
	case BUTTON_EVADE:
		return keyState_[SDL_SCANCODE_A];
		break;
	case BUTTON_UP:
		return keyState_[SDL_SCANCODE_UP];
		break;
	case BUTTON_DOWN:
		return keyState_[SDL_SCANCODE_DOWN];
		break;
	case BUTTON_LEFT:
		return keyState_[SDL_SCANCODE_LEFT];
		break;
	case BUTTON_RIGHT:
		return keyState_[SDL_SCANCODE_RIGHT];
		break;
	default:
		return false;
		break;
	}
}

bool
GameActorController::ifButtonPressed(enum Buttons which) const
{
	return buttonPressed_[which];
}
