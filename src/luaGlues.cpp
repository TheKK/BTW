/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: luaGlues.cpp
 */

#include "luaGlues.h"

void
LuaGlues::register_gameActor(lua_State* L)
{
	SDL_assert(L != nullptr);

	/* Glues for class GameActor */
	lua_register(L, "moveRight", gameActor_moveRight);
	lua_register(L, "moveLeft", gameActor_moveLeft);
	lua_register(L, "jump", gameActor_jump);
	lua_register(L, "land", gameActor_land);
	lua_register(L, "isOnGround", gameActor_isOnGround);
	lua_register(L, "setVelY", gameActor_setVelY);
	lua_register(L, "setVelX", gameActor_setVelX);
	lua_register(L, "applyAcc", gameActor_applyAcc);
	lua_register(L, "setSprite", gameActor_setSprite);
	//lua_register(L, "normalAttack", gameActor_normalAttack);

	lua_newtable(L);
	lua_pushcfunction(L, gameActor_normalAttack);
	lua_setfield(L, 1, "normalAttack");
	lua_setglobal(L, "GameActor");

	add_enum_to_lua(L, "Sprites",
			"ON_GROUND", SPRITE_ON_GROUND,
			"JUMPING", SPRITE_JUMPING,
			"DIVE", SPRITE_DIVE,
			"NORMAL_ATTACK", SPRITE_NORMAL_ATTACK,
			0);
}

void
LuaGlues::register_gameActorController(lua_State* L)
{
	SDL_assert(L != nullptr);

	lua_register(L, "getButtonState", gameActorController_getButtonState);
	lua_register(L, "ifButtonPressed", gameActorController_ifButtonPressed);
	lua_register(L, "ifButtonReleased",
		     gameActorController_ifButtonReleased);

	add_enum_to_lua(L, "Buttons",
			"JUMP", BUTTON_JUMP,
			"NORMAL_ATTACK", BUTTON_NORMAL_ATTACK,
			"SPECIAL_ATTACK" ,BUTTON_SPECIAL_ATTACK,
			"EVADE", BUTTON_EVADE,
			"UP", BUTTON_UP,
			"DOWN", BUTTON_DOWN,
			"RIGHT", BUTTON_RIGHT,
			"LEFT", BUTTON_LEFT,
			0);
}

int
LuaGlues::gameActor_moveRight(lua_State* L)
{
	void* actorPtr = nullptr;

	/* Check number of arguments */
	if (lua_gettop(L) < 1)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 1)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	actorPtr = lua_touserdata(L, 1);

	((GameActor*) actorPtr)->moveRight();

	return 0;
}

int
LuaGlues::gameActor_moveLeft(lua_State* L)
{
	void* actorPtr = nullptr;

	/* Check number of arguments */
	if (lua_gettop(L) < 1)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 1)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	actorPtr = lua_touserdata(L, 1);

	((GameActor*) actorPtr)->moveLeft();

	return 0;
}

int
LuaGlues::gameActor_jump(lua_State* L)
{
	void* actorPtr = nullptr;

	/* Check number of arguments */
	if (lua_gettop(L) < 1)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 1)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	actorPtr = lua_touserdata(L, 1);

	((GameActor*) actorPtr)->jump();

	return 0;
}

int
LuaGlues::gameActor_land(lua_State* L)
{
	void* actorPtr = nullptr;

	/* Check number of arguments */
	if (lua_gettop(L) < 1)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 1)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	actorPtr = lua_touserdata(L, 1);

	((GameActor*) actorPtr)->land();

	return 0;
}

int
LuaGlues::gameActor_isOnGround(lua_State* L)
{
	void* actorPtr = nullptr;

	/* Check number of arguments */
	if (lua_gettop(L) < 1)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 1)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	actorPtr = lua_touserdata(L, 1);

	if (((GameActor*) actorPtr)->isOnGround())
		lua_pushboolean(L, 1);
	else
		lua_pushboolean(L, 0);

	return 1;
}

int
LuaGlues::gameActor_setVelX(lua_State* L)
{
	void* actorPtr = nullptr;
	int value;

	/* Check number of arguments */
	if (lua_gettop(L) < 2)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 2)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");
	if (!lua_isnumber(L, 2))
		return luaL_error(L, "Second argument is not number");

	actorPtr = lua_touserdata(L, 1);
	value = lua_tonumber(L, 2);

	((GameActor*) actorPtr)->setVelX(value);

	return 0;
}

