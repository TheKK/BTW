/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: hpBar.cpp
 */

#include "hpBar.h"

HPBar::HPBar()
{
	posRect_.x = 600;
	posRect_.y = 220;
	posRect_.w = 10;
	posRect_.h = -200;
}

HPBar::~HPBar()
{
}

void
HPBar::update()
{
	SDL_assert(actor_ != nullptr);

	posRect_.h = -actor_->hp() * 2;
	if (posRect_.h >= 0)
		posRect_.h = 0;
}

void
HPBar::render()
{
	SDL_SetRenderDrawColor(Window::renderer(),
			       200 * ((float) (200 + posRect_.h) / 200.0),
			       200 * ((float) (-posRect_.h) / 200.0),
			       10,
			       255);
	SDL_RenderFillRect(Window::renderer(), &posRect_);
}

void
HPBar::bindGameActor(const GameActor& actor)
{
	actor_ = &actor;
}
