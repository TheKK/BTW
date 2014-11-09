/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorController.h
 */

#ifndef GAME_ACTOR_CONTROLLER_H
#define GAME_ACTOR_CONTROLLER_H

#include <iostream>
#include <fstream>
#include <SDL.h>
#include <jsoncpp/json/json.h>

#include "logLocator.h"

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

	bool readSettingFromFile(char* filePath);
	void saveSettingToFile(char* filePath);
	void useDefaultSetting();
	void setButtonKey(enum Buttons button, SDL_Scancode key);

	bool getButtonState(enum Buttons which) const;
	bool ifButtonPressed(enum Buttons which) const;
	bool ifButtonReleased(enum Buttons which) const;
private:
	bool buttonPressed_[BUTTON_COUNT] = {false};
	bool buttonReleased_[BUTTON_COUNT] = {false};
	const Uint8* keyState_;

	SDL_Scancode buttonKeyMap_[BUTTON_COUNT] = {SDL_SCANCODE_UNKNOWN};
};

#endif /* GAME_ACTOR_CONTROLLER_H */
