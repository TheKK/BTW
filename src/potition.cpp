/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: position.cpp
 */

#include "position.h"

#include <cmath>

Position::Position()
{
}

Position::Position(float x, float y, int w, int h)
{
	posX_ = x;
	posY_ = y;

	posRect_.w = w;
	posRect_.h = h;
}

Position::~Position()
{
}

void
Position::moveBy(float dx, float dy)
{
	posX_ += dx;
	posY_ += dy;
}

void
Position::moveTo(float x, float y)
{
	posX_ = x;
	posY_ = y;
}

void
Position::setX(float n)
{
	posX_ = n;
}

void
Position::setY(float n)
{
	posY_ = n;
}

void
Position::setW(int n)
{
	posRect_.w = n;
}

void
Position::setH(int n)
{
	posRect_.h = n;
}

void
Position::setRect(float x, float y, int w, int h)
{
	posX_ = x;
	posY_ = y;

	posRect_.w = w;
	posRect_.h = h;
}

int
Position::x() const
{
	return round(posX_);
}

int
Position::y() const
{
	return round(posY_);
}

int
Position::w() const
{
	return posRect_.w;
}

int
Position::h() const
{
	return posRect_.h;
}

int
Position::top() const
{
	return round(posX_);
}

int
Position::button() const
{
	return round(posY_ + posRect_.h);
}

int
Position::left() const
{
	return round(posY_);
}

int
Position::right() const
{
	return round(posX_ + posRect_.w);
}

const SDL_Rect*
Position::rect()
{
	posRect_.x = round(posX_);
	posRect_.y = round(posY_);

	return &posRect_;
}
