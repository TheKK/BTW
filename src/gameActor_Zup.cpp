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

bool operator<(const GameActor_Zup::SpriteState& a,
	       const GameActor_Zup::SpriteState& b)
{
	if (a.motionType != b.motionType)
		return a.motionType < b.motionType;

	if (a.horizontalFacing != b.horizontalFacing)
		return a.horizontalFacing < b.horizontalFacing;

	return false;
}

GameActor_Zup::GameActor_Zup(Graphics& graphics, const Controller& controller):
	spriteDelay_(0)
{
	stateMachine_ =
		new LuaStateMachine("./game/scripts/character/Zup/states.lua");
	stateMachine_->bindActor(*this);
	stateMachine_->bindController(controller);

	pos_.setRect(0, 0, 30, 65);

	gravity_ = 0.03;

	/* XXX Bad hack */
	horizon_ = graphics.h() - 70;

	initSprites_(graphics);

	stateMachine_->onEnter();
}

GameActor_Zup::~GameActor_Zup()
{
	for (auto& e : spriteSheets_)
		delete e.second;

	spriteSheets_.clear();
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
	spriteSheets_[getSpriteState_()]->render(graphics, pos_.rect());

	renderBullet();
}

void
GameActor_Zup::updateSprite()
{
	if (++spriteDelay_ == 10) {
		spriteSheets_[getSpriteState_()]->nextFrame();
		spriteDelay_ = 0;
	}

	if (direction_ == FACE_RIGHT)
		spriteSheets_[getSpriteState_()]->setFlip(FLIP_NONE);
	else
		spriteSheets_[getSpriteState_()]->setFlip(FLIP_HORIZONTAL);
}

void
GameActor_Zup::updatePosition()
{
	pos_.moveBy(velX_, velY_);

	/* Horizontal movement */
	velX_ += accX_;
	if (accX_ > 0.0f)
		velX_ = std::min(velX_, walkingSpeedMax);
	else if (accX_ < 0.0f)
		velX_ = std::max(velX_, -walkingSpeedMax);
	else
		velX_ *= slowdownFator;

	/* Vertival movement */
	velY_ += accY_;
	if (!isOnGround())
		accY_ += gravity_;
	else
		accY_ = 0.0f;

	if (pos_.button() > horizon_)
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

void
GameActor_Zup::initSprites_(Graphics& graphics)
{
	spriteSheets_[SpriteState(RIGHT, STANDING)] = 
		new Sprite("./game/images/zup_onGround.png", graphics, 30, 65);

	spriteSheets_[SpriteState(RIGHT, WALKING)] = 
		new Sprite("./game/images/zup_jumping.png", graphics, 30, 65);
}

const GameActor_Zup::SpriteState
GameActor_Zup::getSpriteState_() const
{
	return SpriteState(
		RIGHT,
		(accX_ == 0.0f) ? STANDING : WALKING);
}
