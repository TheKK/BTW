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
#include "onGroundState.h"
#include "jumpingState.h"
#include "diveState.h"

using namespace std;

enum TestState
{
	TEST_STATE_ON_GROUND = 0x00,
	TEST_STATE_JUMPING,
	TEST_STATE_DIVE,

	TEST_STATE_COUNT,

	TEST_STATE_NULL
};

class TestStateMachine
{
public:
	TestStateMachine();
	~TestStateMachine() {};

	State* currentState();

	void setNext(enum TestState state);
	bool hasNext();
	void toNext();
private:
	vector<State*> stateList_;
	OnGroundState onGroundState_;
	JumpingState jumpingState_;;
	DiveState diveState_;

	enum TestState currentState_;
	enum TestState nextState_;
};

#endif /* TEST_STATE_MACHINE_H */
