/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor_Zup.cpp
 */

#include "gameActor_Zup.h"

GameActor_Zup::GameActor_Zup():
	sprite_onGround_("./game/images/zup_onGround.png", Window::renderer(),
			 30, 65),
	sprite_jumping_("./game/images/zup_jumping.png", Window::renderer(),
			30, 65),
	stateMachine_("./game/scripts/character/Zup/states.lua"),
	frictionDelay_(0),
	spriteDelay_(0)
{
	posRect_ = {0, 0, 30, 65};
	setGravity(1);
	setHorizon(Window::height() - 70);

	spriteList_[SPRITE_ON_GROUND] = &sprite_onGround_;
	spriteList_[SPRITE_JUMPING] = &sprite_jumping_;
	currentSprite_ = spriteList_[SPRITE_ON_GROUND];

	stateMachine_.onEnter(*this);
}

GameActor_Zup::~GameActor_Zup()
{
}

void
GameActor_Zup::handleInput(const GameActorController& controller)
{
	stateMachine_.handleInput(*this, controller);
}

void
GameActor_Zup::update()
{
	updatePosAndSprite();

	stateMachine_.update(*this);

	updateBullet(*this);
}

void
GameActor_Zup::render()
{
	if (direction_ == ACTOR_FACE_RIGHT)
		currentSprite_->setFlip(FLIP_NONE);
	else
		currentSprite_->setFlip(FLIP_HORIZONTAL);

	currentSprite_->render(posRect_);

	renderBullet();
}

void
GameActor_Zup::updatePosAndSprite()
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
GameActor_Zup::moveRight()
{
	applyAcc(1, 0);
	direction_ = ACTOR_FACE_RIGHT;
}

void
GameActor_Zup::moveLeft()
{
	applyAcc(-1, 0);
	direction_ = ACTOR_FACE_LEFT;
}
