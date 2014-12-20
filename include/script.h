/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: script.h
 */

#ifndef SCRIPT_H
#define SCRIPT_H

#include <SDL.h>

class Graphics;

class Script
{
public:
	/*
	 * XXX I don't know if I should make GameState a member varialbe
	 * here?
	 */
	Script() {};
	virtual ~Script() {};

	virtual void eventHandler(const SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render(Graphics& graphics) = 0;
};

#endif /* SCRIPT_H */
