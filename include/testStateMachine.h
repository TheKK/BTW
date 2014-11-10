/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testStateMachine.h
 */

#ifndef TEST_STATE_MACHINE_H
#define TEST_STATE_MACHINE_H

#include <iostream>
#include <vector>
#include <SDL.h>

#include "stateMachine.h"
#include "gameActor.h"
#include "gameActorController.h"
#include "logLocator.h"

//#include "onGroundState.h"
//#include "jumpingState.h"
//#include "diveState.h"
//#include "normalAttackState.h"
//#include "normalAirAttackState.h"

using namespace std;

enum ActorStates
{
	ACTOR_STATE_ON_GROUND = 0x00,
	ACTOR_STATE_JUMPING,
	ACTOR_STATE_DIVE,
	ACTOR_STATE_NORMAL_ATTACK,
	ACTOR_STATE_NORMAL_AIR_ATTACK,

	ACTOR_STATE_COUNT,

	ACTOR_STATE_NULL
};

class TestStateMachine
{
public:
	TestStateMachine();
	~TestStateMachine();

	//void bindState(enum ActorStates which, State* state);

	void onEnter(GameActor& actor);
	void onExit(GameActor& actor);
	void handleInput(GameActor& actor,
			 const GameActorController& controller);
	void update(GameActor& actor);

	void setNext(enum ActorStates state);
	bool hasNext();
	void toNext();
private:
	//vector<State*> stateList_;
	//OnGroundState onGroundState_;
	//JumpingState jumpingState_;;
	//DiveState diveState_;
	//NormalAttackState normalAttack_;
	//NormalAirAttackState normalAirAttack_;

	lua_State* states_;

	string currentStateName_;

	enum ActorStates currentState_;
	enum ActorStates nextState_;
};

#endif /* TEST_STATE_MACHINE_H */
