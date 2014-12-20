/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameScene_onPause.cpp
 */

#include "mainGameScene_onPause.h"

#include "mainGameScene.h"

MainGameScene_onPause::MainGameScene_onPause(MainGameScene& scene):
	scene_(scene)
{
}

MainGameScene_onPause::~MainGameScene_onPause()
{
}

void
MainGameScene_onPause::eventHandler(const SDL_Event& event)
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
MainGameScene_onPause::update()
{
	if (scene_.controller_.ifButtonPressed(BUTTON_JUMP))
		scene_.changeScript_(SCRIPT_ON_FIGHT);

	scene_.controller_.clearState();
	scene_.controller2_.clearState();
}

void
MainGameScene_onPause::render()
{
	scene_.backGroundBG_.renderFullWindow();

	scene_.actor_.render();
	scene_.actor2_.render();

	scene_.backGroundFG_.renderFullWindow();

	scene_.boosHpBar_.render();
}

