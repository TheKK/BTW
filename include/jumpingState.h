/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: jumpingState.h
 */

#ifndef JUMPING_STATE_H
#define JUMPING_STATE_H

#include "state.h"
#include "gameActor.h"
#include "gameActorController.h"

#define JUMP_SPEED	-20
#define WALK_SPEED	10

class JumpingState : public State
{
public:
	~JumpingState() {};

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);

	void handleInput(GameActor& actor,
			 const GameActorController& contoller);
	void update(GameActor& actor);
private:
	int frame;
};

#endif /* JUMPING_STATE_H */
