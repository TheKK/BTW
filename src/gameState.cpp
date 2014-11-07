/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameState.cpp
 */

#include "gameState.h"

GameState::GameState():
	next_(GAME_STATE_NULL)
{
}

GameState::~GameState()
{
}

bool
GameState::HasNext() const
{
	return (next_ != GAME_STATE_NULL);
}

enum GameStateList
GameState::Next() const
{
	return next_;
}

void
GameState::SetNext(enum GameStateList next)
{
	next_ = next;
}
