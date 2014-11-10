/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActor.cpp
 */

#include "gameActor.h"

GameActor::~GameActor()
{
	for (auto e : bulletList_)
		delete e;

	bulletList_.clear();
}

void
GameActor::lua_registerEverything(lua_State* L)
{
	SDL_assert(L != nullptr);

	lua_register(L, "moveRight", lua_moveRight);
	lua_register(L, "moveLeft", lua_moveLeft);
	lua_register(L, "jump", lua_jump);
	lua_register(L, "land", lua_land);
	lua_register(L, "isOnGround", lua_isOnGround);
	lua_register(L, "setVelY", lua_setVelY);
	lua_register(L, "setVelX", lua_setVelX);
	lua_register(L, "applyAcc", lua_applyAcc);
}

int
GameActor::lua_moveRight(lua_State* L)
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
GameActor::lua_moveLeft(lua_State* L)
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
GameActor::lua_jump(lua_State* L)
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
GameActor::lua_land(lua_State* L)
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
GameActor::lua_isOnGround(lua_State* L)
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
GameActor::lua_setVelX(lua_State* L)
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
GameActor::lua_setVelY(lua_State* L)
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
GameActor::lua_applyAcc(lua_State* L)
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
GameActor::lua_dive(lua_State* L)
{
	return 0;
}

int
GameActor::lua_normalAttack(lua_State* L)
{
	return 0;
}

int
GameActor::lua_normalAirAttack(lua_State* L)
{
	return 0;
}


void
GameActor::addBullet(Bullet* bullet)
{
	bulletList_.push_back(bullet);
}

void
GameActor::updateBullet(GameActor& target)
{
	for (auto it = bulletList_.rbegin(); it != bulletList_.rend(); it++) {
		(*it)->update(target);

		if ((*it)->isDead()) {
			delete (*it);
			bulletList_.erase(next(it).base());
		}
	}
}

void
GameActor::renderBullet()
{
	for (const auto it : bulletList_)
		it->render();
}

void
GameActor::applyAcc(int accX, int accY)
{
	velX_ += accX;
	velY_ += accY;
}

void
GameActor::setVelX(int n)
{
	velX_ = n;
}

void
GameActor::setVelY(int n)
{
	velY_ = n;
}

void
GameActor::setAsInvisible()
{
	isInvisible_ = true;
}

void
GameActor::setAsVisible()
{
	isInvisible_ = false;
}

bool
GameActor::isInvisible()
{
	return isInvisible_;
}

void
GameActor::setGravity(int g)
{
	gravity_ = g;
}

void
GameActor::setHorizon(int h)
{
	horizon_ = h;
}

int
GameActor::getGravity()
{
	return gravity_;
}

int
GameActor::getHorizon()
{
	return horizon_;
}

bool
GameActor::isOnGround()
{
	return (posRect_.y + posRect_.h >= horizon_);
}

enum ActorDirection
GameActor::direction()
{
	return direction_;
}

void
GameActor::moveBy(int dx, int dy)
{
	posRect_.x += dx;
	posRect_.y += dy;

	if (posRect_.y + posRect_.h > horizon_)
		posRect_.y = horizon_ - posRect_.h;
}

void
GameActor::moveTo(int x, int y)
{
	posRect_.x = x;
	posRect_.y = y;
}

void
GameActor::moveXto(int n)
{
	posRect_.x = n;
}

void
GameActor::moveYto(int n)
{
	posRect_.y = n;
}

void
GameActor::setW(int n)
{
	posRect_.w = n;
}

void
GameActor::setH(int n)
{
	posRect_.h = n;
}

int
GameActor::x() const
{
	return posRect_.x;
}

int
GameActor::y() const
{
	return posRect_.y;
}

int
GameActor::w() const
{
	return posRect_.w;
}

int
GameActor::h() const
{
	return posRect_.h;
}

SDL_Rect*
GameActor::rect()
{
	return &posRect_;
}
