/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: luaStateMachine.h
 */

#ifndef LUA_STATE_MACHINE_H
#define LUA_STATE_MACHINE_H

#include <string>

#include "stateMachine.h"

struct lua_State;
class GameActor;
class Controller;

class LuaStateMachine : public StateMachine
{
public:
	LuaStateMachine();
	LuaStateMachine(const char* filePath);
	~LuaStateMachine();

	void init(const char* filePath);

	void bindActor(const GameActor& actor);
	void bindController(const Controller& controller);

	void onEnter();
	void onExit();
	void handleInput();
	void update();

	void setNext(char* nextState);
	bool hasNext();
	void toNext();

	/* For Lua use */
	static int lua_setNext(lua_State* L);
private:
	lua_State* states_ = nullptr;

	std::string currentState_ = "";
	std::string nextState_ = "";

	/* XXX Do I really need these? */
	void createNewLuaState_();
	void loadSettingScript_(const char* filePath);
};

#endif /* LUA_STATE_MACHINE_H */
