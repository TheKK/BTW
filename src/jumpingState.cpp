/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: jumpingState.cpp
 */

#include "jumpingState.h"

void
JumpingState::onEnter(GameActor& actor)
{
	frame = 0;

	actor.setVelY(0);
	actor.applyAcc(0, -10);
}

void
JumpingState::onExit(GameActor& actor)
{
}

void
JumpingState::eventHandler(GameActor& actor, const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		if (event.key.repeat == 1)
			break;

		switch (event.key.keysym.sym) {
		case SDLK_DOWN:
			actor.dive();
			break;
		}
		break;
	}
}

void
JumpingState::update(GameActor& actor)
{
	const uint8_t* keyState = SDL_GetKeyboardState(nullptr);

	/* Check keyboard state */
	if (keyState[SDL_SCANCODE_LEFT])
		actor.moveLeft();

	if (keyState[SDL_SCANCODE_RIGHT])
		actor.moveRight();

	if (!keyState[SDL_SCANCODE_Z])
		frame = 5;

	if (frame++ < 5)
		actor.applyAcc(0, (-1 * (5 - frame)));

	if (actor.isOnGround())
		actor.land();
}
