/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: controller.h
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <SDL.h>
#include <jsoncpp/json/json.h>

#include "logLocator.h"

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

	BUTTON_START,
	BUTTON_SELECT,

	BUTTON_COUNT
};

class Controller
{
public:
	Controller();
	Controller(const char* filePath);
	~Controller();

	void eventHandler(const SDL_Event& event);
	void clearState();

	bool readSettingFromFile(const char* filePath);
	bool saveSettingToFile(const char* filePath);
	void useDefaultSetting();
	void setButtonKey(enum Buttons button, SDL_Scancode key);

	bool ifButtonHeld(enum Buttons which) const;
	bool ifButtonPressed(enum Buttons which) const;
	bool ifButtonReleased(enum Buttons which) const;
private:
	bool buttonPressed_[BUTTON_COUNT] = {false};
	bool buttonReleased_[BUTTON_COUNT] = {false};
	bool buttonHeld_[BUTTON_COUNT] = {false};

	SDL_Scancode buttonKeyMap_[BUTTON_COUNT] = {SDL_SCANCODE_UNKNOWN};

	std::string settingFileName_ = "";
};

#endif /* CONTROLLER_H */
