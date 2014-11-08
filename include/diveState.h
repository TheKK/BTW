/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: diveState.h
 */

#ifndef DIVE_STATE_H
#define DIVE_STATE_H

#include <iostream>
#include <SDL.h>

#include "state.h"
#include "gameActor.h"

#define DIVE_DELAY	8

using namespace std;

class DiveState: public State
{
public:
	~DiveState() {};

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);

	void eventHandler(GameActor& actor, const SDL_Event& event);
	void update(GameActor& actor);
private:
	int delayFrame;
};

#endif /* DIVE_STATE_H */
