/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorController.cpp
 */

#include "gameActorController.h"

GameActorController::GameActorController():
	keyState_(SDL_GetKeyboardState(nullptr)
)
{
}

GameActorController::~GameActorController()
{
}

void
GameActorController::eventHandler(const SDL_Event& event)
{
	enum Buttons whichButton;

	switch (event.type) {
	case SDL_KEYUP:
	case SDL_KEYDOWN:
		/* No repeat fire */
		if (event.key.repeat)
			return;

		switch (event.key.keysym.sym) {
		case SDLK_UP:
			whichButton = BUTTON_UP;
			break;
		case SDLK_DOWN:
			whichButton = BUTTON_DOWN;
			break;
		case SDLK_RIGHT:
			whichButton = BUTTON_RIGHT;
			break;
		case SDLK_LEFT:
			whichButton = BUTTON_LEFT;
			break;
		case SDLK_z:
			whichButton = BUTTON_JUMP;
			break;
		case SDLK_x:
			whichButton = BUTTON_NORMAL_ATTACK;
			break;
		case SDLK_a:
			whichButton = BUTTON_EVADE;
			break;
		case SDLK_s:
			whichButton = BUTTON_SPECIAL_ATTACK;
			break;
		default:
			return;
		}

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
