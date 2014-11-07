/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: main.cpp
 */

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gameState.h"
#include "logLocator.h"
#include "sdlLog.h"
#include "soundEngine.h"
#include "timer.h"
#include "userEvent.h"
#include "window.h"

#include "testGameActor.h"

#ifndef SDL_ASSERT_LEVEL
	#define SDL_ASSERT_LEVEL	3
#else
	#undef SDL_ASSERT_LEVEL
	#define SDL_ASSERT_LEVEL	3
#endif

#define GAME_FPS	60

using namespace std;

void PrintVersionInfo()
{
	SDL_version compiled;
	SDL_version linked;

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);

	LogLocator::GetService()->LogInfo(
		"compiled against SDL version %d.%d.%d.\n",
		compiled.major, compiled.minor, compiled.patch);

	LogLocator::GetService()->LogInfo(
		"Linked against SDL version %d.%d.%d.\n",
		linked.major, linked.minor, linked.patch);

	LogLocator::GetService()->LogInfo(
		"SDL_image linked version %d.%d.%d\n",
		IMG_Linked_Version()->major,
		IMG_Linked_Version()->minor,
		IMG_Linked_Version()->patch
	);

	LogLocator::GetService()->LogInfo(
		"SDL_ttf linked version %d.%d.%d.\n",
		TTF_Linked_Version()->major,
		TTF_Linked_Version()->minor,
		TTF_Linked_Version()->patch
	);
}

void
InitSystem()
{
	/* Initialize SDL, SDL2_image and SDL2_ttf */
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		string errMsg("Error while initialize SDL2 subsystem: ");
		errMsg += SDL_GetError();
		throw runtime_error(errMsg);
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0) {
		string errMsg("Error while initialize SDL2_image: ");
		errMsg += IMG_GetError();
		throw runtime_error(errMsg);
	}

	if (TTF_Init() < 0) {
		string errMsg("Error while initialize SDL2_ttf: ");
		errMsg += TTF_GetError();
		throw runtime_error(errMsg);
	}

	/* Register user events */
	UserEvent::Init();
	SoundEngine::Init();

	/* Regist SDL as our log system */
	LogLocator::Init();
	LogLocator::Register(new SDLLog());

	/* Make game "pixelate" */
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

	srand(time(nullptr));

	PrintVersionInfo();
}

void
CleanUp()
{
	LogLocator::GetService()->LogDebug("Exit successes");

	delete (LogLocator::GetService());
	LogLocator::Register(nullptr);

	SDL_Quit();
	IMG_Quit();
	TTF_Quit();

	SoundEngine::Quit();
}

GameState*
ChangeState(GameState* state, enum GameStateList which)
{
	delete state;
	state = nullptr;

	switch (which) {
	case GAME_STATE_MAIN:
		break;
	case GAME_STATE_QUIT:
		break;
	default:
		LogLocator::GetService()->LogError("GameState trasform error");
		break;
	}

	return state;
}

int
main(int argc, char* argv[])
{
	Timer timer;
	SDL_Event event;

	bool appIsRunning = true;

	try {
		/* The creation of world... */
		InitSystem();

		Window mainWindow("BTW-test", 1280, 720);
		mainWindow.SetClearColor({0, 0, 0, 0});
		
		TestGameActor actor(mainWindow.GetRenderer());
		actor.setGravity(1);

		/* The cycle of life... */
		while (appIsRunning) {
			timer.Start();

			/* EventHandler */
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT)
					appIsRunning = false;

				actor.eventHandler(event);
			}

			/* Update */
			{
				actor.update();
			}

			/* Render */
			mainWindow.Clear();
			{
				actor.render();
			}
			mainWindow.Present();

			if (timer.GetTicks() < (1000 / GAME_FPS))
				SDL_Delay((1000 / GAME_FPS) -
					  timer.GetTicks());
		}
	} catch (runtime_error& e) {
		cerr << e.what() << endl;
	}

	CleanUp();

	return 0;
}
