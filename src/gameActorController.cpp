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
}

bool
GameActorController::getButtonState_(enum Buttons which) const
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
