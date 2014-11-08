/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: state.h
 */

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <map>
#include <SDL.h>

#include "gameActor.h"

using namespace std;

class State
{
public:
	virtual ~State() {};

	virtual void onEnter(GameActor& actor) = 0;
	virtual void onExit(GameActor& actor) = 0;

	virtual void eventHandler(GameActor& actor,
				  const SDL_Event& event) = 0;
	virtual void update(GameActor& actor) = 0;
};

#endif /* STATE_H */
