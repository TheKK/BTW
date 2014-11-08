/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameActor.cpp
 */

#include "testGameActor.h"

TestGameActor::TestGameActor(SDL_Renderer* renderer)
{
	renderer_ = renderer;

	posRect_ = {0, 0, 30, 65};
	setGravity(1);
	setHorizon(570);

	machine_.currentState()->onEnter(*this);
}

TestGameActor::~TestGameActor()
{
}

void
TestGameActor::handleInput(const GameActorController& controller)
{
	machine_.currentState()->eventHandler(*this, event);
}

void
TestGameActor::update()
{
	moveBy(velX_, velY_);

	if (!isOnGround())
		velY_ += gravity_;

	if (velX_ != 0) {
		static int delay = 0;
		if (delay++ == 5) {
			velX_ -= velX_ * 0.5;
			delay = 0;
		}
	}

	updateBullet(*this);

	machine_.currentState()->update(*this);
	if (machine_.hasNext()) {
		machine_.currentState()->onExit(*this);
		machine_.toNext();
		machine_.currentState()->onEnter(*this);
	}
}

void
TestGameActor::render()
{
	SDL_SetRenderDrawColor(renderer_, 0, 255, 30, 255);
	SDL_RenderFillRect(renderer_, &posRect_);

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
	machine_.setNext(TEST_STATE_JUMPING);
}

void
TestGameActor::land()
{
	machine_.setNext(TEST_STATE_ON_GROUND);
}

void
TestGameActor::dive()
{
	machine_.setNext(TEST_STATE_DIVE);
}

void
TestGameActor::normalAttack()
{
	machine_.setNext(TEST_STATE_NORMAL_ATTACK);
}

void
TestGameActor::normalAirAttack()
{
	machine_.setNext(TEST_STATE_NORMAL_AIR_ATTACK);
}
