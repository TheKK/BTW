/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: mainGameScene_onPause.h
 */

#ifndef MAIN_GAME_SCENE_ON_PAUSE_H
#define MAIN_GAME_SCENE_ON_PAUSE_H

#include <SDL.h>

#include "script.h"

class MainGameScene;

class MainGameScene_onPause : public Script
{
public:
	MainGameScene_onPause(MainGameScene& scene);
	~MainGameScene_onPause();

	void eventHandler(const SDL_Event& event);
	void update();
	void render();
private:
	MainGameScene& scene_;
};

#endif /* MAIN_GAME_SCENE_ON_PAUSE_H */
