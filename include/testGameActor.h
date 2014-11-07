/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testGameActor.h
 */

#ifndef TEST_GAME_ACTOR_H
#define TEST_GAME_ACTOR_H

#include <iostream>
#include <SDL.h>

#include "gameActor.h"
#include "testStateMachine.h"

using namespace std;

class TestGameActor : public GameActor
{
public:
	TestGameActor(SDL_Renderer* renderer);
	~TestGameActor();

	void eventHandler(const SDL_Event& evnet);
	void update();
	void render();

	void applyAcc(int accX, int accY);
	void setAccY(int n);
	void setGravity(int g);

	bool isOnGround();
private:
	TestStateMachine machine;
};

#endif /* TEST_GAME_ACTOR_H */
