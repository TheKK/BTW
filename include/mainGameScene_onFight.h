/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameScene_onFight.h
 */

#ifndef MAIN_GAME_SCENE_ON_FIGHT_H
#define MAIN_GAME_SCENE_ON_FIGHT_H

#include <SDL.h>

#include "script.h"

class Graphics;
class MainGameScene;

class MainGameScene_onFight : public Script
{
public:
	MainGameScene_onFight(MainGameScene& scene);
	~MainGameScene_onFight();

	void eventHandler(const SDL_Event& event);
	void update();
	void render(Graphics& graphics);
private:
	MainGameScene& scene_;
};

#endif /* MAIN_GAME_SCENE_ON_FIGHT_H */
