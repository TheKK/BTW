/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor.cpp
 */

#include "gameActor.h"

void
GameActor::applyAcc(int accX, int accY)
{
	velX_ += accX;
	velY_ += accY;
}

void
GameActor::setVelX(int n)
{
	velX_ = n;
}

void
GameActor::setVelY(int n)
{
	velY_ = n;
}

void
GameActor::setGravity(int g)
{
	gravity_ = g;
}

void
GameActor::setHorizon(int h)
{
	horizon_ = h;
}

bool
GameActor::isOnGround()
{
	return (posRect_.y + posRect_.h >= horizon_);
}

void
GameActor::moveBy(int dx, int dy)
{
	posRect_.x += dx;
	posRect_.y += dy;

	if (posRect_.y + posRect_.h > horizon_)
		posRect_.y = horizon_ - posRect_.h;
}

void
GameActor::moveTo(int x, int y)
{
	posRect_.x = x;
	posRect_.y = y;
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