int
LuaGlues::gameActor_setVelY(lua_State* L)
{
	void* actorPtr = nullptr;
	int value;

	/* Check number of arguments */
	if (lua_gettop(L) < 2)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 2)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");
	if (!lua_isnumber(L, 2))
		return luaL_error(L, "Second argument is not number");

	actorPtr = lua_touserdata(L, 1);
	value = lua_tonumber(L, 2);

	((GameActor*) actorPtr)->setVelY(value);

	return 0;
}

int
LuaGlues::gameActor_applyAcc(lua_State* L)
{
	void* actorPtr = nullptr;
	int dx, dy;

	/* Check number of arguments */
	if (lua_gettop(L) < 3)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 3)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");
	if (!lua_isnumber(L, 2))
		return luaL_error(L, "Second argument is not number");
	if (!lua_isnumber(L, 3))
		return luaL_error(L, "Third argument is not number");

	actorPtr = lua_touserdata(L, 1);
	dx = lua_tonumber(L, 2);
	dy = lua_tonumber(L, 3);

	((GameActor*) actorPtr)->applyAcc(dx, dy);

	return 0;
}

int
LuaGlues::gameActor_setSprite(lua_State* L)
{
	void* actorPtr = nullptr;
	enum ActorSprite sprite;

	/* Check number of arguments */
	if (lua_gettop(L) < 2)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 2)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	if (!check_enum_type(L, "Sprites", 2))
		return luaL_error(L, "Second argument is not enum Sprites");

	actorPtr = lua_touserdata(L, 1);
	sprite = (enum ActorSprite) get_enum_value(L, 2);

	((GameActor*) actorPtr)->setSprite(sprite);

	return 0;
}

int
LuaGlues::gameActor_dive(lua_State* L)
{
	return 0;
}

int
LuaGlues::gameActor_normalAttack(lua_State* L)
{
	void* actorPtr = nullptr;

	/* Check number of arguments */
	if (lua_gettop(L) < 1)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 1)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	actorPtr = lua_touserdata(L, 1);

	((GameActor*) actorPtr)->normalAttack();

	return 0;
}

int
LuaGlues::gameActor_normalAirAttack(lua_State* L)
{
	return 0;
}

int
LuaGlues::gameActorController_getButtonState(lua_State* L)
{
	void* controllerPtr = nullptr;
	enum Buttons button;

	/* Check number of arguments */
	if (lua_gettop(L) < 2)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 2)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	if (!check_enum_type(L, "Buttons", 2))
		return luaL_error(L, "Second argument is not enum Button");

	controllerPtr = lua_touserdata(L, 1);
	button = (enum Buttons) get_enum_value(L, 2);

	if(((GameActorController*) controllerPtr)->getButtonState(button))
		lua_pushboolean(L, 1);
	else
		lua_pushboolean(L, 0);

	return 1;
}

int
LuaGlues::gameActorController_ifButtonPressed(lua_State* L)
{
	void* controllerPtr = nullptr;
	enum Buttons button;

	/* Check number of arguments */
	if (lua_gettop(L) < 2)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 2)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	if (!check_enum_type(L, "Buttons", 2))
		return luaL_error(L, "Second argument is not enum Button");

	controllerPtr = lua_touserdata(L, 1);
	button = (enum Buttons) get_enum_value(L, 2);

	if(((GameActorController*) controllerPtr)->ifButtonPressed(button))
		lua_pushboolean(L, 1);
	else
		lua_pushboolean(L, 0);

	return 1;
}

int
LuaGlues::gameActorController_ifButtonReleased(lua_State* L)
{
	void* controllerPtr = nullptr;
	enum Buttons button;

	/* Check number of arguments */
	if (lua_gettop(L) < 2)
		return luaL_error(L, "Too few argument");
	else if (lua_gettop(L) > 2)
		return luaL_error(L, "Too much argument");

	/* Check type of argument */
	if (!lua_isuserdata(L, 1))
		return luaL_error(L, "First argument is not userdata");

	if (!check_enum_type(L, "Buttons", 2))
		return luaL_error(L, "Second argument is not enum Button");

	controllerPtr = lua_touserdata(L, 1);
	button = (enum Buttons) get_enum_value(L, 2);

	if(((GameActorController*) controllerPtr)->ifButtonReleased(button))
		lua_pushboolean(L, 1);
	else
		lua_pushboolean(L, 0);

	return 1;
}
