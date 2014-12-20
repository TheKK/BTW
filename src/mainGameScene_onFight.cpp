/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameScene_onFight.cpp
 */

#include "mainGameScene_onFight.h"

#include "mainGameScene.h"
#include "graphics.h"

MainGameScene_onFight::MainGameScene_onFight(MainGameScene& scene):
	scene_(scene)
{
}

MainGameScene_onFight::~MainGameScene_onFight()
{
}

void
MainGameScene_onFight::eventHandler(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_QUIT:
		scene_.setNext(SCENE_QUIT);
		break;
	}

	scene_.controller_.eventHandler(event);
	scene_.controller2_.eventHandler(event);
}

void
MainGameScene_onFight::update()
{
	if (scene_.controller_.ifButtonPressed(BUTTON_UP))
		scene_.changeScript_(SCRIPT_ON_PAUSE);

	scene_.actor_.update();
	scene_.actor2_.update();

	scene_.actor_.testBulletCollision(scene_.actor2_);
	scene_.actor2_.testBulletCollision(scene_.actor_);

	scene_.boosHpBar_.update();

	scene_.controller_.clearState();
	scene_.controller2_.clearState();
}

void
MainGameScene_onFight::render(Graphics& graphics)
{
	scene_.backGroundBG_.render(graphics, nullptr);

	scene_.actor_.render(graphics);
	scene_.actor2_.render(graphics);

	scene_.backGroundFG_.render(graphics, nullptr);

	scene_.boosHpBar_.render(graphics);
}

