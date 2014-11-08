/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: potionBullet.cpp
 */

#include "potionBullet.h"

PotionBullet::PotionBullet(GameActor& caster)
{
	posRect_ = {(caster.x() + 20), (caster.y()) + 10, 20, 20};
	horizon_ = caster.getHorizon();
	delay_ = 0;

	if (caster.direction() == ACTOR_FACE_RIGHT)
		velX_ = 10;
	else
		velX_ = -10;
	velY_ = -10;
	gravity_ = 1;
}

PotionBullet::~PotionBullet()
{
}

void
PotionBullet::update(GameActor& target)
{
	if (!isOnGround_()) {
		velY_ += gravity_;

		posRect_.x += velX_;
		posRect_.y += velY_;
	} else {
		if (++delay_ == 30)
			suicide();
	}
}

void
PotionBullet::render()
{
	SDL_SetRenderDrawColor(Window::renderer(), 50, 100, 30, 255);
	SDL_RenderFillRect(Window::renderer(), &posRect_);
}

bool
PotionBullet::isOnGround_()
{
	return (posRect_.y + posRect_.h >= horizon_);
}
