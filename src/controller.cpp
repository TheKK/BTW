/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: controller.cpp
 */

#include "controller.h"

#include <jsoncpp/json/json.h>
#include <stdexcept>
#include <fstream>

#include "logLocator.h"

#define DEFAULT_SETTING_FILE	(char*) "./game/setting/controller.json"

#define GET_SETTING_FROM_JSON(json, button, defaultValue); \
	do { \
		buttonKeyMap_[button] = \
		SDL_GetScancodeFromName(json.get(#button, defaultValue) \
					.asCString()); \
	} while (0); \

#define SAVE_SETTING_TO_JSON(json, button); \
	do { \
		json[#button] = \
		SDL_GetScancodeName(buttonKeyMap_[button]); \
	} while (0); \

Controller::Controller()
{
	useDefaultSetting();
}

Controller::Controller(const char* filePath)
{
	/* Use file to config button map */
	settingFileName_ = filePath;
	if(!(readSettingFromFile(settingFileName_.c_str()))) {
		settingFileName_ = "";
		useDefaultSetting();
	}
}

Controller::~Controller()
{
	if (settingFileName_ != "")
		saveSettingToFile(settingFileName_.c_str());
}

void
Controller::eventHandler(const SDL_Event& event)
{
	enum Buttons whichButton;
	SDL_Scancode scancode;

	switch (event.type) {
	case SDL_KEYUP:
	case SDL_KEYDOWN:
		/* No repeat */
		if (event.key.repeat)
			return;

		scancode = event.key.keysym.scancode;

		if (scancode == buttonKeyMap_[BUTTON_UP])
			whichButton = BUTTON_UP;
		else if (scancode == buttonKeyMap_[BUTTON_DOWN])
			 whichButton = BUTTON_DOWN;
		else if (scancode == buttonKeyMap_[BUTTON_RIGHT])
			 whichButton = BUTTON_RIGHT;
		else if (scancode == buttonKeyMap_[BUTTON_LEFT])
			 whichButton = BUTTON_LEFT;
		else if (scancode == buttonKeyMap_[BUTTON_JUMP])
			 whichButton = BUTTON_JUMP;
		else if (scancode == buttonKeyMap_[BUTTON_EVADE])
			 whichButton = BUTTON_EVADE;
		else if (scancode == buttonKeyMap_[BUTTON_NORMAL_ATTACK])
			 whichButton = BUTTON_NORMAL_ATTACK;
		else if (scancode == buttonKeyMap_[BUTTON_SPECIAL_ATTACK])
			 whichButton = BUTTON_SPECIAL_ATTACK;
		else if (scancode == buttonKeyMap_[BUTTON_START])
			 whichButton = BUTTON_START;
		else if (scancode == buttonKeyMap_[BUTTON_SELECT])
			 whichButton = BUTTON_SELECT;

		if (event.key.state == SDL_PRESSED) {
			buttonPressed_[whichButton] = true;
			buttonHeld_[whichButton] = true;
		} else {
			buttonReleased_[whichButton] = true;
			buttonHeld_[whichButton] = false;
		}

		break;
	}
}

void
Controller::clearState()
{
	for (bool& e : buttonPressed_)
		e = false;

	for (bool& e : buttonReleased_)
		e = false;
}

bool
Controller::readSettingFromFile(const char* filePath)
{
	Json::Value root;
	Json::Reader reader;
	std::ifstream config;
	bool parseingSuccessful;
	std::string fullPath;

	/* Open file */
	fullPath = SDL_GetBasePath();
	fullPath += filePath;

	config.open(fullPath, std::ifstream::in);
	if (!config.is_open()) {
		LogLocator::GetService()->LogWarn(
			"[Controller] Setting file not found");
		return false;
	}

	/* Parse Json file */
	parseingSuccessful = reader.parse(config, root);
	config.close();
	if(!parseingSuccessful) {
		LogLocator::GetService()->LogWarn(
			"[Controller] Failed to parse json file: %s",
			reader.getFormattedErrorMessages().c_str());
		return false;
	}

	/* Get value */
	GET_SETTING_FROM_JSON(root, BUTTON_JUMP, "Z");
	GET_SETTING_FROM_JSON(root, BUTTON_NORMAL_ATTACK,"X");
	GET_SETTING_FROM_JSON(root, BUTTON_SPECIAL_ATTACK,"S");
	GET_SETTING_FROM_JSON(root, BUTTON_EVADE, "A");
	GET_SETTING_FROM_JSON(root, BUTTON_UP, "Up");
	GET_SETTING_FROM_JSON(root, BUTTON_DOWN, "Down");
	GET_SETTING_FROM_JSON(root, BUTTON_RIGHT, "Right");
	GET_SETTING_FROM_JSON(root, BUTTON_LEFT, "Left");
	GET_SETTING_FROM_JSON(root, BUTTON_START, "Return");
	GET_SETTING_FROM_JSON(root, BUTTON_SELECT, "Right Shift");

	LogLocator::GetService()->LogDebug(
		"[Controller] Setting read from %s successfully",
		filePath);

	return true;
}

bool
Controller::saveSettingToFile(const char* filePath)
{
	Json::Value root;
	Json::StyledStreamWriter writer;
	std::string str;
	std::ofstream output;

	/* Create file */
	output.open(filePath, std::ofstream::out);
	if (!output.is_open()) {
		LogLocator::GetService()->LogWarn(
			"[Controller] Can not write setting to file");

		return false;
	}

	/* Store current setting */
	SAVE_SETTING_TO_JSON(root, BUTTON_JUMP);
	SAVE_SETTING_TO_JSON(root, BUTTON_NORMAL_ATTACK);
	SAVE_SETTING_TO_JSON(root, BUTTON_SPECIAL_ATTACK);
	SAVE_SETTING_TO_JSON(root, BUTTON_EVADE);
	SAVE_SETTING_TO_JSON(root, BUTTON_UP);
	SAVE_SETTING_TO_JSON(root, BUTTON_DOWN);
	SAVE_SETTING_TO_JSON(root, BUTTON_RIGHT);
	SAVE_SETTING_TO_JSON(root, BUTTON_LEFT);
	SAVE_SETTING_TO_JSON(root, BUTTON_START);
	SAVE_SETTING_TO_JSON(root, BUTTON_SELECT);

	writer.write(output, root);

	output.close();

	LogLocator::GetService()->LogDebug(
		"[Controller] Setting write to %s successfully",
		filePath);

	return true;
}

void
Controller::useDefaultSetting()
{
	LogLocator::GetService()->LogDebug(
		"[Controller] Use default mapping");

	buttonKeyMap_[BUTTON_JUMP] = 		SDL_SCANCODE_Z;
	buttonKeyMap_[BUTTON_NORMAL_ATTACK] = 	SDL_SCANCODE_X;
	buttonKeyMap_[BUTTON_SPECIAL_ATTACK] = 	SDL_SCANCODE_S;
	buttonKeyMap_[BUTTON_EVADE] = 		SDL_SCANCODE_A;

	buttonKeyMap_[BUTTON_UP] = 		SDL_SCANCODE_UP;
	buttonKeyMap_[BUTTON_DOWN] = 		SDL_SCANCODE_DOWN;
	buttonKeyMap_[BUTTON_RIGHT] = 		SDL_SCANCODE_RIGHT;
	buttonKeyMap_[BUTTON_LEFT] = 		SDL_SCANCODE_LEFT;

	buttonKeyMap_[BUTTON_START] = 		SDL_SCANCODE_RETURN;
	buttonKeyMap_[BUTTON_SELECT] = 		SDL_SCANCODE_RSHIFT;
}

bool
Controller::ifButtonHeld(enum Buttons which) const
{
	return buttonHeld_[which];
}

bool
Controller::ifButtonPressed(enum Buttons which) const
{
	return buttonPressed_[which];
}

bool
Controller::ifButtonReleased(enum Buttons which) const
{
	return buttonReleased_[which];
}
