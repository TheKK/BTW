/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: onGroundState.h
 */

#ifndef ON_GROUND_STATE_H
#define ON_GROUND_STATE_H

#include <iostream>
#include <SDL.h>

#include "state.h"
#include "gameActor.h"

#include "jumpingState.h"

#define WALK_SPEED	5

using namespace std;

class OnGroundState : public State
{
public:
	~OnGroundState() {};

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);

	void eventHandler(GameActor& actor, const SDL_Event& event);
	void update(GameActor& actor);
};

#endif /* ON_GROUND_STATE_H */
