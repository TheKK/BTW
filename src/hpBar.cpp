/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: hpBar.cpp
 */

#include "hpBar.h"

#include "gameActor.h"
#include "graphics.h"

HPBar::HPBar(Graphics& graphics):
	hpBarTex_("./game/images/boss_hp_bar.png", graphics)
{
	posRect_.x = 600;
	posRect_.y = 30;
	posRect_.w = 20;
	posRect_.h = 150;
}

HPBar::~HPBar()
{
}

void
HPBar::update()
{
	//SDL_assert(actor_ != nullptr);
}

void
HPBar::render(Graphics& graphics)
{
	hpBarTex_.render(graphics, &posRect_);
}

void
HPBar::bindGameActor(const GameActor& actor)
{
	actor_ = &actor;
}
