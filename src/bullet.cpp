/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: bullet.cpp
 */

#include "bullet.h"

void
Bullet::suicide()
{
	isDead_ = true;
}

bool
Bullet::isDead()
{
	return isDead_;
}

SDL_Rect*
Bullet::rect()
{
	return &posRect_;
}
