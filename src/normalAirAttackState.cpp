/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: normalAirAttackState.cpp
 */

#include "normalAirAttackState.h"

void
NormalAirAttackState::onEnter(GameActor& actor)
{
	frameCount = 0;

	actor.addBullet(new PotionBullet(actor));
}

void
NormalAirAttackState::onExit(GameActor& actor)
{
}

void
NormalAirAttackState::eventHandler(GameActor& actor, const SDL_Event& event)
{
}

void
NormalAirAttackState::update(GameActor& actor)
{
	if (++frameCount == 5)
		actor.jump();

	if (actor.isOnGround())
		actor.land();
}

