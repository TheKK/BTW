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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "renderable.h"


using namespace std;

class Sprite : public Renderable
{
	public:
		Sprite();
		Sprite(string filePath, SDL_Renderer* renderer,
		       int w, int h,
		       Uint8 r = 0, Uint8 g = 255, Uint8 = 255);
		~Sprite();

		int Load(string filePath, SDL_Renderer* renderer,
			 int w, int h,
			 Uint8 r = 0, Uint8 g = 255, Uint8 = 255);

		void Render();
		void RenderFullWindow();

		void SetAlpha(Uint8 value);

		/* Frame control */
		void NextFrame();
		void PrevFrame();
		void JumpTo(Uint16 where);
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

		void Release_();
};

#endif	/* SPRITE_H */
