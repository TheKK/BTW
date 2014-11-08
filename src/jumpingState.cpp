/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: jumpingState.cpp
 */

#include "jumpingState.h"

void
JumpingState::onEnter(GameActor& actor)
{
	/* If you jump from ground */
	if (actor.isOnGround()) {
		frame = 0;
		actor.setVelY(0);
		actor.applyAcc(0, -10);
	}
}

void
JumpingState::onExit(GameActor& actor)
{
}

void
JumpingState::handleInput(GameActor& actor,
			  const GameActorController& controller)
{
	if (controller.getButtonState(BUTTON_RIGHT))
		actor.moveRight();

	if (controller.getButtonState(BUTTON_LEFT))
		actor.moveLeft();

	if (controller.getButtonState(BUTTON_DOWN))
		actor.dive();

	if (controller.ifButtonPressed(BUTTON_NORMAL_ATTACK))
		actor.normalAirAttack();

	if (!controller.getButtonState(BUTTON_JUMP))
		frame = 5;
}

void
JumpingState::update(GameActor& actor)
{
	if (frame++ < 5)
		actor.applyAcc(0, (-1 * (5 - frame)));

	if (actor.isOnGround())
		actor.land();
}
