/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameState.h
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SDL2/SDL.h>

enum GameStateList
{
	GAME_STATE_NULL = 0x00,

	GAME_STATE_INTRO,
	GAME_STATE_MAIN,

	GAME_STATE_QUIT
};

class GameState
{
	public:
		GameState();
		virtual ~GameState();

		virtual void EventHandler(const SDL_Event& event) = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		bool HasNext() const;
		enum GameStateList Next() const;
	protected:
		void SetNext(enum GameStateList next);
	private:
		enum GameStateList next_ = GAME_STATE_NULL;
};

#endif	/* GAME_STATE_H */
