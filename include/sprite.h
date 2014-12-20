/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: sprite.h
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <vector>
#include <SDL.h>

#include "renderable.h"

class Graphics;

enum FlipDirection
{
	FLIP_HORIZONTAL = 0x00,
	FLIP_VERTICAL,
	FLIP_NONE
};

class Sprite : public Renderable
{
public:
	Sprite();
	Sprite(const std::string& filePath, Graphics& graphics,
	       int w, int h,
	       Uint8 r = 0, Uint8 g = 255, Uint8 = 255);
	~Sprite();

	int load(const std::string& filePath, Graphics& graphics,
		 int w, int h,
		 Uint8 r = 0, Uint8 g = 255, Uint8 = 255);

	void render(Graphics& graphics, const SDL_Rect* rect);

	void setAlpha(Uint8 value);
	void setFlip(enum FlipDirection dir);

	/* Frame control */
	void nextFrame();
	void prevFrame();
	void jumpTo(Uint16 where);
private:
	SDL_Texture* sheet_ = nullptr;
	std::vector<SDL_Rect> clip_;

	int totalFrame_ = 0;
	int currentFrame_ = 0;

	SDL_RendererFlip flip_ = SDL_FLIP_NONE;

	void release_();
};

#endif	/* SPRITE_H */
