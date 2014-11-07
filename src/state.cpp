/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: state.cpp
 */

#include "state.h"

void
State::addDest(const char* name, State& dest)
{
	destList_.insert(pair<string, State*>(name, &dest));
}

bool
State::setNext(const char* name)
{
	map<string, State*>::iterator it;

	/* Reset nextState_ */
	if (name == nullptr) {
		nextState_ = nullptr;
		return true;
	}

	it = destList_.find(name);
	if (it == destList_.end())
		return false;
	else {
		nextState_ = destList_[name];
		return true;
	}
}

State*
State::next()
{
	return nextState_;
}
