/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameActor.cpp
 */

#include "testGameActor.h"

TestGameActor::TestGameActor(SDL_Renderer* renderer)
{
	renderer_ = renderer;
	posRect_ = {0, 0, 20, 50};
}

TestGameActor::~TestGameActor()
{
}

void
TestGameActor::eventHandler(const SDL_Event& event)
{
	machine.currentState()->eventHandler(*this, event);
}

void
TestGameActor::update()
{
	machine.currentState()->update(*this);
	if (machine.next()) {
		machine.currentState()->onExit(*this);
		machine.changeStateTo(machine.next());
		machine.currentState()->onEnter(*this);
	}

	move(velX, velY);
	if (isOnGround()) {
		moveYto(720 - posRect_.h);
		velY = 0;
	} else {
		velY += gY;
	}

	if (velX > 0)
		velX -= velX * 0.4;
	else if (velX < 0)
		velX -= velX * 0.4;
}

void
TestGameActor::render()
{
	SDL_SetRenderDrawColor(renderer_, 0, 255, 30, 255);
	SDL_RenderFillRect(renderer_, &posRect_);
}

void
TestGameActor::applyAcc(int accX, int accY)
{
	velX += accX;
	velY += accY;
}

void
TestGameActor::setAccY(int n)
{
	velY = n;
}

void
TestGameActor::setGravity(int g)
{
	gY = g;
}

bool
TestGameActor::isOnGround()
{
	return (posRect_.y >= 720 - posRect_.h);
}
