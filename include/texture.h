/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: texture.h
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "renderable.h"

class Graphics;

class Texture : public Renderable
{
public:
	Texture();
	Texture(const std::string&  filePath, Graphics& graphics,
		uint8_t r = 0, uint8_t g = 255, uint8_t b = 255);
	~Texture();

	void load(const std::string& filePath, Graphics& graphics,
		  uint8_t r = 0, uint8_t g = 255, uint8_t b = 255);

	void rotate(double value);

	void setAlpha(uint8_t value);

	void setBlendMode(SDL_BlendMode mode);

	void render(Graphics& graphics, const SDL_Rect* rect);
private:
	SDL_Texture* texture_ = nullptr;

	double degree_ = 0;
	uint8_t alpha_ = SDL_ALPHA_OPAQUE;
	SDL_RendererFlip flip_ = SDL_FLIP_NONE;

	void release_();
};

#endif	/* TEXTURE_H */
