/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * File: button.h
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "renderable.h"
#include "texture.h"

using namespace std;

enum ButtonState {
	BUTTON_NORMAL = 0,
	BUTTON_HOVERED,
	BUTTON_PUSHED,
	BUTTON_STATE_NUM
};

class Button : public Renderable
{
	public:
		Button();
		Button(string normalPicPath, string hoverPicPath,
		       string pushPicPath, SDL_Renderer* renderer,
		       Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);
		~Button();

		void Load(string normalPicPath, string hoverPicPath,
		       string pushPicPath, SDL_Renderer* renderer,
		       Uint8 r = 0, Uint8 g = 255, Uint8 b = 255);

		void Render();

		void SetAlpha(uint8_t value);

		void ChangeState(enum ButtonState buttonState);
	private:
		SDL_Texture* pics_[BUTTON_STATE_NUM];

		enum ButtonState buttonState_ = BUTTON_NORMAL;

		void Release_();
};

#endif	/* BUTTON_H */
