/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: texture.h
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "renderable.h"

using namespace std;

class Texture : public Renderable
{
	public:
		Texture();
		Texture(string filePath, SDL_Renderer* renderer,
			Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
		~Texture();

		void Load(string filePath, SDL_Renderer* renderer,
				Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);

		void Rotate(double value);

		void SetAlpha(Uint8 value);
		SDL_Texture* Object() const;

		void SetBlendMode(SDL_BlendMode mode);

		void Render();
		void RenderFullWindow();
	private:
		SDL_Texture* texture_ = nullptr;

		double degree_ = 0;
		Uint8 alpha_ = SDL_ALPHA_OPAQUE;

		void Release_();
};

#endif	/* TEXTURE_H */
