/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: jumpingState.h
 */

#ifndef JUMPING_STATE_H
#define JUMPING_STATE_H

#include <iostream>
#include <SDL.h>

#include "state.h"
#include "gameActor.h"

#include "onGroundState.h"

#define JUMP_SPEED	-20
#define WALK_SPEED	5

using namespace std;

class JumpingState : public State
{
public:
	~JumpingState() {};

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);

	void eventHandler(GameActor& actor, const SDL_Event& event);
	void update(GameActor& actor);
private:
	int frame;
};

#endif /* STANDING_STATE_H */
