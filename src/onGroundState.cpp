/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: onGroundState.cpp
 */

#include "onGroundState.h"

void
OnGroundState::onEnter(GameActor& actor)
{
	const uint8_t* keyState = SDL_GetKeyboardState(nullptr);

	/* Check keyboard state */
	if (keyState[SDL_SCANCODE_RIGHT])
		moveRight_ = true;
	else
		moveRight_ = false;

	if (keyState[SDL_SCANCODE_LEFT])
		moveLeft_ = true;
	else
		moveLeft_ = false;

	dashRight_ = false;
}

void
OnGroundState::onExit(GameActor& actor)
{
}

void
OnGroundState::eventHandler(GameActor& actor, const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		if (event.key.repeat == 1)
			break;

		switch (event.key.keysym.sym) {
		case SDLK_RIGHT:
			moveRight_ = true;

			if (event.key.timestamp - buttonRightTimestamp <= 200)
				dashRight_ = true;
			buttonRightTimestamp = event.key.timestamp;
			break;
		case SDLK_LEFT:
			moveLeft_ = true;
			break;
		case SDLK_z:
			actor.jump();
			break;
		case SDLK_x:
			actor.normalAttack();
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_RIGHT:
			moveRight_ = false;
			break;
		case SDLK_LEFT:
			moveLeft_ = false;
			break;
		}
		break;
	}
}

void
OnGroundState::update(GameActor& actor)
{
	if (moveRight_)
		actor.moveRight();

	if (moveLeft_)
		actor.moveLeft();

	if (dashRight_) {
		actor.moveBy(70, 0);
		dashRight_ = false;
	}
}
