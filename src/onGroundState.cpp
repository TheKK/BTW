/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: onGroundState.cpp
 */

#include "onGroundState.h"

void
OnGroundState::onEnter(GameActor& actor)
{
	cout << "on gournd enter" << endl;

	setNext(nullptr);
}

void
OnGroundState::onExit(GameActor& actor)
{
	cout << "on ground exit" << endl;
}

void
OnGroundState::eventHandler(GameActor& actor, const SDL_Event& event)
{
}

void
OnGroundState::update(GameActor& actor)
{
	const uint8_t* keyState = SDL_GetKeyboardState(nullptr);

	/* Check keyboard state */
	if (keyState[SDL_SCANCODE_LEFT])
		actor.applyAcc(-WALK_SPEED, 0);

	if (keyState[SDL_SCANCODE_RIGHT])
		actor.applyAcc(WALK_SPEED, 0);

	if (keyState[SDL_SCANCODE_Z])
		setNext("jumpingState");
}
