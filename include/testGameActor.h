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
#include "sprite.h"
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
private:
	Sprite sprite_onGround_;
	//Sprite sprite_onGroundAttack_;
	Sprite sprite_jumping_;
	//Sprite sprite_jumpingAttack_;

	TestStateMachine machine_;
	int delay_;
};

#endif /* TEST_GAME_ACTOR_H */
