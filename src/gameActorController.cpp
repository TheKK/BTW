/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorController.cpp
 */

#include "gameActorController.h"

GameActorController::GameActorController():
	keyState_(SDL_GetKeyboardState(nullptr))
{
	/* Use file to config button map */
	if(!(readSettingFromFile((char*) "./game/setting/controller.json")))
		useDefaultSetting();
}

GameActorController::~GameActorController()
{
}

void
GameActorController::eventHandler(const SDL_Event& event)
{
	enum Buttons whichButton;
	SDL_Scancode scancode;

	switch (event.type) {
	case SDL_KEYUP:
	case SDL_KEYDOWN:
		/* No repeat fire */
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

		if (event.key.state == SDL_PRESSED) {
			buttonPressed_[whichButton] = true;
			buttonReleased_[whichButton] = false;
		} else {
			buttonPressed_[whichButton] = false;
			buttonReleased_[whichButton] = true;
		}
		break;
	}
}

void
GameActorController::update()
{
	for (bool& e : buttonPressed_)
		e = false;

	for (bool& e : buttonReleased_)
		e = false;
}

bool
GameActorController::readSettingFromFile(char* filePath)
{
	Json::Value root;
	Json::Reader reader;
	ifstream config;
	bool parseingSuccessful;

	/* Open file */
	config.open(filePath, ifstream::in);
	if (!config.is_open()) {
		LogLocator::GetService()->LogWarn(
			"Controller setting file not found");
		return false;
	}

	/* Parse Json file */
	parseingSuccessful = reader.parse(config, root);
	config.close();
	if(!parseingSuccessful) {
		LogLocator::GetService()->LogWarn(
			"Failed to parse json file: %s",
			reader.getFormattedErrorMessages().c_str());
		return false;
	}

	/* Get value */
	/* FIXME Tooooooooo long!! */
	buttonKeyMap_[BUTTON_JUMP] = SDL_GetScancodeFromName(root.get("BUTTON_JUMP", "Z").asCString());
	buttonKeyMap_[BUTTON_NORMAL_ATTACK] = SDL_GetScancodeFromName(root.get("BUTTON_NORMAL_ATTACK", "X").asCString());
	buttonKeyMap_[BUTTON_SPECIAL_ATTACK] = SDL_GetScancodeFromName(root.get("BUTTON_SPECIAL_ATTACK", "S").asCString());
	buttonKeyMap_[BUTTON_EVADE] = SDL_GetScancodeFromName(root.get("BUTTON_EVADE", "A").asCString());

	buttonKeyMap_[BUTTON_UP] = SDL_GetScancodeFromName(root.get("BUTTON_UP", "Up").asCString());
	buttonKeyMap_[BUTTON_DOWN] = SDL_GetScancodeFromName(root.get("BUTTON_DOWN", "Down").asCString());
	buttonKeyMap_[BUTTON_RIGHT] = SDL_GetScancodeFromName(root.get("BUTTON_RIGHT", "Right").asCString());
	buttonKeyMap_[BUTTON_LEFT] = SDL_GetScancodeFromName(root.get("BUTTON_LEFT", "Left").asCString());

	return true;
}

void
GameActorController::saveSettingToFile(char* filePath)
{
}

void
GameActorController::useDefaultSetting()
{
	LogLocator::GetService()->LogInfo("Controller use default mapping");
	buttonKeyMap_[BUTTON_JUMP] = 		SDL_SCANCODE_Z;
	buttonKeyMap_[BUTTON_NORMAL_ATTACK] = 	SDL_SCANCODE_X;
	buttonKeyMap_[BUTTON_SPECIAL_ATTACK] = 	SDL_SCANCODE_S;
	buttonKeyMap_[BUTTON_EVADE] = 		SDL_SCANCODE_A;

	buttonKeyMap_[BUTTON_UP] = 		SDL_SCANCODE_UP;
	buttonKeyMap_[BUTTON_DOWN] = 		SDL_SCANCODE_DOWN;
	buttonKeyMap_[BUTTON_RIGHT] = 		SDL_SCANCODE_RIGHT;
	buttonKeyMap_[BUTTON_LEFT] = 		SDL_SCANCODE_LEFT;
}

bool
GameActorController::getButtonState(enum Buttons which) const
{
	return keyState_[buttonKeyMap_[which]];
}

bool
GameActorController::ifButtonPressed(enum Buttons which) const
{
	return buttonPressed_[which];
}

bool
GameActorController::ifButtonReleased(enum Buttons which) const
{
	return buttonReleased_[which];
}
