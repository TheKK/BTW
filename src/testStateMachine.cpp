/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testStateMachine.cpp
 */

#include "testStateMachine.h"

TestStateMachine::TestStateMachine()
{
	stateList_.push_back((State*) &onGroundState_);
	stateList_.push_back((State*) &jumpingState_);
	stateList_.push_back((State*) &diveState_);
	stateList_.push_back((State*) &normalAttack_);
	stateList_.push_back((State*) &normalAirAttack_);

	SDL_assert(stateList_.size() == TEST_STATE_COUNT);

	currentState_ = TEST_STATE_ON_GROUND;
	nextState_ = TEST_STATE_NULL;
}

State*
TestStateMachine::currentState()
{
	return stateList_[currentState_];
}

void
TestStateMachine::toNext()
{
	currentState_ = nextState_;
	nextState_ = TEST_STATE_NULL;
}

void
TestStateMachine::setNext(enum TestState state)
{
	nextState_ = state;
};

bool
TestStateMachine::hasNext()
{
	return (nextState_ != TEST_STATE_NULL);
}
