/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: luaStateMachine.cpp
 */

#include "luaStateMachine.h"

LuaStateMachine::LuaStateMachine(const char* filePath):
	states_(nullptr),
	currentState_(""),
	nextState_("")
{
	string fullPath;

	/* Lua routine */
	states_ = luaL_newstate();
	if (states_ == nullptr) {
		LogLocator::GetService()->LogCritical(
			"[LuaStateMachine]"
			"No enough memory to create Lua state");
		throw runtime_error("Critical error, program shutdown");
	}

	luaL_openlibs(states_);

	/* Load character states */
	fullPath = SDL_GetBasePath();
	fullPath += filePath;
	if (luaL_dofile(states_, fullPath.c_str()) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[LuaStateMachine] Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
		throw runtime_error("Lua script error, program shutdown");
	}

	/* Register needed functions */
	GameActor::lua_registerEverything(states_);
	GameActorController::lua_registerEverything(states_);

	lua_newtable(states_);
	lua_pushcfunction(states_, lua_setNext);
	lua_setfield(states_, 1, "setNext");
	lua_setglobal(states_, "StateMachine");
	/* lua_register(states_, "changeStateTo", lua_setNext); */

	/* Set 'this' address as Lua global variable */
	lua_pushlightuserdata(states_, this);
	lua_setglobal(states_, "FSM");

	/* Init machine state */
	setNext((char*) "onGround");
	toNext();
}

LuaStateMachine::~LuaStateMachine()
{
	if (states_)
		lua_close(states_);
	states_ = nullptr;
}

void
LuaStateMachine::onEnter(GameActor& actor)
{
	lua_pushstring(states_, (char*) "onEnter");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, (void*) &actor);
	if (lua_pcall(states_, 1, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[LuaStateMachine] onEnter: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
		throw runtime_error("Lua error, program shutdown");
	}
}

void
LuaStateMachine::onExit(GameActor& actor)
{
	lua_pushstring(states_, (char*) "onExit");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, (void*) &actor);
	if (lua_pcall(states_, 1, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[LuaStateMachine] onExit: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
		throw runtime_error("Lua error, program shutdown");
	}
}

void
LuaStateMachine::handleInput(GameActor& actor,
			      const GameActorController& controller)
{
	lua_pushstring(states_, (char*) "handleInput");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, (void*) &actor);
	lua_pushlightuserdata(states_, (void*) &controller);
	if (lua_pcall(states_, 2, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[LuaStateMachine] handleInput: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
		throw runtime_error("Lua error, program shutdown");
	}
}

void
LuaStateMachine::update(GameActor& actor)
{
	lua_pushstring(states_, (char*) "update");
	lua_gettable(states_, -2);

	/* Push argument */
	lua_pushlightuserdata(states_, &actor);
	if (lua_pcall(states_, 1, 0, 0) != LUA_OK) {
		LogLocator::GetService()->LogError(
			"[LuaStateMachine] update: Lua error %s",
			lua_tostring(states_, -1));
		lua_pop(states_, 1);
		throw runtime_error("Lua error, program shutdown");
	}

	/* See if need to change to new state */
	if (hasNext()) {
		onExit(actor);
		toNext();
		onEnter(actor);
	}
}

void
LuaStateMachine::toNext()
{
	SDL_assert(nextState_ != "");

	currentState_ = nextState_;
	nextState_ = "";

	/* Make sure nothing go wrong and pop them all */
	if (lua_gettop(states_) > 1)
		LogLocator::GetService()->LogWarn(
			"[LuaStateMachine] Lua stack height is not 1");
	lua_pop(states_, lua_gettop(states_));

	/* Get new table and check error */
	lua_getglobal(states_, currentState_.c_str());
	if (lua_isnil(states_, -1)) {
		LogLocator::GetService()->LogCritical(
			"[LuaStateMachine] State \"%s\" does not exist",
			currentState_.c_str());
		throw runtime_error("Critical error, program shutdown");

	} else if (!lua_istable(states_, -1)) {
		LogLocator::GetService()->LogCritical(
			"[LuaStateMachine] State \"%s\" is not a table",
			currentState_.c_str());
		throw runtime_error("Critical error, program shutdown");
	}
}

void
LuaStateMachine::setNext(char* state)
{
	nextState_ = state;
};

bool
LuaStateMachine::hasNext()
{
	return (nextState_ != "");
}

int
LuaStateMachine::lua_setNext(lua_State* L)
{
	void* LuaStateMachinePtr = nullptr;
	char* nextState = nullptr;

	/* Check number of argument(s) */
	if (lua_gettop(L) < 2)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 2)
		return luaL_error(L, "Too much argument");

	/* Check argument type */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");
	if (!lua_isstring(L, 2))
		return luaL_error(L, "Second argument is not string");

	LuaStateMachinePtr = (void*) lua_topointer(L, 1);
	nextState = (char*) lua_tostring(L, 2);

	((LuaStateMachine*) LuaStateMachinePtr)->setNext(nextState);

	return 0;
}
