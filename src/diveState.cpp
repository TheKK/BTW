/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: diveState.h
 */

#include "diveState.h"

void
DiveState::onEnter(GameActor& actor)
{
	actor.setVelX(0);
	actor.setVelY(10);
}

void
DiveState::onExit(GameActor& actor)
{
}

void
DiveState::eventHandler(GameActor& actor, const SDL_Event& event)
{
}

void
DiveState::update(GameActor& actor)
{
	if (actor.isOnGround()) {
		static int frame = 0;

		if (++frame == 10) {
			frame = 0;
			actor.land();
		}
	}
}
