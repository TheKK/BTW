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

	SDL_assert(stateList_.size() == ACTOR_STATE_COUNT);

	currentState_ = ACTOR_STATE_ON_GROUND;
	nextState_ = ACTOR_STATE_NULL;
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
	nextState_ = ACTOR_STATE_NULL;
}

void
TestStateMachine::setNext(enum ActorStates state)
{
	nextState_ = state;
};

bool
TestStateMachine::hasNext()
{
	return (nextState_ != ACTOR_STATE_NULL);
}
