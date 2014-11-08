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
#include "gameActorController.h"

#define DIVE_DELAY	5

using namespace std;

class DiveState: public State
{
public:
	~DiveState() {};

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);

	void handleInput(GameActor& actor,
			 const GameActorController& controller);
	void update(GameActor& actor);
private:
	int delayFrame;
};

#endif /* DIVE_STATE_H */
