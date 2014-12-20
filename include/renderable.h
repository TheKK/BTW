/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: renderable.h
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SDL.h>
#include <SDL_image.h>

class Graphics;

class Renderable
{
public:
	virtual ~Renderable();

	virtual void render(Graphics& graphics, const SDL_Rect* rect) = 0;

	virtual void setAlpha(uint8_t value) = 0;
};

#endif	/* RENDERABLE_H */
