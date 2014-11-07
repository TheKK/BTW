/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: jumpingState.cpp
 */

#include "jumpingState.h"

void
JumpingState::onEnter(GameActor& actor)
{
	cout << "jumping enter" << endl;

	setNext(nullptr);

	frame = 0;
}

void
JumpingState::onExit(GameActor& actor)
{
	cout << "jumping exit" << endl;
}

void
JumpingState::eventHandler(GameActor& actor, const SDL_Event& event)
{
}

void
JumpingState::update(GameActor& actor)
{
	const uint8_t* keyState = SDL_GetKeyboardState(nullptr);

	/* Check keyboard state */
	if (keyState[SDL_SCANCODE_LEFT])
		actor.applyAcc(-WALK_SPEED, 0);

	if (keyState[SDL_SCANCODE_RIGHT])
		actor.applyAcc(WALK_SPEED, 0);

	if (!keyState[SDL_SCANCODE_Z])
		frame = 7;

	if (frame++ < 7)
		actor.applyAcc(0, (-1 * (7 - frame)));

	if (actor.isOnGround())
		setNext("onGroundState");
}
