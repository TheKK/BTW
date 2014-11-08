/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorController.h
 */

#ifndef GAME_ACTOR_CONTROLLER_H
#define GAME_ACTOR_CONTROLLER_H

#include <iostream>
#include <SDL.h>

using namespace std;

enum Buttons
{
	BUTTON_JUMP = 0x00,
	BUTTON_NORMAL_ATTACK,
	BUTTON_SPECIAL_ATTACK,
	BUTTON_EVADE,

	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,

	BUTTON_COUNT
};

class GameActorController
{
public:
	GameActorController();
	~GameActorController();

	void eventHandler(const SDL_Event& event);

	bool getButtonState_(enum Buttons which) const;
private:
	bool buttonState_[BUTTON_COUNT] = {false};
	const Uint8* keyState_;
};

#endif /* GAME_ACTOR_CONTROLLER_H */
