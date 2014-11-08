/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorController.h
 */

#ifndef GAME_ACTOR_CONTROLLER_H
#define GAME_ACTOR_CONTROLLER_H

#include <iostream>
#include <SDL.h>

#include "gameActor.h"

using namespace std;

enum Buttons
{
	BUTTON_JUMP = 0x00,
	BUTTON_NORMAL_ATTACK,
	BUTTON_SPECIAL_ATTACK,
	BUTTON_EVADE,

	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_RIGHT,
	BUTTON_LEFT,

	BUTTON_COUNT
};

enum Commands
{
	COMMAND_JUMP = 0x00,
	COMMAND_DIVE,
	COMMAND_NORMAL_ATTACK,
	COMMAND_NORMAL_AIR_ATTACK,

	COMMAND_COUNT,

	COMMAND_NULL
};

class GameActor;

class GameActorController
{
public:
	GameActorController();
	~GameActorController();

	void eventHandler(const SDL_Event& event);
	void update();

	void execute(GameActor& actor);

	void setButtonFunction(enum Buttons button, enum Commands command);
	void setButtonKey(enum Buttons button, SDL_Keycode key);
	bool getButtonState(enum Buttons which) const;
	bool ifButtonPressed(enum Buttons which) const;
private:
	bool buttonPressed_[BUTTON_COUNT] = {false};
	bool buttonReleased_[BUTTON_COUNT] = {false};
	const Uint8* keyState_;

	enum Commands buttonCommandMap_[BUTTON_COUNT] = {COMMAND_NULL};
	SDL_Keycode buttonKeyMap_[BUTTON_COUNT] = {0};
};

#endif /* GAME_ACTOR_CONTROLLER_H */
