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

#define WALK_SPEED	10

using namespace std;

class OnGroundState : public State
{
public:
	~OnGroundState() {};

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);

	void eventHandler(GameActor& actor, const SDL_Event& event);
	void update(GameActor& actor);
private:
	bool moveRight_;
	bool moveLeft_;
	bool dashRight_;

	Uint32 buttonLeftTimestamp;
	Uint32 buttonRightTimestamp;
};

#endif /* ON_GROUND_STATE_H */
