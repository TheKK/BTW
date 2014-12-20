/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor_Zup.cpp
 */

#include "gameActor_Zup.h"

#include <cmath>

#include "window.h"
#include "potionBullet.h"
#include "luaStateMachine.h"
#include "graphics.h"

GameActor_Zup::GameActor_Zup(Graphics& graphics, const Controller& controller):
	sprite_onGround_("./game/images/zup_onGround.png", graphics,
			 30, 65),
	sprite_normalAttack_("./game/images/zup_normalAttack.png",
			     graphics, 30, 65),
	sprite_jumping_("./game/images/zup_jumping.png", graphics,
			30, 65),

	frictionDelay_(0),
	gravityDelay_(0),
	spriteDelay_(0)
{
	stateMachine_ =
		new LuaStateMachine("./game/scripts/character/Zup/states.lua");
	stateMachine_->bindActor(*this);
	stateMachine_->bindController(controller);

	pos_.setRect(0, 0, 30, 65);

	gravity_ = 1;
	horizon_ = graphics.h() - 70;

	spriteList_[SPRITE_ON_GROUND] = &sprite_onGround_;
	spriteList_[SPRITE_NORMAL_ATTACK] = &sprite_normalAttack_;
	spriteList_[SPRITE_JUMPING] = &sprite_jumping_;
	currentSprite_ = spriteList_[SPRITE_ON_GROUND];

	stateMachine_->onEnter();
}

GameActor_Zup::~GameActor_Zup()
{
}

void
GameActor_Zup::handleInput()
{
	stateMachine_->handleInput();
}

void
GameActor_Zup::update()
{
	handleInput();
	updateSprite();
	updatePosition();
	updateBullet(*this);

	stateMachine_->update();
}

void
GameActor_Zup::render(Graphics& graphics)
{
	if (direction_ == FACE_RIGHT)
		currentSprite_->setFlip(FLIP_NONE);
	else
		currentSprite_->setFlip(FLIP_HORIZONTAL);

	currentSprite_->render(graphics, &pos_.rect());

	renderBullet();
}

void
GameActor_Zup::updateSprite()
{
	if (++spriteDelay_ == 10) {
		currentSprite_->nextFrame();
		spriteDelay_ = 0;
	}
}

void
GameActor_Zup::updatePosition()
{
	pos_.moveBy(round(velX_), velY_);
	velX_ += accX_;
	if (accX_ > 0.0f)
		velX_ = std::min(velX_, walkingSpeedMax);
	else if (accX_ < 0.0f)
		velX_ = std::max(velX_, -walkingSpeedMax);
	else
		velX_ *= slowdownFator;

	if ((!isOnGround()) && (++gravityDelay_ == 2)) {
		velY_ += gravity_;
		gravityDelay_ = 0;
	}

	if (pos_.y() + pos_.h() > horizon_)
		pos_.setY(horizon_ - pos_.h());
}

void
GameActor_Zup::movingRight()
{
	direction_ = FACE_RIGHT;

	accX_ = walkingAcceleration;
}

void
GameActor_Zup::movingLeft()
{
	direction_ = FACE_LEFT;

	accX_ = -walkingAcceleration;
}

void
GameActor_Zup::stopMoving()
{
	accX_ = 0.0f;
}

void
GameActor_Zup::normalAttack()
{
	addBullet(new PotionBullet(*this));
}
