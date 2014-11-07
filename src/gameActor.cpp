/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor.cpp
 */

#include "gameActor.h"

void
GameActor::move(int dx, int dy)
{
	posRect_.x += dx;
	posRect_.y += dy;
}

void
GameActor::moveXto(int n)
{
	posRect_.x = n;
}

void
GameActor::moveYto(int n)
{
	posRect_.y = n;
}

void
GameActor::setW(int n)
{
	posRect_.w = n;
}

void
GameActor::setH(int n)
{
	posRect_.h = n;
}

void
GameActor::setRenderer(SDL_Renderer* renderer)
{
	renderer_ = renderer;
}

int
GameActor::x() const
{
	return posRect_.x;
}

int
GameActor::y() const
{
	return posRect_.y;
}

int
GameActor::w() const
{
	return posRect_.w;
}

int
GameActor::h() const
{
	return posRect_.h;
}

SDL_Rect*
GameActor::rect()
{
	return &posRect_;
}

SDL_Renderer*
GameActor::renderer() const
{
	return renderer_;
}
