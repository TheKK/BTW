/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor.cpp
 */

#include "gameActor.h"

GameActor::GameActor()
{
	spriteList_.resize(SPRITE_COUNT);
}

GameActor::~GameActor()
{
	for (auto e : bulletList_)
		delete e;

	bulletList_.clear();
}

void
GameActor::addBullet(Bullet* bullet)
{
	bulletList_.push_back(bullet);
}

void
GameActor::updateBullet(GameActor& target)
{
	for (auto it = bulletList_.rbegin(); it != bulletList_.rend(); it++) {
		(*it)->update(target);

		if ((*it)->isDead()) {
			delete (*it);
			bulletList_.erase(next(it).base());
		}
	}
}

void
GameActor::renderBullet()
{
	for (const auto it : bulletList_)
		it->render();
}

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
GameActor::setAsInvisible()
{
	isInvisible_ = true;
}

void
GameActor::setAsVisible()
{
	isInvisible_ = false;
}

bool
GameActor::isInvisible()
{
	return isInvisible_;
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

int
GameActor::getGravity()
{
	return gravity_;
}

int
GameActor::getHorizon()
{
	return horizon_;
}

bool
GameActor::isOnGround()
{
	return (posRect_.y + posRect_.h >= horizon_);
}

enum ActorDirection
GameActor::direction()
{
	return direction_;
}

void
GameActor::moveBy(int dx, int dy)
{
	posRect_.x += dx;
	posRect_.y += dy;
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

void
GameActor::setSprite(enum ActorSprite which)
{
	currentSprite_ = spriteList_[which];
	currentSprite_->jumpTo(0);
}
