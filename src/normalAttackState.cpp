/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: normalAttackState.cpp
 */

#include "normalAttackState.h"

void
NormalAttackState::onEnter(GameActor& actor)
{
	frameCount = 0;

	actor.addBullet(new PotionBullet(actor));
}

void
NormalAttackState::onExit(GameActor& actor)
{
}

void
NormalAttackState::eventHandler(GameActor& actor, const SDL_Event& event)
{
}

void
NormalAttackState::update(GameActor& actor)
{
	if (++frameCount == 5)
		actor.land();
}

