/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testStateMachine.cpp
 */

#include "testStateMachine.h"

TestStateMachine::TestStateMachine()
{
	onGroundState_.addDest("jumpingState", jumpingState_);

	jumpingState_.addDest("onGroundState", onGroundState_);

	currentState_ = &onGroundState_;
}

State*
TestStateMachine::currentState()
{
	return currentState_;
}

State*
TestStateMachine::next()
{
	return currentState_->next();
}

void
TestStateMachine::changeStateTo(State* where)
{
	currentState_ = where;
}
