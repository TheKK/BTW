/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: gameActorController.h
 */

#ifndef GAME_ACTOR_CONTROLLER_H
#define GAME_ACTOR_CONTROLLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <lua.hpp>
#include <SDL.h>
#include <jsoncpp/json/json.h>

#include "logLocator.h"
#include "lua_typed_enums.h"

#define DEFAULT_SETTING_FILE	(char*) "./game/setting/controller.json"

#define GET_SETTING_FROM_JSON(json, button, defaultValue); \
	do { \
		buttonKeyMap_[button] = \
		SDL_GetScancodeFromName(json.get(#button, defaultValue) \
					.asCString()); \
	} while (0); \

#define SAVE_SETTING_TO_JSON(json, button); \
	do { \
		root[#button] = \
		SDL_GetScancodeName(buttonKeyMap_[button]); \
	} while (0); \

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

class GameActor;

class GameActorController
{
public:
	GameActorController();
	GameActorController(const char* filePath);
	~GameActorController();

	void eventHandler(const SDL_Event& event);
	void update();

	bool readSettingFromFile(const char* filePath);
	bool saveSettingToFile(const char* filePath);
	void useDefaultSetting();
	void setButtonKey(enum Buttons button, SDL_Scancode key);

	bool getButtonState(enum Buttons which) const;
	bool ifButtonPressed(enum Buttons which) const;
	bool ifButtonReleased(enum Buttons which) const;

	/* For Lua use */
	static void lua_registerEverything(lua_State* L);
	static int lua_getButtonState(lua_State* L);
	static int lua_ifButtonPressed(lua_State* L);
	static int lua_ifButtonReleased(lua_State* L);
private:
	bool buttonPressed_[BUTTON_COUNT] = {false};
	bool buttonReleased_[BUTTON_COUNT] = {false};
	const Uint8* keyState_;

	string settingFileName_;

	SDL_Scancode buttonKeyMap_[BUTTON_COUNT] = {SDL_SCANCODE_UNKNOWN};
};

#endif /* GAME_ACTOR_CONTROLLER_H */
