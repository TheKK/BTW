/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testStateMachine.h
 */

#ifndef TEST_STATE_MACHINE_H
#define TEST_STATE_MACHINE_H

#include <iostream>
#include <set>
#include <SDL.h>

#include "stateMachine.h"
#include "onGroundState.h"
#include "jumpingState.h"

using namespace std;

class TestStateMachine
{
public:
	TestStateMachine();
	~TestStateMachine() {};

	State* currentState();
	State* next();

	void changeStateTo(State* where);
private:
	State* currentState_;
	OnGroundState onGroundState_;
	JumpingState jumpingState_;;
};

#endif /* TEST_STATE_MACHINE_H */
