/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameScene.cpp
 */

#include "mainGameScene.h"

#include "window.h"

MainGameScene::MainGameScene():
	controller_("./game/setting/controller.json"),
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

MainGameScene::~MainGameScene()
{
}

void
MainGameScene::eventHandler(const SDL_Event& event)
{
	currentScript_->eventHandler(event);
}

void
MainGameScene::update()
{
	currentScript_->update();
}

void
MainGameScene::render()
{
	currentScript_->render();
}

void
MainGameScene::changeScript_(enum MainGameSceneScript which)
{
	currentScript_ = scripts_[which];
}
