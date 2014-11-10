/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameActor.cpp
 */

#include "testGameActor.h"

TestGameActor::TestGameActor():
	machine_(),
	delay_(0)
{
	posRect_ = {0, 0, 30, 65};
	setGravity(1);
	setHorizon(570);

	machine_.onEnter(*this);
}

TestGameActor::~TestGameActor()
{
}

void
TestGameActor::handleInput(const GameActorController& controller)
{
	machine_.handleInput(*this, controller);
}

void
TestGameActor::update()
{
	moveBy(velX_, velY_);

	if (!isOnGround())
		velY_ += gravity_;

	if (velX_ != 0) {
		if (delay_++ == 5) {
			velX_ -= velX_ * 0.5;
			delay_ = 0;
		}
	}

	updateBullet(*this);

	machine_.update(*this);
	if (machine_.hasNext()) {
		machine_.onExit(*this);
		machine_.toNext();
		machine_.onEnter(*this);
	}
}

void
TestGameActor::render()
{
	SDL_SetRenderDrawColor(Window::renderer(), 0, 255, 30, 255);
	SDL_RenderFillRect(Window::renderer(), &posRect_);

	renderBullet();
}

void
TestGameActor::moveRight()
{
	applyAcc(1, 0);
	direction_ = ACTOR_FACE_RIGHT;
}

void
TestGameActor::moveLeft()
{
	applyAcc(-1, 0);
	direction_ = ACTOR_FACE_LEFT;
}

void
TestGameActor::jump()
{
	machine_.setNext(ACTOR_STATE_JUMPING);
}

void
TestGameActor::land()
{
	machine_.setNext(ACTOR_STATE_ON_GROUND);
}

void
TestGameActor::dive()
{
	machine_.setNext(ACTOR_STATE_DIVE);
}

void
TestGameActor::normalAttack()
{
	machine_.setNext(ACTOR_STATE_NORMAL_ATTACK);
}

void
TestGameActor::normalAirAttack()
{
	machine_.setNext(ACTOR_STATE_NORMAL_AIR_ATTACK);
}
