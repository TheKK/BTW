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
#include "window.h"

using namespace std;

class TestGameActor : public GameActor
{
public:
	TestGameActor();
	~TestGameActor();

	void handleInput(const GameActorController& controller);
	void update();
	void render();

	void moveRight();
	void moveLeft();
	void jump();
	void land();
	void dive();
	void normalAttack();
	void normalAirAttack();
private:
	TestStateMachine machine_;
};

#endif /* TEST_GAME_ACTOR_H */
