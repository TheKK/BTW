/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: stateMachine.h
 */

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <iostream>
#include <SDL.h>

#include "state.h"

using namespace std;

class StateMachine
{
public:
	virtual ~StateMachine() {};
};

#endif /* STATE_MACHINE_H */
