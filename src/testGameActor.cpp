/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameActor.cpp
 */

#include "testGameActor.h"

TestGameActor::TestGameActor():
	sprite_onGround_("./game/images/zup_onGround.png", Window::renderer(),
			 30, 65),
	sprite_jumping_("./game/images/zup_jumping.png", Window::renderer(),
			30, 65),
	machine_(),
	frictionDelay_(0),
	spriteDelay_(0)
{
	posRect_ = {0, 0, 30, 65};
	setGravity(1);
	setHorizon(Window::height() - 70);

	spriteList_[SPRITE_ON_GROUND] = &sprite_onGround_;
	spriteList_[SPRITE_JUMPING] = &sprite_jumping_;
	currentSprite_ = spriteList_[SPRITE_ON_GROUND];

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
	updatePosAndSprite();

	machine_.update(*this);

	updateBullet(*this);
}

void
TestGameActor::render()
{
	currentSprite_->render(posRect_);

	renderBullet();
}

void
TestGameActor::updatePosAndSprite()
{
	moveBy(velX_, velY_);
	if (!isOnGround())
		velY_ += gravity_;

	if (posRect_.y + posRect_.h > horizon_)
		posRect_.y = horizon_ - posRect_.h;

	if (velX_ != 0) {
		if (++frictionDelay_ == 4) {
			velX_ -= velX_ * 0.5;
			frictionDelay_ = 0;
		}
	}

	if (++spriteDelay_ == 10) {
		currentSprite_->nextFrame();
		spriteDelay_ = 0;
	}
}

void
TestGameActor::moveRight()
{
	applyAcc(1, 0);
	direction_ = ACTOR_FACE_RIGHT;
	currentSprite_->setFlip(FLIP_NONE);
}

void
TestGameActor::moveLeft()
{
	applyAcc(-1, 0);
	direction_ = ACTOR_FACE_LEFT;
	currentSprite_->setFlip(FLIP_HORIZONTAL);
}
