/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameState.cpp
 */

#include "testGameState.h"

TestGameState::TestGameState():
	controller_(),
	controller2_("./game/setting/debugController.json"),

	actor_(controller_),
	actor2_(controller2_),

	backGroundBG_("./game/images/battleField.png", Window::renderer()),
	backGroundFG_("./game/images/battleFieldFG.png", Window::renderer()),

	onFight_(*this),
	onPause_(*this)
{
	boosHpBar_.bindGameActor(actor2_);

	scripts_.resize(0);
	scripts_.push_back(&onFight_);
	scripts_.push_back(&onPause_);

	SDL_assert(scripts_.size() == SCRIPT_COUNT);

	currentScript_ = scripts_[SCRIPT_ON_FIGHT];
}

TestGameState::~TestGameState()
{
}

void
TestGameState::eventHandler(const SDL_Event& event)
{
	currentScript_->eventHandler(event);
}

void
TestGameState::update()
{
	currentScript_->update();
}

void
TestGameState::render()
{
	currentScript_->render();
}

void
TestGameState::changeScript_(enum TestGameStateScript which)
{
	currentScript_ = scripts_[which];
}
