/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testStateMachine.h
 */

#ifndef TEST_STATE_MACHINE_H
#define TEST_STATE_MACHINE_H

#include <iostream>
#include <vector>
#include <SDL.h>

#include "stateMachine.h"
#include "gameActor.h"
#include "gameActorController.h"
#include "logLocator.h"

using namespace std;

class TestStateMachine
{
public:
	TestStateMachine();
	~TestStateMachine();

	//void bindState(enum ActorStates which, State* state);

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);
	void handleInput(GameActor& actor,
			 const GameActorController& controller);
	void update(GameActor& actor);

	void setNext(char* nextState);
	bool hasNext();
	void toNext();

	/* For Lua use */
	static int lua_setNext(lua_State* L);
private:
	lua_State* states_;

	string currentState_;
	string nextState_;
};

#endif /* TEST_STATE_MACHINE_H */
