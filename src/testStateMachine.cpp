/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: testStateMachine.cpp
 */

#include "testStateMachine.h"

TestStateMachine::TestStateMachine():
	states_(nullptr),
	currentStateName_("")
{
	string fullPath;

	states_ = luaL_newstate();
	if (states_ == nullptr) {
		LogLocator::GetService()->LogCritical(
			"[TestStateMachine]"
			"No enough memory to create Lua state");
		throw runtime_error("Critical error, program shutdown");
	}

	luaL_openlibs(states_);

	fullPath = SDL_GetBasePath();
	fullPath += "./game/scripts/character/Zup/states.lua";
	if (luaL_dofile(states_, fullPath.c_str()) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[TestStateMachine] Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
		throw runtime_error("Lua script error, program shutdown");
	}

	GameActor::lua_registerEverything(states_);
	GameActorController::lua_registerEverything(states_);

	/* Init machine state */
	setNext(ACTOR_STATE_ON_GROUND);
	toNext();
}

TestStateMachine::~TestStateMachine()
{
	if (states_)
		lua_close(states_);
	states_ = nullptr;
}

void
TestStateMachine::onEnter(GameActor& actor)
{
	lua_pushstring(states_, (char*) "onEnter");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, (void*) &actor);
	if (lua_pcall(states_, 1, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[TestStateMachine] onEnter: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
	}
}

void
TestStateMachine::onExit(GameActor& actor)
{
	lua_pushstring(states_, (char*) "onExit");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, (void*) &actor);
	if (lua_pcall(states_, 1, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[TestStateMachine] onExit: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
	}
}

void
TestStateMachine::handleInput(GameActor& actor,
			      const GameActorController& controller)
{
	lua_pushstring(states_, (char*) "handleInput");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, (void*) &actor);
	lua_pushlightuserdata(states_, (void*) &controller);
	if (lua_pcall(states_, 2, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[TestStateMachine] handleInput: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
	}
}

void
TestStateMachine::update(GameActor& actor)
{
	lua_pushstring(states_, (char*) "update");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, &actor);
	if (lua_pcall(states_, 1, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[TestStateMachine] update: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
	}
}

void
TestStateMachine::toNext()
{
	currentState_ = nextState_;
	nextState_ = ACTOR_STATE_NULL;

	/* Lua stuffs */
	switch (currentState_) {
	case ACTOR_STATE_ON_GROUND:
		currentStateName_ = "onGround";
		break;
	case ACTOR_STATE_JUMPING:
		currentStateName_ = "jumping";
		break;
	case ACTOR_STATE_DIVE:
		currentStateName_ = "dive";
		break;
	case ACTOR_STATE_NORMAL_ATTACK:
		currentStateName_ = "normalAttack";
		break;
	case ACTOR_STATE_NORMAL_AIR_ATTACK:
		currentStateName_ = "normalAirAttack";
		break;
	default:
		LogLocator::GetService()->LogError(
			"[TestStateMachine] Program should not get here");
		throw runtime_error("Boo");
		break;
	}

	/* Make sure nothing go wrong */
	if (lua_gettop(states_) > 1)
		LogLocator::GetService()->LogWarn(
			"[TestStateMachine] Lua stack height is not 1");
	/* Pop old table */
	lua_pop(states_, lua_gettop(states_));

	/* Get new table */
	lua_getglobal(states_, currentStateName_.c_str());
	/* You are not exist */
	if (lua_isnil(states_, -1)) {
		LogLocator::GetService()->LogCritical(
			"[TestStateMachine] Global varialbe \"%s\" not exist",
			currentStateName_.c_str());
		throw runtime_error("Critical error, program shutdown");

	/* You are not table */
	} else if (!lua_istable(states_, -1)) {
		LogLocator::GetService()->LogCritical(
			"[TestStateMachine] Global varialbe \"%s\" not exist",
			currentStateName_.c_str());
		throw runtime_error("Critical error, program shutdown");
	}
}

void
TestStateMachine::setNext(enum ActorStates state)
{
	nextState_ = state;
};

bool
TestStateMachine::hasNext()
{
	return (nextState_ != ACTOR_STATE_NULL);
}
