/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: sprite.h
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "renderable.h"


using namespace std;

class Sprite : public Renderable
{
	public:
		Sprite();
		Sprite(const char* filePath, SDL_Renderer* renderer,
		       int w, int h,
		       Uint8 r = 0, Uint8 g = 255, Uint8 = 255);
		~Sprite();

		int load(const char* filePath, SDL_Renderer* renderer,
			 int w, int h,
			 Uint8 r = 0, Uint8 g = 255, Uint8 = 255);

		void render(const SDL_Rect& rect);

		void setAlpha(Uint8 value);

		/* Frame control */
		void nextFrame();
		void prevFrame();
		void jumpTo(Uint16 where);
	private:
		SDL_Texture* sheet_ = nullptr;
		vector<SDL_Rect> clip_;

		/*
		 * Use to store the number of frame
		 */
		int totalFrame_;

		/*
		 * Tell you which frame will show. Start from 0.
		 */
		int currentFrame_ = 0;

		void release_();
};

#endif	/* SPRITE_H */
