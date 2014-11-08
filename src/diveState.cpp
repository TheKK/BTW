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

	delayFrame = 0;
}

void
DiveState::onExit(GameActor& actor)
{
}

void
DiveState::handleInput(GameActor& actor, const GameActorController& controller)
{
}

void
DiveState::update(GameActor& actor)
{
	if (actor.isOnGround()) {
		if (++delayFrame == DIVE_DELAY) {
			actor.land();
		}
	}
}
